#include "systembase.h"

using namespace ecs;

void SystemBase::updateBase(const double gameTime)
{
	if (active)
	{
		update(gameTime);
	}
}

void SystemBase::setActive(bool ac)
{
	active = ac;
}

bool SystemBase::isActive()
{
	return active;
}