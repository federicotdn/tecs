/*
 tdogl::Program

 Copyright 2012 Thomas Dalling - http://tomdalling.com/

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

/*
 Slightly modified version of tdogl::Program
 */

#include "Program.h"

using namespace tdogl;

Program::Program()
{
	bLinked = false;

	uiProgram = glCreateProgram();

	bReady = !(uiProgram == 0);
}


void Program::deleteProgram()
{
	if (!bLinked || !bReady)
		return;

	bLinked = false;

	for (unsigned i = 0; i < shaders.size(); i++)
	{
		delete shaders[i];
	}

	glDeleteProgram(uiProgram);
}


bool Program::addShader(std::string name, int type)
{
	if (bLinked || !bReady)
		return false;

	Shader *shader = new Shader(type);

	if (!shader->loadShader(name))
	{
		delete shader;
		return false;
	}

	glAttachShader(uiProgram, shader->getShaderID());
	shaders.push_back(shader);

	return true;
}

bool Program::linkProgram()
{
	if (!bReady)
		return false;

	glLinkProgram(uiProgram);

	int linkStatus;

	glGetProgramiv(uiProgram, GL_LINK_STATUS, &linkStatus);

	bLinked = (linkStatus == GL_TRUE);

	if (!bLinked)
		throw std::runtime_error("Shaders no se pudieron linkear.");

	return bLinked;
}

GLint Program::attrib(const GLchar *name) const
{
	if (!name)
		throw std::runtime_error("Nombre nulo para shader attribute");

	GLint location = glGetAttribLocation(uiProgram, name);

	if (location == -1)
		throw std::runtime_error(std::string("No se pudo encontrar el atributo: ") + name);

	return location;
}

GLint Program::uniform(const GLchar *name) const
{
	if (!name)
		throw std::runtime_error("Nombre nulo para shader uniform");

	GLint location = glGetUniformLocation(uiProgram, name);

	if (location == -1)
		throw std::runtime_error(std::string("No se pudo encontrar el uniform: ") + name);

	return location;
}

void Program::use() const
{
	if (bLinked && bReady)
		glUseProgram(uiProgram);
}

void Program::stopUsing() const
{
	if (!bLinked || !isInUse())
		return;
	glUseProgram(0);
}

bool Program::isInUse() const
{
	if (!bLinked)
		return false;

	GLint currentProgram = 0;
	glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);

	return (currentProgram == (GLint)uiProgram);
}

void Program::setUniformMatrix4fv(std::string name, const glm::mat4 &mat)
{
	glUniformMatrix4fv(uniform(name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Program::setUniform1i(std::string name, GLint v0)
{
	glUniform1i(uniform(name.c_str()), v0);
}

void Program::setUniform3f(std::string name, const glm::vec3 vec)
{
	glUniform3f(uniform(name.c_str()), vec.x, vec.y, vec.z);
}

void Program::setUniform1f(std::string name, const float val)
{
	glUniform1f(uniform(name.c_str()), val);
}

void Program::setUniformMatrix3fv(std::string name, const glm::mat3 &mat)
{
	glUniformMatrix3fv(uniform(name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}