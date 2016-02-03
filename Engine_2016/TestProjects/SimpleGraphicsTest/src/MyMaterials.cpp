//#include "MyMaterials.h"
//
//GlobalShaderUniforms::GlobalShaderUniforms(graphics::Shader* shader, const SharedShaderValues* shaderShaderValues = 0) : graphics::ShaderUniforms(shader), m_shaderShaderValues(shaderShaderValues)
//{	
//	
//}
//
//GlobalShaderUniforms::~GlobalShaderUniforms()
//{
//
//}
//void GlobalShaderUniforms::getUniformLocations(graphics::Shader* shader)
//{
//	m_id = glGetUniformLocation(shader->getProgram(), "g_matModelViewProj");
//}
//
//void GlobalShaderUniforms::bind(graphics::Shader* shader)
//{
//	shader->bind();
//
//	if (m_shaderShaderValues)
//	{
//		if (m_id > 0)
//		{
//			glUniformMatrix4fv(m_id, 1, GL_FALSE, &m_shaderShaderValues->matModelViewProj[0][0]);
//		}		
//	}
//}