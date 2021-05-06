#pragma once
#define GLM_ENABLE_EXPERIMENTAL

#include <functional>
#include  <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>

class Camera;
class Scene;

namespace aie
{
	class OBJMesh;
	class ShaderProgram;
}


class Instance
{

public:

	Instance(glm::mat4 a_transform, aie::OBJMesh* a_mesh, aie::ShaderProgram* a_shader);
	Instance(glm::vec3 a_position, glm::vec3 a_eulerAngles, glm::vec3 a_scale, aie::OBJMesh* a_mesh, aie::ShaderProgram* a_shader);

	void Draw(Scene* scene);

	 glm::mat4 MakeTransform(glm::vec3 a_position, glm::vec3 a_eulerAngles, glm::vec3 a_scale);

	 void DecomposeMatrix()
	 {
		 glm::decompose(m_transform, scale, rotation, translation, skew, perspective);
		 rotation = glm::conjugate(rotation); 	
	 }


	glm::vec3 GetPosition() const { return translation; }
	glm::vec3 GetScale() const { return scale; }
	glm::quat GetRotation() const { return rotation; }
	glm::vec3 GetSkew() const { return skew; }
	glm::vec4 GetPerspective() const { return perspective; }

	glm::mat4 m_transform;

protected:



	glm::vec3 scale;
	glm::quat rotation;
	glm::vec3 translation;
	glm::vec3 skew;
	glm::vec4 perspective;
	
	aie::OBJMesh* m_mesh;
	aie::ShaderProgram* m_shader;
	
};

