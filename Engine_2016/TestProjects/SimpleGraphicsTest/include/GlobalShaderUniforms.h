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
//
//	}
//	~GlobalShaderUniforms()
//	{
//
//	}
//
//
//	virtual void getUniformLocations(graphics::Shader* shader)
//	{
//		m_id = glGetUniformLocation(shader->getProgram(), "g_matModelViewProj");
//	}
//	virtual void bind(graphics::Shader* shader)
//	{
//		if (m_id >= 0)
//		{
//			glUniformMatrix4fv(m_id, 1, GL_FALSE, &m_shaderShaderValues->matModelViewProj[0][0]);
//		}
//	}
//
//
//private:
//	const SharedShaderValues* m_shaderShaderValues;
//	GLint m_id;
//};
//
//#endif