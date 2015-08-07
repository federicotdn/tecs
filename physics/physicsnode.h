#ifndef TECS_PHYSICSNODE
#define TECS_PHYSICSNODE

#include "../node.h"
#include "../components/GLMatrixComp.h"
#include "../components/PhysicsComp.h"

namespace ecs
{
	class PhysicsNode : public Node
	{
	public:
		PhysicsNode(const IDtype id) : Node{id} {}

		GLMatrixComp *GLmat;
		PhysicsComp *BTcomp;

		static bool canBuildFromEntity(const Entity& ent)
		{
			return ent.hasComponent<GLMatrixComp>() &&
				ent.hasComponent<PhysicsComp>();
		}

		void buildFromEntity(const Entity& ent) override
		{
			GLmat = static_cast<GLMatrixComp*>(ent.getComponent<GLMatrixComp>());
			BTcomp = static_cast<PhysicsComp*>(ent.getComponent<PhysicsComp>());
		}
	};
}

#endif
/* TECS_PHYSICSNODE */
