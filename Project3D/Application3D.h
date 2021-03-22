#pragma once

#include "Application.h"
#include "Mesh.h"
#include "OBJMesh.h"
#include "Shader.h"
#include "Camera.h"
#include "imgui.h"
#include "Scene.h"
#include <glm/mat4x4.hpp>
#include <vector>

class Application3D : public aie::Application
{
public:

	Application3D();
	virtual ~Application3D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	float z = 0.03;
	float b = 2;
	float x = 0.01;
	float val = 2;
	
protected:

	Camera m_camera;
	
	aie::Texture m_gridTexture;

	glm::vec3				pos;
	glm::mat4				m_viewMatrix;
	glm::mat4				m_projectionMatrix;
	glm::mat4				m_planetTransform;

	glm::vec4				colorthing;
	glm::vec4				bunnyColour;
	
	// ====== SHADER ==============
	aie::ShaderProgram		m_simpleShader;
	aie::ShaderProgram	    m_bunnyShader;
	aie::ShaderProgram		m_phongShader;
	aie::ShaderProgram		m_texturedShader;
	aie::ShaderProgram		m_normalMapShader;
	// ============================

	

	struct gameObject
	{
		std::string			name;
		aie::OBJMesh		mesh;
		glm::mat4			transform;
		glm::vec3			position;
		glm::vec3			scale;
		glm::vec3			rotation;
		
	};

	struct quadObject
	{
		std::string name;
		Mesh mesh;
		glm::mat4 transform;
	};


	
	Scene* m_scene;

	
	gameObject*				m_bunny;
	gameObject*				m_dragon;
	gameObject*				m_spear;
	gameObject*				m_spear2;
	quadObject				m_quad;
	

	// Light Object
	/*struct Light
	{
		glm::vec3			direction;
		glm::vec3			color;
	};

	Light					m_light;
	glm::vec3				m_ambientLight;*/
	glm::vec3				diffuseVec;
	float					xPos = 0;
	float					yPos = 0;
	int						m_iter = 0;
	int						m_max;

	std::vector<gameObject*> m_objects;


public:

	bool LoadShaperAndMeshLogic(Light a_light);
	//void DrawShaderAndMeshes(glm::mat4, glm::mat4);

private:

	void DebugUI(float dt);

};