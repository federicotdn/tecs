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

#include "Shader.h"

using namespace tdogl;

bool Shader::loadShader(std::string name)
{
	//Leer el archivo con el codigo GLSL

	FILE *f = fopen(name.c_str(), "rt");

	if (f == NULL)
	{
		throw std::runtime_error("No se pudo abrir el archivo: " + name);
		return false;
	}

	std::vector<std::string> lines;
	char line[255];

	while (fgets(line, 255, f))
		lines.push_back(line);

	fclose(f);

	//Convertir a array de arrays de chars (puntero a puntero de char)

	const char **codigo = new const char*[(int)lines.size()];

	for (int i = 0; i < (int)lines.size(); i++)
		codigo[i] = lines[i].c_str();

	uiShader = glCreateShader(iType);

	//Compilar el shader

	glShaderSource(uiShader, (int)lines.size(), codigo, NULL);
	glCompileShader(uiShader);

	delete[] codigo;

	int compilationStatus;
	glGetShaderiv(uiShader, GL_COMPILE_STATUS, &compilationStatus);

	if (compilationStatus == GL_FALSE)
	{
		std::ofstream file("log.txt");

		if (file)
		{
			GLint maxLength = 0;
			glGetShaderiv(uiShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(uiShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(uiShader);

			for (char ch : infoLog)
				if (ch != '\0')
					file << ch;
		}

		throw std::runtime_error("No se pudo cargar shader: " + name);

		return false;
	}

	return bLoaded = true;
}

void Shader::deleteShader()
{
	if (!isLoaded())
		return;

	bLoaded = false;
	glDeleteShader(uiShader);
}