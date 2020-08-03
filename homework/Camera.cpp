#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup) {
	Position = position;
	Worldup = worldup;
	Forward = glm::normalize(target - position);
	Right = glm::normalize(glm::cross(Forward, Worldup));
	Up = glm::normalize(glm::cross(Forward, Right));
}

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup) {
	Position = position;
	Worldup = worldup;
	Pitch = pitch;
	Yaw = yaw;
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, Worldup));
	Up = glm::normalize(glm::cross(Forward, Right));
}

Camera::~Camera() {

}

glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(Position, Position + Forward, Worldup);
}

void Camera::UpdataCameraVectors() {
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, Worldup));
	Up = glm::normalize(glm::cross(Forward, Right));
}

void Camera::ProcessMouseMovement(float deltaX, float deltaY) {
	Pitch -= deltaY * 0.001f;
	Yaw -= deltaX * 0.001f;
	UpdataCameraVectors();
}
