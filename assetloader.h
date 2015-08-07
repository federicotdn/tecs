#ifndef TECS_ASSETLOADER
#define TECS_ASSETLOADER

#include "render/GLAsset.h"
#include "physics/BTAsset.h"
#include "resources/vertex.h"
#include "objload.h"

namespace ecs
{
	class AssetLoader
	{
	public:
		GLAsset* loadCube();
		GLAsset* loadOBJ(std::string name);

		BTAsset* loadBTGround();
		BTAsset* loadBTCube();
	};
}

#endif
/* TECS_ASSETLOADER */