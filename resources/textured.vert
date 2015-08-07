#version 130

uniform mat4 camera;
uniform mat4 model;

in vec4 vert;
in vec2 vertTexCoord;

out vec2 textureCoord;


void main() 
{    
	textureCoord = vertTexCoord;
	gl_Position = camera * model * vert;
}