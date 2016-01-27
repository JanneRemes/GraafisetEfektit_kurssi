#ifndef SIMPLEMESHRENDERINGSCENE_H
#define SIMPLEMESHRENDERINGSCENE_H

#include "scene.h"
#include <core/log.h>
#include <graphics\Shader.h>
#include "MyMaterials.h"
#include <graphics\Mesh.h>
#include <teapot.h>

class Simple3DScene : public Scene
{
public:
	Simple3DScene();
	~Simple3DScene();

	virtual void update(graphics::ESContext* esContext, float deltaTime);
	virtual void render(graphics::ESContext* esContext);

	graphics::Mesh* createTeapotMesh();

private:

	core::Ref<graphics::Shader> m_shader;
	int numAttributes;
	SharedShaderValues m_sharedValues;
	core::Ref<graphics::ShaderUniforms> m_material;
	core::Ref<graphics::Mesh> m_mesh;

	float m_totalTime;

	slmath::mat4 m_matProjection;
	slmath::mat4 m_matView;
	slmath::mat4 m_matModel;
};

#endif