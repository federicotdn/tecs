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

#include "Shader.h"
#include <glm/gtc/type_ptr.hpp>
#include <stdexcept>

#pragma once

namespace tdogl
{

	//static std::string ResourcePath(std::string fileName);

	class Program
	{

	public:

		Program();
		~Program() { deleteProgram(); }

		void deleteProgram();

		bool addShader(std::string name, int type);
		bool linkProgram();

		GLint attrib(const GLchar *name) const;
		GLint uniform(const GLchar *name) const;

		bool isInUse() const;
		void use() const;
		void stopUsing() const;

		// Setters para los uniforms

		void setUniformMatrix4fv(std::string name, const glm::mat4 &mat);
		void setUniformMatrix3fv(std::string name, const glm::mat3 &mat);
		void setUniform1i(std::string name, GLint v0);
		void setUniform3f(std::string name, const glm::vec3 vec);
		void setUniform1f(std::string name, const float val);

	private:

		unsigned int uiProgram; //Contiene ID del objecto program
		bool bLinked;
		bool bReady;
		std::vector<Shader*> shaders;
	};

}
