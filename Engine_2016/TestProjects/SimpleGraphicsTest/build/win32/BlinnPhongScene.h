#ifndef BLINNPHONGSCENE_H
#define BLINNPHONGSCENE_H


#include "scene.h"
#include <core/log.h>
#include <graphics\Shader.h>
#include "MyMaterials.h"
#include <graphics\Mesh.h>
#include <graphics\Image.h>
#include <teapot.h>
#include <graphics\Texture.h>

#include "SimpleMaterialUniforms.h"

//kokeilu
#include <math.h>
#include <ctime>

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
	core::Ref<graphics::Texture2D> m_texture;
	core::Ref<graphics::Image> m_image;

};
#endif