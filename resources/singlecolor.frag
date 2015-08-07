#version 130

out vec4 finalColor;

in vec3 fragVert;
in vec3 fragNormal;

void main()
{
	//set every drawn pixel to white
	finalColor = vec4(1.0, 1.0, 1.0, 0.0);
}