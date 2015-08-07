#include "rendersystem.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace ecs;

RenderSystem::RenderSystem(GLFWwindow *win, const int w, const int h) : width{w}, height{h}, window{win}
{
	camera.setAspectRatio((float)width / height);
    camera.setPosition(glm::vec3(10, 30, 10));
}

void RenderSystem::update(const double gameTime)
{
	updateCamera((float)gameTime);

	for (auto node : nodes)
	{
		GLMatrixComp *GLmat = node->GLmat;
		GLDrawComp *GLasset = node->GLasset;

		GLasset->asset->shaders->use();

        assert(GLasset->asset->shaders->isInUse());

		GLasset->asset->shaders->setUniformMatrix4fv("camera", camera.matrix());
		GLasset->asset->shaders->setUniformMatrix4fv("model", GLmat->matrix);

        if (GLasset->asset->hasNormals)
        {
            glm::mat3 modelNormal(GLmat->matrix);
            modelNormal = glm::inverse(modelNormal);
            modelNormal = glm::transpose(modelNormal);

            GLasset->asset->shaders->setUniform3f("position", lightpos);
            GLasset->asset->shaders->setUniform3f("intensities", lightcolor);
            GLasset->asset->shaders->setUniformMatrix3fv("normalMatrix", modelNormal);
        }

        if (GLasset->asset->texture != nullptr)
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, GLasset->asset->texture->object());

            GLasset->asset->shaders->setUniform1i("tex", 0);
        }

		glBindVertexArray(GLasset->asset->VAO);

		glDrawArrays(GLasset->asset->drawType, GLasset->asset->drawStart, GLasset->asset->drawCount);

		glBindVertexArray(0);

		GLasset->asset->shaders->stopUsing();
	}
}

void RenderSystem::updateCamera(const float secondsElapsed)
{
	//Mover la camara con WASD
    const float moveSpeed = 6.0; //Unidades por segundo

    if (glfwGetKey(window, 'S'))
    {
        camera.changePosition(secondsElapsed * moveSpeed * -camera.getForwardVector());
    } else if (glfwGetKey(window, 'W'))
    {
        camera.changePosition(secondsElapsed * moveSpeed * camera.getForwardVector());
    }

    if (glfwGetKey(window, 'A'))
    {
        camera.changePosition(secondsElapsed * moveSpeed * -camera.getRightVector());
    } else if (glfwGetKey(window, 'D'))
    {
        camera.changePosition(secondsElapsed * moveSpeed * camera.getRightVector());
    }

    if (glfwGetKey(window, 'Z'))
    {
        camera.changePosition(secondsElapsed * moveSpeed * -glm::vec3(0,1,0));
    } else if (glfwGetKey(window, 'X'))
    {
        camera.changePosition(secondsElapsed * moveSpeed * glm::vec3(0,1,0));
    }

    if (glfwGetKey(window, 'L'))
    {
        lightpos = camera.getPosition();
    }

    //Rotar la camara con el movimiento del mouse
    const float mouseSensitivity = 0.1;
    double mouseX, mouseY;

    glfwGetCursorPos(window, &mouseX, &mouseY);

    camera.changeOrientation(mouseSensitivity * mouseY, mouseSensitivity * mouseX);

    glfwSetCursorPos(window, 0, 0);
}