#include "Scene.h"

#include "Instance.h"

Scene::Scene(Camera* camera, glm::vec2 windowSize, Light& light, glm::vec3 ambientLight)
	: m_camera(camera), m_windowSize(windowSize), m_light(light), m_ambientLight(ambientLight)
{
	
}
Scene::~Scene()
{
	for (auto i = m_instances.begin(); i != m_instances.end(); i++)
	{
		
	}
}

void Scene::AddInstances(Instance* instance)
{
	m_instances.push_back(instance);
}

void Scene::Draw()
{
	for (auto i = m_instances.begin(); i != m_instances.end(); i++)
	{
		Instance* instance = *i;
		instance->Draw(this);
	}
}


