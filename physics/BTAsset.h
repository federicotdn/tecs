#ifndef TECS_BTASSET
#define TECS_BTASSET

#include <btBulletDynamicsCommon.h>

namespace ecs
{
	struct BTAsset
	{
		btScalar mass;
		btVector3 fallInertia;
		btVector3 scale;
		btCollisionShape *shape{nullptr};

		~BTAsset()
		{
			delete shape;
		}
	};
}

#endif
/* TECS_BTASSET */