#ifndef TEHTÄVÄ_2
#define TEHTÄVÄ_2

#include "scene.h"
#include <core/log.h>
#include <graphics\Shader.h>


class QuadScene2 : public Scene
{
public:
	QuadScene2();
	virtual ~QuadScene2();
	virtual void update(graphics::ESContext* esContext, float deltaTime);
	virtual void render(graphics::ESContext* esContext);

private:
	float m_count;
	//GLuint m_hShaderProgram;
	core::Ref<graphics::Shader> m_shader;
	int numAttributes;
	//FRM_SHADER_ATTRIBUTE *attributes[];

};

#endif


