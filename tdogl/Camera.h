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

#pragma once

#include <glm/glm.hpp>

namespace tdogl
{
	const float maxAngle = 85.0f;

	//La clase representa una camara en primera persona
	class Camera
	{
		glm::vec3 position;

		float horizontalAngle;
		float verticalAngle;
		float FOV;

		float nearPlane;
		float farPlane;
		float aspectRatio;

		public:
			Camera();

			const glm::vec3 getPosition() const;
			void setPosition(const glm::vec3& pos);
			void changePosition(const glm::vec3& pos);

			float getFOV() const;
			void setFOV(const float fov);

			float getNearPlane() const;
			float getFarPlane() const;
			void setNearAndFarPlane(const float near, const float far);

			glm::mat4 getOrientationMatrix() const;
			void changeOrientation(const float vertical, const float horizontal);

			float getAspectRatio() const;
			void setAspectRatio(const float ratio);

			glm::vec3 getUpVector() const;
			glm::vec3 getForwardVector() const;
			glm::vec3 getRightVector() const;

			glm::mat4 matrix() const;
	};
}