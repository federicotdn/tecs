#ifndef TECS_INPUTSYSTEM
#define TECS_INPUTSYSTEM

#include "inputnode.h"
#include "../system.h"

struct GLFWwindow;

namespace ecs
{
	class Engine;
	
	class InputSystem : public System<InputNode>
	{
		GLFWwindow *win;
		Engine &engine;
		
	public:
		InputSystem(GLFWwindow* w, Engine& eng);
		
		void update(const double gameTime) override;
	};
}

#endif
/* TECS_INPUTSYSTEM */
