#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Sphere.h"
#include "Box.h"
#include "PhysicsScene.h"

class Physics_ProjectApp : public aie::Application
{
public:

	Physics_ProjectApp();
	virtual ~Physics_ProjectApp();

	virtual bool startup();
	void DebugUI();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	glm::vec2 ScreenToWorld(glm::vec2 a_screenPos);

	void TriggerTest();
	void DrawRect();
	void SphereAndPlane();
	void SpringTest(int a_amount);
	void GameScene(int a_amount = 0);
	void GenerateStart();

	bool toggle = false;
protected:

	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;

	PhysicsScene* m_physicsScene;
	Sphere* hole;
	Sphere* pole;
	Sphere* mouseTrigger;
	Sphere* whiteBall;
	Sphere* billardBalll;

	Box* bounds;

	glm::vec4 RED;
	glm::vec4 GREEN;
	glm::vec4 BLUE;
	glm::vec4 WHITELINES;
	glm::vec4 REDLINES;
	glm::vec4 GREENLINES;

	glm::vec4 lineColor;

	int iteratorDebug = 0;

	bool whiteBallMoving = false;
	bool gameRunning = true;
	unsigned int sphereNumber;

	glm::vec2 m_mouseVelocity;
	glm::vec2 velo;
	glm::vec2 m_prevPos;

	glm::vec2 firedVelocity;

	float lineLength;
	float mouseState;

	bool playerWin1 = false;
	bool playerWin2 = false;

	// False = turn 1
	// True = turn 2
	bool turn = false;

	bool TURN_2 = true;
	bool TURN_1 = false;
	
	// Red player
	const int PLAYER_ONE_MAX = 5;
	// Blue Player
	const int PLAYER_TWO_MAX = 6;

	// red player
	int playerOneScore = 0;

	// Blue player
	int playerTwoScore = 0;
	
	const float m_aspectRatio = 16.0f / 9.0f;
	const float m_extents = 100.0f;
};