#ifndef MYMATERIALS_H
#define MYMATERIALS_H

#include <graphics/Shader.h>

struct SharedShaderValues
{
	float totalTime;
};

class GlobalShaderUniforms : public graphics::ShaderUniforms
{
public:
	GlobalShaderUniforms(graphics::Shader* shader, const SharedShaderValues* shaderShaderValues = 0);
	~GlobalShaderUniforms();
private:

		


};

#endif