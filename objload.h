#ifndef TECS_OBJLOAD
#define TECS_OBJLOAD

#include <fstream>
#include <sstream>
#include <vector>
#include <glm/glm.hpp>

namespace ecs
{
	inline bool loadOBJFile(std::string name, std::vector<glm::vec3>& finalVertices, std::vector<glm::vec3>& finalNormals)
	{
		using std::ifstream;
		using std::istringstream;

		ifstream file(name);

		if (!file)
			return false;

		std::string buffer;

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;

		while (std::getline(file, buffer))
		{
			if (buffer.front() == '#' || buffer.empty())
				continue;

			istringstream line(buffer);
			std::string type;

			line >> type;

			if (type == "v")
			{
				float x, y, z;

				line >> x >> y >> z;

				vertices.emplace_back(x, y, z);
			}
			else if (type == "f")
			{
				std::string s[3];
				int i[3], j = 0;

				line >> s[0] >> s[1] >> s[2];

				for (std::string point : s)
				{
					istringstream info(point);
					info >> i[j++];
				}

				glm::vec3 points[3];

				for (j = 0; j < 3; j++)
				{
					points[j] = vertices[i[j] - 1];
					finalVertices.push_back(points[j]);
				}

				glm::vec3 normal = glm::cross(points[1] - points[0], points[2] - points[0]);

				for (j = 0; j < 3; j++)
					finalNormals.push_back(normal);
			}

		}

		return true;
	}
}

#endif