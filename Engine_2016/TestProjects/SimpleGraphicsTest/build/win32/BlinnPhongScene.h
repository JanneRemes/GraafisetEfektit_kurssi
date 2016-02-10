#ifndef BLINNPHONGSCENE_H
#define BLINNPHONGSCENE_H


#include "scene.h"
#include <core/log.h>
#include <graphics\Shader.h>
#include "MyMaterials.h"
#include <graphics\Mesh.h>
#include <teapot.h>

#include "SimpleMaterialUniforms.h"

class BlinnPhongScene : public Scene
{
public:
	BlinnPhongScene();
	~BlinnPhongScene();

	virtual void update(graphics::ESContext* esContext, float deltaTime);
	virtual void render(graphics::ESContext* esContext);

	graphics::Mesh* createTeapotMesh();

private:

	int numAttributes;
	SharedShaderValues m_sharedValues;
	core::Ref<graphics::ShaderUniforms> m_material;
	core::Ref<graphics::Mesh> m_mesh;

	float m_totalTime;

	slmath::mat4 m_matProjection;
	slmath::mat4 m_matView;
	slmath::mat4 m_matModel;
	core::Ref<graphics::Texture> m_texture;
	core::Ref<graphics::Image> m_image;

};
#endif