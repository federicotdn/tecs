#ifndef TECS_SYSTEM
#define TECS_SYSTEM

#include <list>
#include <unordered_set>

#include "systembase.h"

namespace ecs
{
	template<class T> class System : public SystemBase
	{
		std::unordered_set<IDtype> entities;

		static_assert(std::is_base_of<Node, T>(), "T must be a subclass of ecs::Node.");

		void updateEntity(Entity& ent, bool forceRemove)
		{
			IDtype id = ent.getID();

			if (!entities.count(id))
				return;

			if (forceRemove || !T::canBuildFromEntity(ent))
			{
				auto it = nodes.begin();

				for (; it != nodes.end(); it++)
					if ((*it)->getID() == id)
					{
						deregisterNode(**it);
						delete *it;
						break;
					}

				nodes.erase(it);
				entities.erase(id);
			}
		}

		virtual void registerNode(T& node) { }
		virtual void deregisterNode(T& node) { }

	protected:
		std::list<T*> nodes;

	public:
		virtual ~System()
		{
			for (T* node : nodes)
			{
				deregisterNode(*node);
				delete node;
			}
		}

		void offerEntity(Entity& ent)
		{
			IDtype id = ent.getID();

			if (entities.count(id))
				return;

			if (T::canBuildFromEntity(ent))
			{
				T *node = new T{id};

				node->buildFromEntity(ent);

				nodes.push_front(node);

				entities.insert(id);

				registerNode(*node);
			}
		}

		void refreshEntity(Entity& ent)
		{
			updateEntity(ent, false);
		}

		void removeEntity(Entity& ent)
		{
			updateEntity(ent, true);
		}
	};
}

#endif
/* TECS_SYSTEM */
