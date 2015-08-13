#ifndef TECS_ENTITY
#define TECS_ENTITY

#include <unordered_map>
#include <typeinfo>
#include <memory>

#include "component.h"
#include "entityid.h"

namespace ecs
{
	class Entity
	{
		friend class Engine;

		const IDtype ID;
		mutable std::unordered_map<const std::type_info*, std::unique_ptr<Component>> components;

		explicit Entity(const IDtype id) : ID{id} {}

	public:

		IDtype getID() const { return ID; }

		template<class T> bool hasComponent() const
		{
			return components.count(&typeid(T)); //usar at() y sacar mutable
		}

		template<class T> Component* getComponent() const
		{
			Component* aux = (components[&typeid(T)]).get();
			return aux;
		}

		template<class T> void addComponent(T* comp)
		{
			components.erase(&typeid(T));
			components[&typeid(T)] = std::unique_ptr<Component>{comp};
		}

		template<class T> Component* removeComponent()
		{
			Component *comp = (components[&typeid(T)]).release();
			components.erase(&typeid(T));
			return comp;
		}
	};
}

#endif
/* TECS_ENTITY */
