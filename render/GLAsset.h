#ifndef TECS_GLASSET
#define TECS_GLASSET

#include "../tdogl/Program.h"
#include "../tdogl/Texture.h"

namespace ecs
{
	struct GLAsset
	{
		tdogl::Program *shaders{nullptr};
		tdogl::Texture *texture{nullptr};
		GLuint VAO;
		GLenum drawType;
		GLint drawStart;
		GLint drawCount;
		bool hasNormals{false};
	};
}

#endif