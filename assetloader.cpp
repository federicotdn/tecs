#include "assetloader.h"

#include <iostream>

using namespace ecs;

BTAsset* AssetLoader::loadBTGround()
{
	BTAsset *asset = new BTAsset{}; //leak

	btVector3 scale{1, 1, 1};

	btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
	btScalar mass{0};
	btVector3 inertia{0, 0, 0};

	asset->mass = mass;
	asset->fallInertia = inertia;
	asset->shape = groundShape;
	asset->scale = scale;

	return asset;
}

BTAsset* AssetLoader::loadBTCube()
{
	BTAsset *asset = new BTAsset{}; //leak

	btVector3 scale{3, 3, 3};

	btCollisionShape* cubeShape = new btBoxShape(scale);
	btScalar mass{10};
	btVector3 inertia{0, 10, 0};

	cubeShape->calculateLocalInertia(mass, inertia);

	asset->mass = mass;
	asset->fallInertia = inertia;
	asset->shape = cubeShape;
	asset->scale = scale;

	return asset;
}

GLAsset* AssetLoader::loadOBJ(std::string name)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;

	if(!loadOBJFile(name, vertices, normals) || vertices.size() != normals.size())
		throw std::runtime_error("No se pudo cargar OBJ:" + name + ". ");

	GLAsset *asset = new GLAsset{};

	tdogl::Program *shader = new tdogl::Program{};

	shader->addShader("resources/simpleshaded.vert", GL_VERTEX_SHADER);
	shader->addShader("resources/simpleshaded.frag", GL_FRAGMENT_SHADER);
	shader->linkProgram();

	GLuint VAO, VBOVertex, VBONormal;

	glGenBuffers(1, &VBOVertex);
	glGenBuffers(1, &VBONormal);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	//Cargar los vertices

	glBindBuffer(GL_ARRAY_BUFFER, VBOVertex);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(shader->attrib("vert"));
	glVertexAttribPointer(shader->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Cargar las normales

	glBindBuffer(GL_ARRAY_BUFFER, VBONormal);

	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(shader->attrib("vertNormal"));
	glVertexAttribPointer(shader->attrib("vertNormal"), 3, GL_FLOAT, GL_FALSE, 0, NULL);

	//Listo

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	asset->VAO = VAO;
	asset->shaders = shader;
	asset->drawType = GL_TRIANGLES;
	asset->drawStart = 0;
	asset->drawCount = vertices.size();
	asset->hasNormals = true;

	return asset;
}

GLAsset* AssetLoader::loadCube()
{
	GLAsset* asset = new GLAsset{}; //leak

	tdogl::Program *shader = new tdogl::Program{}; //leak

	shader->addShader("resources/textured.vert", GL_VERTEX_SHADER);
	shader->addShader("resources/textured.frag", GL_FRAGMENT_SHADER);
	shader->linkProgram();

	GLuint VBO; //leak

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	GLuint VAO; //leak

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 36 * 5, cubeVertexData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(shader->attrib("vert"));

	glVertexAttribPointer(shader->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), NULL);

	glEnableVertexAttribArray(shader->attrib("vertTexCoord"));

	glVertexAttribPointer(shader->attrib("vertTexCoord"), 2, GL_FLOAT, GL_TRUE, 5 * sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//Cargar la textura
	tdogl::Bitmap bmp = tdogl::Bitmap::bitmapFromFile("resources/wooden-crate.jpg");
	bmp.flipVertically();

	asset->texture = new tdogl::Texture{bmp};
	asset->shaders = shader;
	asset->VAO = VAO;
	asset->drawType = GL_TRIANGLES;
	asset->drawStart = 0;
	asset->drawCount = 36;

	return asset;
}