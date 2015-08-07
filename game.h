#ifndef TECS_GAME
#define TECS_GAME

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "assetloader.h"
#include "engine.h"

#include <iostream> //remove

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define WINDOW_NAME "TECS"

/*
 * La clase abstracta ecs::Game representa un juego con sus metodos mas basicos:
 * initialize, update y end.  El metodo begin crea el contexto OpenGL
 * y crea el game-loop, donde se llama a update en cada iteracion.  Para
 * crear un juego solo hay que implementar Game y definir los tres metodos
 * mencionados.
 *
 * ecs::Game incluye una instancia de ecs::Engine.
*/

namespace ecs
{
	class Game
	{
		double lastTime = 0;
		double thisTime = 0;

	protected:
		Engine engine;
		AssetLoader loader;
		GLFWwindow *window;

		const int screenWidth = SCREEN_WIDTH;
		const int screenHeight = SCREEN_HEIGHT;

	public:
		Game();
		virtual ~Game() { }

		void begin();
		void checkErrors();

		virtual void initialize() = 0;
		virtual void update(const double gameTime) = 0;
		virtual void end() = 0;
	};
}

#endif
/* TECS_GAME */
