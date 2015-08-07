#ifndef TECS_ENTITYID
#define TECS_ENTITYID

#include <stack>

namespace ecs
{
	using IDtype = long;

	class EntityID
	{
		//EntityID es un Singleton
		EntityID() {}
		EntityID(const EntityID&) = delete;
		EntityID(const EntityID&&) = delete;
		void operator=(const EntityID&) = delete;

		IDtype IDGen = 1;
		std::stack<IDtype> recycle;

	public:
		static EntityID* getInstance()
		{
			static EntityID* inst = new EntityID();
			return inst;
		}

		IDtype next()
		{
			IDtype id;

			if (!recycle.empty())
			{
				id = recycle.top();
				recycle.pop();
			}
			else
				id = IDGen++;

			return id;
		}

		void give(IDtype id)
		{
			recycle.push(id);
		}
	};
}

#endif
/* TECS_ENTITYID */