#ifndef TECS_RENDERNODE
#define TECS_RENDERNODE

#include "../node.h"

#include "../components/GLMatrixComp.h"
#include "../components/GLDrawComp.h"

namespace ecs
{
	class RenderNode : public Node
	{
	public:
		RenderNode(const IDtype id) : Node{id} { }

		GLMatrixComp* GLmat;
		GLDrawComp* GLasset;

		static bool canBuildFromEntity(const Entity& ent)
		{
			return ent.hasComponent<GLMatrixComp>() && 
				ent.hasComponent<GLDrawComp>();
		}

		void buildFromEntity(const Entity& ent) override
		{
			GLmat = static_cast<GLMatrixComp*>(ent.getComponent<GLMatrixComp>());
			GLasset = static_cast<GLDrawComp*>(ent.getComponent<GLDrawComp>());
		}
	};
}

#endif
/* TECS_RENDERNODE */
