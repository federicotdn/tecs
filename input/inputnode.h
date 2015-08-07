#ifndef TECS_INPUTNODE
#define TECS_INPUTNODE

#include "../node.h"
#include "../components/InputComp.h"

namespace ecs
{
	class InputNode : public Node
	{
	public:
		InputNode(const IDtype id) : Node{id} {}
	
		InputComp *comp;
	
		static bool canBuildFromEntity(const Entity& ent)
		{
			return ent.hasComponent<InputComp>();
		}

		void buildFromEntity(const Entity& ent) override
		{
			comp = static_cast<InputComp*>(ent.getComponent<InputComp>());
		}
	};
}

#endif
/* TECS_INPUTNODE */
