#ifndef TECS_RENDERSYSTEM
#define TECS_RENDERSYSTEM

#include "rendernode.h"
#include "../system.h"
#include "../tdogl/Camera.h"

struct GLFWwindow;

namespace ecs
{
	class RenderSystem : public System<RenderNode>
	{
		glm::vec3 lightpos{10, 0, 10};
    	glm::vec3 lightcolor{1, 1, 1};

		const int width;
		const int height;

		GLFWwindow *window;

		void updateCamera(const float secondsElapsed);

	public:
		tdogl::Camera camera{}; //hacer privado

		RenderSystem(GLFWwindow *win, const int w, const int h);
		void update(const double gameTime) override;
	};
}

#endif
/* TECS_RENDERSYSTEM */