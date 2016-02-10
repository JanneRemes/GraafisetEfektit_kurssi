//#ifndef GLOBALSHADERUNIFORMS_H
//#define GLOBALSHADERUNIFORMS_H
//
//#include <graphics\Shader.h>
//
//struct SharedShaderValues : public core::Object
//{
//	slmath::mat4 matModelViewProj;
//};
//
//
//class GlobalShaderUniforms : graphics::ShaderUniforms
//{
//public:
//	GlobalShaderUniforms(graphics::Shader *shader, const SharedShaderValues* shaderValues = 0)
//		:ShaderUniforms(shader), m_shaderShaderValues(shaderValues)
//	{
//	}
//
//	~GlobalShaderUniforms()
//	{
//	}
//
//
//	virtual void getUniformLocations(graphics::Shader* shader)
//	{	
//		m_ids[0] = glGetUniformLocation(shader->getProgram(), "g_matModel");
//		m_ids[1] = glGetUniformLocation(shader->getProgram(), "g_matView");
//		m_ids[2] = glGetUniformLocation(shader->getProgram(), "g_matProj");
//		m_ids[3] = glGetUniformLocation(shader->getProgram(), "g_matModelView");
//		m_ids[4] = glGetUniformLocation(shader->getProgram(), "g_matNormal");
//		m_ids[5] = glGetUniformLocation(shader->getProgram(), "g_matModelViewProj");
//		m_ids[6] = glGetUniformLocation(shader->getProgram(), "g_lightPos");
//		m_ids[7] = glGetUniformLocation(shader->getProgram(), "g_camPos");
//	}
//	virtual void bind(graphics::Shader* shader)
//	{
//		shader->bind();
//		if (m_shaderShaderValues)
//		{
//			glUniformMatrix4fv(m_ids[0], 1, GL_FALSE, &m_shaderShaderValues->matModel[0][0]);
//			glUniformMatrix4fv(m_ids[1], 1, GL_FALSE, &m_shaderShaderValues->matView[0][0]);
//			glUniformMatrix4fv(m_ids[2], 1, GL_FALSE, &m_shaderShaderValues->matProj[0][0]);
//			glUniformMatrix4fv(m_ids[3], 1, GL_FALSE, &m_shaderShaderValues->matModelView[0][0]);
//			glUniformMatrix4fv(m_ids[4], 1, GL_FALSE, &m_shaderShaderValues->matNormal[0][0]);
//			glUniformMatrix4fv(m_ids[5], 1, GL_FALSE, &m_shaderShaderValues->matModelViewProj[0][0]);
//			
//			glUniform3f(m_ids[6], m_shaderShaderValues->lightPos.x, m_shaderShaderValues->lightPos.y, m_shaderShaderValues->lightPos.z);
//			glUniform3f(m_ids[7], m_shaderShaderValues->camPos.x, m_shaderShaderValues->camPos.y, m_shaderShaderValues->camPos.z);
//		}
//	}
//
//
//private:
//	const SharedShaderValues* m_shaderShaderValues;
//	GLint m_ids[8];
//};
//
//#endif