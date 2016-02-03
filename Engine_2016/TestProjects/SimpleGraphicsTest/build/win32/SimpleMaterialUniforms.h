#ifndef SIMPLEMATERIALUNIFORMS_H
#define SIMPLEMATERIALUNIFORMS_H

#include <graphics\Shader.h>

class SimpleMaterialUniforms : public graphics::ShaderUniforms
{
public:
	slmath::vec4 vAmbient;
	slmath::vec4 vDiffuse;
	slmath::vec4 vSpecular;

	SimpleMaterialUniforms(graphics::Shader *shader, sharedShader)

};

#endif