#ifndef TECS_NODE
#define TECS_NODE

#include "entity.h"

namespace ecs
{
	class Node
	{
		const IDtype EntityID;
	public:
		Node(const IDtype id) : EntityID{id} { }
		virtual ~Node() { }

		IDtype getID() const { return EntityID; }
		virtual void buildFromEntity(const Entity& ent) = 0;
	};
}

#endif
/* TECS_NODE */
