#pragma once
#include <list>
#include <vector>
#include  <glm/glm.hpp>


class Camera;
class Instance;

struct Light
{
	Light()
	{
		m_direction = glm::vec3(0);
		m_color = glm::vec4(1, 1, 1, 1);
	};
	Light(glm::vec3 a_pos, glm::vec3 a_color, float a_intensity)
	{
		m_direction = a_pos;
		m_color = a_color * a_intensity;
	};

	glm::vec3 m_direction;
	glm::vec3 m_color;

	
};

const int MAX_LIGHTS = 4;
class Scene
{

public:

	Scene(Camera* camera, glm::vec2 windowSize, Light& light, glm::vec3 ambientLight);
	~Scene();

	void AddInstances(Instance* instance);
	void Draw();

	Camera* getCamera()
	{
		return m_camera;
	}
	
	glm::vec2 GetWindowSize()
	{
		return m_windowSize;
	}
	Light& GetLight()
	{
		return m_light;
	}
	glm::vec3 GetAmbientLight()
	{
		return m_ambientLight;
	}


	int GetNumOfLights() { return (int)m_pointLights.size(); }
	
	std::list<Instance*> getList() { return m_instances; }
	// getters for vecs and vectorLists

	glm::vec3* GetPointLightPos() { return &m_pointLightPositions[0]; }
	glm::vec3* GetPointLightColor() { return &m_pointLightColors[0]; }
	std::vector<Light>& GetPointLights() { return m_pointLights; }


protected:
	Camera* m_camera;
	glm::vec2 m_windowSize;
	Light m_light;

	std::vector<Light> m_pointLights;
	Light sunlight;
	
	glm::vec3 m_pointLightPositions[MAX_LIGHTS];
	glm::vec3 m_pointLightColors[MAX_LIGHTS];
	glm::vec3 m_ambientLight;
	std::list<Instance*> m_instances;
	
};

