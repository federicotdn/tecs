#version 130

smooth in vec4 position;
out vec4 outputColor;

void main()
{
	outputColor = vec4(position.x / 2, position.y / 20, position.z / 2, 1);
}