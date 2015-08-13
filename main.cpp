#include <iostream>

#include "game.h"
#include "render/rendersystem.h"
#include "physics/physicssystem.h"
#include "input/inputsystem.h"

#include <cstdlib>

class TestGame : public ecs::Game
{
	using Entity = ecs::IDtype;

	ecs::PhysicsSystem* ps;
	ecs::RenderSystem* rs;
	ecs::InputSystem* is;

	ecs::GLAsset *obj;
	ecs::GLAsset *obj2;
	ecs::BTAsset *cube;

	std::vector<Entity> ents;
	std::vector<Entity> projectiles;

public:
	void initialize() override
	{
		ps = new ecs::PhysicsSystem{};
		rs = new ecs::RenderSystem{window, screenWidth, screenHeight};
		is = new ecs::InputSystem{window, engine};

		engine.addSystem(ps);
		engine.addSystem(rs);
		engine.addSystem(is);

		//ecs::GLAsset *data = loader.loadCube();
		ecs::BTAsset *floor = loader.loadBTGround();
		cube = loader.loadBTCube();
		ecs::GLAsset *floorasset = loader.loadCube();

		obj = loader.loadOBJ("resources/cube.obj");
		obj2 = loader.loadOBJ("resources/vaso.obj");

		Entity fl = engine.createEntity();

		ecs::GLMatrixComp *matfl = new ecs::GLMatrixComp{};
		ecs::GLDrawComp *floorcomp = new ecs::GLDrawComp{};
		floorcomp->asset = floorasset;
		ecs::PhysicsComp *phyfl = new ecs::PhysicsComp{floor, {0, 0, 0}};

		engine.addComponent(fl, matfl);
		engine.addComponent(fl, phyfl);
		engine.addComponent(fl, floorcomp);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Entity ent = engine.createEntity();

				ents.push_back(ent);

				ecs::GLMatrixComp *mat = new ecs::GLMatrixComp{};

				ecs::GLDrawComp *asset = new ecs::GLDrawComp{};
				asset->asset = obj;

				ecs::PhysicsComp *phy = new ecs::PhysicsComp{cube, {0, i * 7, j * 7}};

				engine.addComponent(ent, mat);
				engine.addComponent(ent, asset);
				engine.addComponent(ent, phy);
			}
		}

		std::cout << "Initialization complete.  Entity count: " << engine.entityCount() << std::endl;
	}

	void update(const double gameTime) override
	{
		static double time = 0;

		time += gameTime;

		if (glfwGetKey(window, 'E') && time > 0.1)
		{
			time = 0;
			glm::vec3 direction = rs->camera.getForwardVector();
			glm::vec3 position = rs->camera.getPosition();

			Entity ent = engine.createEntity();

			ecs::GLMatrixComp *mat = new ecs::GLMatrixComp{};

			ecs::GLDrawComp *asset = new ecs::GLDrawComp{};
			asset->asset = obj2;

			ecs::PhysicsComp *phy = new ecs::PhysicsComp{cube, {position.x, position.y, position.z}};

			engine.addComponent(ent, mat);
			engine.addComponent(ent, asset);
			engine.addComponent(ent, phy);

			btVector3 vec{direction.x, direction.y, direction.z};
			phy->body->setLinearVelocity(vec * 200);

			projectiles.push_back(ent);
		}
		else if (glfwGetKey(window, 'R') && time > 0.5)
		{
			time = 0;
			for (auto en : ents)
			{
				engine.destroyEntity(en);
			}

			ents.clear();

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					Entity ent = engine.createEntity();

					ents.push_back(ent);

					ecs::GLMatrixComp *mat = new ecs::GLMatrixComp{};

					ecs::GLDrawComp *asset = new ecs::GLDrawComp{};
					asset->asset = obj;

					ecs::PhysicsComp *phy = new ecs::PhysicsComp{cube, {0, i * 7, j * 7}};

					engine.addComponent(ent, mat);
					engine.addComponent(ent, asset);
					engine.addComponent(ent, phy);
				}
			}
		}
		else if (glfwGetKey(window, 'T') && time > 0.5)
		{
			time = 0;

			for (auto en : projectiles)
			{
				engine.destroyEntity(en);
			}

			projectiles.clear();
		}
		else if (glfwGetKey(window, 'F') && time > 0.5)
		{
			time = 0;

			ps->setActive(!ps->isActive());
		}

		engine.update(gameTime);
	}

	void end() override
	{
		std::cout << "Exit end function." << std::endl;
	}
};

int main()
{
	TestGame game;

	try
	{
		game.begin();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
