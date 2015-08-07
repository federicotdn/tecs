#ifndef TECS_PHYSICSCOMP
#define TECS_PHYSICSCOMP

#include "../physics/BTAsset.h"

namespace ecs
{
	class PhysicsComp : public Component
	{
	public:
		btDefaultMotionState* mstate;
		btRigidBody* body;
		btVector3 scale;

		PhysicsComp(BTAsset *asset, btVector3 pos) : scale{asset->scale}
		{
			mstate = new btDefaultMotionState{btTransform(btQuaternion{0, 0, 0, 1}, pos)};

			btRigidBody::btRigidBodyConstructionInfo cInfo{asset->mass, mstate, asset->shape, asset->fallInertia};
			body = new btRigidBody{cInfo};
		}

		~PhysicsComp()
		{
			delete body;
			delete mstate;
		}
	};
}

#endif
/* TECS_PHYSICSCOMP */