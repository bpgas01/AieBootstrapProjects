#include "Camera.h"
#include <glm/ext.hpp>
#include <Input.h>
Camera::Camera()
{
	m_position = glm::vec3(0, 2, -10);
	m_phi = 0;
	m_theta = 0;
}

void Camera::Update(float a_deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	float thetaR = glm::radians(m_theta);
	float phiR = glm::radians(m_phi);

	// Calculate the forwards and up axis for the camera
	glm::vec3 forward(glm::cos(phiR) * glm::cos(thetaR), glm::sin(phiR), glm::cos(phiR) * glm::sin(thetaR));
	glm::vec3 right(-glm::sin(thetaR), 0, glm::cos(thetaR));
	glm::vec3 up(0, 1, 0);


	// Input Settings
	if (input->isKeyDown(aie::INPUT_KEY_X)) m_position += up * a_deltaTime * 3.f;
	
	if (input->isKeyDown(aie::INPUT_KEY_Z)) m_position -= up * a_deltaTime * 3.f;
	
	if (input->isKeyDown(aie::INPUT_KEY_A)) m_position -= right * a_deltaTime * 3.f;

	if (input->isKeyDown(aie::INPUT_KEY_D)) m_position += right * a_deltaTime * 3.f;
	
	if (input->isKeyDown(aie::INPUT_KEY_W)) m_position += forward * a_deltaTime * 3.f;
	
	if (input->isKeyDown(aie::INPUT_KEY_S)) m_position -= forward * a_deltaTime * 3.f;
	
	// -----
	// Get current position of mouse coordiniates
	float mX = input->getMouseX();
	float mY = input->getMouseY();
	const float turnSpeed = glm::radians(180.f);

	// IF the right button is down, increment theta and phi
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_RIGHT))
	{
		m_theta += turnSpeed * (mX - lastMouseX) * a_deltaTime * 3;
		m_phi += turnSpeed * (mY - lastMouseY) * a_deltaTime * 3;
	}

	// Now store the last values
	lastMouseX = mX;
	lastMouseY = mY;

}

glm::mat4 Camera::GetViewMatrix()
{
	float thetaR = glm::radians(m_theta);
	float phiR = glm::radians(m_phi);
	glm::vec3 forward(glm::cos(phiR) * glm::cos(thetaR), glm::sin(phiR), glm::cos(phiR) * glm::sin(thetaR));


	return glm::lookAt(m_position, m_position+forward, glm::vec3(0,1,0));
}

glm::mat4 Camera::GetProjectionMatrix(float width, float height)
{
	return glm::perspective(glm::pi<float>() * 0.25f,
		width / height , 0.1f, 1000.0f);
}
