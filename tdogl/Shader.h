/*
 tdogl::Shader

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
 Slightly modified version of tdogl::Shader
 */

#include <string>
#include <vector>
#include <GL/glew.h>
#include <stdexcept>
#include <stdio.h>
#include <fstream>

#pragma once

namespace tdogl
{

	class Shader
	{
	public:

		Shader(int type) { bLoaded = false; iType = type; }
		~Shader() { deleteShader(); }

		bool loadShader(std::string name);
		void deleteShader();

		bool isLoaded() { return bLoaded; }
		unsigned int getShaderID() { return uiShader; }

	private:

		unsigned int uiShader;
		int iType;
		bool bLoaded;
	};

}
