#ifndef TECS_ENGINE
#define TECS_ENGINE

#include "system.h"

namespace ecs
{
	class Engine
	{
		std::unique_ptr<EntityID> IDgen;
		std::unordered_map<IDtype, Entity*> entities;
		std::list<SystemBase*> systems;
		
	public:
		Engine();
		~Engine();

		IDtype createEntity();
		void destroyEntity(IDtype);

		int entityCount() const { return entities.size(); }
		void destroyAllEntities();

		void addSystem(SystemBase* sys);
		void update(const double gameTime);

		template<class T> void addComponent(IDtype ent, T* comp)
		{
			if (!entities.count(ent))
				return;

			Entity* temp = entities[ent];

			temp->addComponent(comp);

			for (auto it = systems.begin(); it != systems.end(); it++)
			{
				(*it)->offerEntity(*temp);
			}
		}

		template<class T> void removeComponent(IDtype ent)
		{
			if (!entities.count(ent))
				return;

			Entity* temp = entities[ent];

			Component* comp = temp->removeComponent<T>();

			for (auto it = systems.begin(); it != systems.end(); it++)
			{
				(*it)->refreshEntity(*temp);
			}

			delete comp;
		}

	};
}

#endif
/* TECS_ENGINE */
