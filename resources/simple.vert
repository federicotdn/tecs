#version 130

uniform mat4 camera;
uniform mat4 model;

in vec3 vert;
smooth out vec4 position;


void main() 
{    
	vec4 finalpos = model * vec4(vert, 1);
	gl_Position = camera * finalpos;
	position = finalpos;
}