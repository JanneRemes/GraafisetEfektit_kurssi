#ifndef SIMPLEMATERIALUNIFORMS_H
#define SIMPLEMATERIALUNIFORMS_H

#include <graphics\Shader.h>
#include <graphics\Texture.h>

#include "MyMaterials.h"

class SimpleMaterialUniforms : public graphics::ShaderUniforms
{
public:
	slmath::vec4 vAmbient;
	slmath::vec4 vDiffuse;
	slmath::vec4 vSpecular;
	core::Ref<graphics::Texture> diffuseMap;

	SimpleMaterialUniforms(graphics::Shader *shader, SharedShaderValues* sharedValues = 0)
		:ShaderUniforms(shader)
		, m_globalShaderUniforms(new GlobalShaderUniforms(shader, sharedValues))
	{
	}

	virtual ~SimpleMaterialUniforms()
	{
	}

	virtual void getUniformLocations(graphics::Shader* shader)
	{
		m_globalShaderUniforms->getUniformLocations(shader);
		m_materialAmbientLoc = glGetUniformLocation(shader->getProgram(), "g_Material.vAmbient");
		m_materialDiffuseLoc = glGetUniformLocation(shader->getProgram(), "g_Material.vDiffuse");
		m_materialSpecularloc = glGetUniformLocation(shader->getProgram(), "g_Material.vSpecular");
		m_diffuseTextureLoc = glGetUniformLocation(shader->getProgram(), "DiffuseTexture");
	}

	virtual void bind(graphics::Shader *shader)
	{
		shader->bind();
		m_globalShaderUniforms->bind(shader);
		glUniform4fv(m_materialAmbientLoc, 1, &vAmbient.x);
		glUniform4fv(m_materialDiffuseLoc, 1, &vDiffuse.x);
		glUniform4fv(m_materialSpecularloc, 1, &vSpecular.x);
		
		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap->getTextureId());

		glUniform1i(m_diffuseTextureLoc, 0);

	}



private:
	core::Ref<GlobalShaderUniforms> m_globalShaderUniforms;
	GLint m_materialAmbientLoc;
	GLint m_materialDiffuseLoc;
	GLint m_materialSpecularloc;
	GLint m_diffuseTextureLoc;

};


class SimpleMaterialWithTextureUniforms : public SimpleMaterialUniforms
{
public:
	SimpleMaterialWithTextureUniforms(graphics::Shader* shader, SharedShaderValues* sharedValues)
		:SimpleMaterialUniforms(shader, sharedValues)
	{
	}

	virtual ~SimpleMaterialWithTextureUniforms()
	{
	}

	virtual void getUniformLocation(graphics::Shader* shader)
	{
		SimpleMaterialUniforms::getUniformLocations(shader);

		m_diffuseMapLoc = glGetUniformLocation(shader->getProgram(), "s_diffuseMap");
	}

	virtual void bind(graphics::Shader* shader)
	{
		SimpleMaterialUniforms::bind(shader);
		//bind diffuse texture to texture sampler unit #0
		glActiveTexture(GL_TEXTURE0 + 0);
		glBindTexture(GL_TEXTURE_2D, diffuseMap->getTextureId());

		//set sampler unit 0 to be used as sampler for diffuse map uniformn
		glUniform1i(m_diffuseMapLoc, 0);
	}

private:
	GLint m_diffuseMapLoc;
};

#endif