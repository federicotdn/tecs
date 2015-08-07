#include "game.h"

using namespace ecs;

Game::Game()
{
}

void Game::begin()
{
	if (!glfwInit())
		throw std::runtime_error("Error: No se pudo inicializar GLFW.");

    glfwWindowHint(GLFW_RESIZABLE, false);

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME, NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Error: no se pudo crear ventana GLFW.");
    }

    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(window, 0, 0);

	if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
		throw std::runtime_error("Error: No se pudo inicializar GLEW.");
    }

	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    initialize();

    lastTime = glfwGetTime();

    std::cout << "Entrando a loop principal..." << std::endl;

    bool shouldClose = false;

    while (!glfwWindowShouldClose(window) && !shouldClose)
    {
        thisTime = glfwGetTime();

        glClearColor(0.0, 0.0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        update(thisTime - lastTime);

        lastTime = thisTime;

        glfwSwapBuffers(window);

        if (glfwGetKey(window, GLFW_KEY_ESCAPE))
            shouldClose = true;

        checkErrors();

        glfwPollEvents();
    }

    std::cout << "Saliendo de loop principal..." << std::endl;

    end();

    glfwTerminate();
}

void Game::checkErrors()
{
	GLenum error = glGetError();
    if(error != GL_NO_ERROR)
		std::cerr << "OpenGL Error " << error << ": " << (const char*)gluErrorString(error) << std::endl;
}
