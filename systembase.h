#ifndef TECS_SYSTEMBASE
#define TECS_SYSTEMBASE

#include "node.h"

namespace ecs
{
	class SystemBase
	{
	public:
		virtual ~SystemBase() {}

		virtual void offerEntity(Entity& ent) = 0;
		virtual void refreshEntity(Entity& ent) = 0;
		virtual void removeEntity(Entity& ent) = 0;

		virtual void update(const double gameTime) = 0;
	};
}

#endif
/* TECS_SYSTEMBASE */