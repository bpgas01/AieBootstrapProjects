#include "Instance.h"

#include "Scene.h"
#include "OBJMesh.h"
#include "Camera.h"
#include "Mesh.h"
#include "Shader.h"

#include <Texture.h>
#include <Application.h>
#include <glm/ext.hpp>

Instance::Instance(glm::mat4 a_transform, aie::OBJMesh* a_mesh, aie::ShaderProgram* a_shader)
	: m_transform(a_transform), m_mesh(a_mesh), m_shader(a_shader)

{
	
}

Instance::Instance(glm::vec3 a_position, glm::vec3 a_eulerAngles, glm::vec3 a_scale, aie::OBJMesh* a_mesh, aie::ShaderProgram* a_shader)
	: m_mesh(a_mesh), m_shader(a_shader)
{
	m_transform = MakeTransform(a_position, a_eulerAngles, a_scale);
}


glm::mat4 Instance::MakeTransform(glm::vec3 a_position, glm::vec3 a_eulerAngles, glm::vec3 a_scale)
{
	return glm::translate(glm::mat4(1), a_position)
		* glm::rotate(glm::mat4(1), glm::radians(a_eulerAngles.x), glm::vec3(1, 0, 0))
		* glm::rotate(glm::mat4(1), glm::radians(a_eulerAngles.y), glm::vec3(0, 1, 0))
		* glm::rotate(glm::mat4(1), glm::radians(a_eulerAngles.z), glm::vec3(0, 0, 1))
		* glm::scale(glm::mat4(1), a_scale);
			
}


void Instance::Draw(Scene* scene)
{
	m_shader->bind();
	
	auto pvm = scene->getCamera()->GetProjectionMatrix(scene->GetWindowSize().x, scene->GetWindowSize().y) * 
		scene->getCamera()->GetViewMatrix() * m_transform;

	m_shader->bindUniform("ProjectionViewModel", pvm);
	m_shader->bindUniform("CameraPosition", scene->getCamera()->GetPosition());
	m_shader->bindUniform("AmbientColor", scene->GetAmbientLight());
	m_shader->bindUniform("LightColor", scene->GetLight().m_color);
	m_shader->bindUniform("LightDirection", scene->GetLight().m_direction);
	m_shader->bindUniform("ModelMatrix", m_transform);

	int numofLights = scene->GetNumOfLights();
	m_shader->bindUniform("numOfLights", numofLights);
	m_shader->bindUniform("PointLightPosition", numofLights, scene->GetPointLightPos());
	m_shader->bindUniform("PointLightColor", numofLights, scene->GetPointLightColor());



	
	m_mesh->draw();
}

