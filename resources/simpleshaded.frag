#version 130

uniform mat4 model;
uniform mat3 normalMatrix;
uniform vec3 position;
uniform	vec3 intensities;

in vec3 fragVert;
in vec3 fragNormal;

out vec4 finalColor;

void main()
{
	vec3 normal = normalize(normalMatrix * fragNormal);

	vec3 fragPosition = vec3(model * vec4(fragVert, 1));

	vec3 surfaceToLight = position - fragPosition;

	float len = length(surfaceToLight);
	float brightness = dot(normal, surfaceToLight) / (len);
	brightness = clamp(brightness, 0, 1);

	finalColor = brightness * vec4(intensities, 1);
}