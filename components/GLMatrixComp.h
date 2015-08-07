#ifndef TECS_GLMATRIXCOMP
#define TECS_GLMATRIXCOMP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ecs
{
	class GLMatrixComp : public Component
	{
	public:
		glm::mat4 matrix{};

		void scale(const float x, const float y, const float z)
		{
			matrix = glm::scale(matrix, glm::vec3{x, y, z});
		}
	};
}

#endif
/* TECS_GLMATRIXCOMP */