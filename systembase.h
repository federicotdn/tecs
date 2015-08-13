#ifndef TECS_SYSTEMBASE
#define TECS_SYSTEMBASE

#include "node.h"

namespace ecs
{
	class SystemBase
	{
	private:
		bool active = true;

	public:
		virtual ~SystemBase() {}

		virtual void offerEntity(Entity& ent) = 0;
		virtual void refreshEntity(Entity& ent) = 0;
		virtual void removeEntity(Entity& ent) = 0;
		virtual void update(const double gameTime) = 0;

		void updateBase(const double gameTime);

		void setActive(bool act);
		bool isActive();
	};
}

#endif
/* TECS_SYSTEMBASE */