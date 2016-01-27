#include "Tehtävä2.h"

QuadScene2::QuadScene2()
{
	LOG("QuadScene2 construct");
	//shader lataus
	FRM_SHADER_ATTRIBUTE attributes[3] = {
		{ "g_vVertex", 0 },
		{ "g_vColor", 1 },
		{ "g_vTexCoord", 2 }
	};

	numAttributes = sizeof(attributes) / sizeof(FRM_SHADER_ATTRIBUTE);
	m_shader = new graphics::Shader("assets/QuadScene.glvs", "assets/QuadScene.glfs", attributes, numAttributes);


	checkOpenGL();

	//m_count = 0.0f;
	//m_sharedValues.totalTime = 0.0f;
	totalTime = 0.0f;
	m_material = new GlobalShaderUniforms(m_shader, &m_sharedValues);
	
	

}

QuadScene2::~QuadScene2()
{
	LOG("QuadScene2 destruct");
}

void QuadScene2::update(graphics::ESContext* esContext, float deltaTime)
{
	//m_count += deltaTime;

	//if (m_count > 1.0f)
	//	m_count = 0.0f;

	//if (m_sharedValues.totalTime > 1.0f)
	//{
	//	m_sharedValues.totalTime -= deltaTime;
	//}
	//else
	//{
		//m_sharedValues.totalTime += deltaTime;
		  totalTime += deltaTime;
	//}

}

void QuadScene2::render(graphics::ESContext* esContext)
{
	checkOpenGL();

	// Set the viewport
	glViewport(0, 0, esContext->width, esContext->height);
	checkOpenGL();

	float aspectRatio = float(esContext->width) / float(esContext->height);
	float fSize = 0.8f;
	float VertexPositions[] =
	{
		-fSize, -fSize*aspectRatio, 0.0f, 1.0f,
		+fSize, -fSize*aspectRatio, 0.0f, 1.0f,
		-fSize, +fSize*aspectRatio, 0.0f, 1.0f,
		+fSize, +fSize*aspectRatio, 0.0f, 1.0f,
	};

	float VertexColors[] = {
		1.0f, 0.5f, 0.0f, 1.0f,
		0.2f, 1.0f, 0.0f, 1.0f,
		0.15f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	float VertexCoords[] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f
	};

	// Clear the backbuffer and depth-buffer
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	checkOpenGL();

	// Set the shader program and the texture
	m_material->bind();

	// Draw the colored triangle
	glVertexAttribPointer(0, 4, GL_FLOAT, 0, 0, VertexPositions);
	checkOpenGL();
	glEnableVertexAttribArray(0);
	checkOpenGL();

	glVertexAttribPointer(1, 4, GL_FLOAT, 0, 0, VertexColors);
	checkOpenGL();
	glEnableVertexAttribArray(1);
	checkOpenGL();

	glVertexAttribPointer(2, 2, GL_FLOAT, 0, 0, VertexCoords);
	checkOpenGL();
	glEnableVertexAttribArray(2);
	checkOpenGL();

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	checkOpenGL();

	glDisableVertexAttribArray(0);
	checkOpenGL();
	glDisableVertexAttribArray(1);
	checkOpenGL();
	glDisableVertexAttribArray(2);
	checkOpenGL();
}