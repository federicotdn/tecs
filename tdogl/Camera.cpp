/*
 tdogl::Camera

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
 Slightly modified version of tdogl::Camera
 */

#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace tdogl;

//Crea una camara con valores default
Camera::Camera() : position(0.0f, 0.0f, 1.0f), horizontalAngle(0.0f), verticalAngle(0.0f), FOV(50.0f),
					nearPlane(0.01f), farPlane(100.0f), aspectRatio(4.0f / 3.0f)
{ }

//Devuelve la posicion de la camara
const glm::vec3 Camera::getPosition() const { return position; }

//Setea la posicion 3D de la camara
void Camera::setPosition(const glm::vec3& pos)
{
	position = pos;
}

//Cambia la posicion de la camara en +pos
void Camera::changePosition(const glm::vec3& pos)
{
	position += pos;
}

//Devuelve el field of view de la camara
float Camera::getFOV() const { return FOV; }

//Setea el FOV de la camara
void Camera::setFOV(const float fov)
{
	if (fov > 0.0f && fov < 180.0f)
		FOV = fov;
}

//Devuelven los limites de plano cercano/lejano de la camara
float Camera::getNearPlane() const { return nearPlane; }
float Camera::getFarPlane() const { return farPlane; }

//Setea los dos planos de vision de la camara
void Camera::setNearAndFarPlane(const float near, const float far)
{
	if (nearPlane > 0.0f && nearPlane < farPlane)
	{
		nearPlane = near;
		farPlane = far;
	}
}

//La camara esta orientada de la siguiente manera:
// Y es "arriba"
// -Z es "adelante" (looking down the Z axis)
// X es "derecha"
// Devuelve una matriz que representa la rotacion que se aplica a un vertice para que
// aparezca bien posicionado en la pantalla (ejemplo: si muevo la camara para abajo,
// los vertices se tienen que dibujar mas "arriba").  La matriz representa el angulo en
// (distancia) que habria que desplazar un vertice para que aparezca bien dibujado
glm::mat4 Camera::getOrientationMatrix() const
{
	glm::mat4 orientation;
	orientation = glm::rotate(orientation, verticalAngle, glm::vec3(1.0f, 0.0f, 0.0f));
	orientation = glm::rotate(orientation, horizontalAngle, glm::vec3(0.0f, 1.0f, 0.0f));
	return orientation;
}

//Cambia la orientacion vertical y horizontal de la camara, checkeando que los valores
//sean validos para evitar gimbal lock
void Camera::changeOrientation(const float vertical, const float horizontal)
{
	horizontalAngle += horizontal;

	while (horizontalAngle > 360.0f)
		horizontalAngle -= 360.0f;
	while (horizontalAngle < 0.0f)
		horizontalAngle += 360.0f;

	verticalAngle += vertical;

	if (verticalAngle > maxAngle)
		verticalAngle = maxAngle;
	if (verticalAngle < -maxAngle)
		verticalAngle = -maxAngle;
}

//Devuelve el aspect ratio
float Camera::getAspectRatio() const { return aspectRatio; }

//Setter para el aspect ratio
void Camera::setAspectRatio(const float ratio)
{
	if (ratio > 0.0f)
		aspectRatio = ratio;
}

/** Las tres funciones siguientes devuelven vectores normalizados que representan las
	direcciones con respecto a la orientacion de la camara (no importa la posicion)
	Para lograr esto se calcula la inversa de la matriz de orientacion (lo cual nos da una matriz
	de orientacion inversa).  Esta matriz nueva se multiplica por una de las direcciones iniciales de la camara
	correspondiente.
 **/
glm::vec3 Camera::getUpVector() const
{
	glm::vec4 up = glm::inverse(getOrientationMatrix()) * glm::vec4(0.0f, 0.1f, 0.0f, 1.0f);
	return glm::vec3(up);
}

glm::vec3 Camera::getForwardVector() const
{
	glm::vec4 forward = glm::inverse(getOrientationMatrix()) * glm::vec4(0.0f, 0.0f, -1.0f, 1.0f);
	return glm::vec3(forward);
}

glm::vec3 Camera::getRightVector() const
{
	glm::vec4 right = glm::inverse(getOrientationMatrix()) * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	return glm::vec3(right);
}

//Devuelva la matriz correspondiente a la camara para ser aplicado a un shader
//Utiliza todas las propiedades de la camara (orientacion, posicion, fov, etc.)
glm::mat4 Camera::matrix() const
{
	glm::mat4 mat = glm::perspective(FOV, aspectRatio, nearPlane, farPlane);
	mat *= getOrientationMatrix();
	mat = glm::translate(mat, -position);
	return mat;
}