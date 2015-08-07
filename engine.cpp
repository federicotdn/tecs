#include "engine.h"

using namespace ecs;

Engine::Engine() : IDgen{EntityID::getInstance()}
{

}

Engine::~Engine()
{
	for (SystemBase* sys : systems)
		delete sys;

	for (auto it = entities.begin(); it != entities.end(); it++)
		delete it->second;
}

void Engine::update(const double gameTime)
{
	for (auto it = systems.begin(); it != systems.end(); it++)
		(*it)->update(gameTime);
}

IDtype Engine::createEntity()
{
	IDtype id = IDgen->next();

	Entity* ent = new Entity{id};

	entities[id] = ent;

	return id;
}

void Engine::destroyEntity(IDtype id)
{
	if (!entities.count(id))
		return;

	Entity* aux = entities[id];

	entities.erase(id);

	for (auto it = systems.begin(); it != systems.end(); it++)
	{
		(*it)->removeEntity(*aux);
	}

	IDgen->give(id);

	delete aux;
}

void Engine::destroyAllEntities()
{
	//TODO: implement
}

void Engine::addSystem(SystemBase* sys)
{
	systems.push_back(sys);
}
