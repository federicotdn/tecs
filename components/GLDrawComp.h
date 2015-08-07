#ifndef TECS_DRAWCOMP
#define TECS_DRAWCOMP

#include "../render/GLAsset.h"

namespace ecs
{
	class GLDrawComp : public Component
	{
	public:
		GLAsset *asset;
	};
}

#endif
/* TECS_DRAWCOMP */