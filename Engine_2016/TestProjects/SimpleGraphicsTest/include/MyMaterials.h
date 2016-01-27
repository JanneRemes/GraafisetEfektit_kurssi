#ifndef MYMATERIALS_H
#define MYMATERIALS_H

#include <graphics/Shader.h>
#include "GlobalShaderUniforms.h"

struct SharedShaderValues : public core::Object
{
	//float totalTime;
	slmath::mat4 matModelViewProj;
};

class GlobalShaderUniforms : public graphics::ShaderUniforms
{
public:

	GlobalShaderUniforms(graphics::Shader* shader, const SharedShaderValues* shaderShaderValues);
	virtual ~GlobalShaderUniforms();

	virtual void getUniformLocations(graphics::Shader* shader);
	virtual void bind(graphics::Shader* shader);

private:
	const SharedShaderValues* m_shaderShaderValues;
	GLint m_id;
	
};

#endif