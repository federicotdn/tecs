#ifndef TECS_PHYSICSSYSTEM
#define TECS_PHYSICSSYSTEM

#include "../system.h"
#include "physicsnode.h"
#include <glm/gtc/type_ptr.hpp>

namespace ecs
{
	class PhysicsSystem : public System<PhysicsNode>
	{
		btBroadphaseInterface* broadphase;
		btDefaultCollisionConfiguration* collisionConfiguration;
		btCollisionDispatcher* dispatcher;
		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* dynamicsWorld;

	public:
		PhysicsSystem();
		~PhysicsSystem();

		void update(const double gameTime) override;

		void registerNode(PhysicsNode& node) override;
		void deregisterNode(PhysicsNode& node) override;
		
	};
}

#endif
/* TECS_PHYSICSSYSTEM */