#ifndef QUADSCENE_H
#define QUADSCENE_H

#include "scene.h"
#include <core/log.h>

class QuadScene : public Scene
{
public:
	QuadScene()
	{

		LOG("QuadScene construct");
		checkOpenGL();

		m_count = 0.0f;
		m_hShaderProgram = 0;

		const char* g_strVSProgram =
			"attribute vec4 g_vVertex;											 \n"
			"attribute vec4 g_vColor;											 \n"	
			"attribute   vec2 g_vTexCoord;                                       \n"			
			"varying   vec4 g_vVSColor; 										 \n"
			"varying   vec2 g_vVTexCoord;										 \n"
			"																	 \n"
			"void main()														 \n"
			"{																	 \n"
			"    gl_Position  = vec4( g_vVertex.x, g_vVertex.y,                  \n"
			"                         g_vVertex.z, g_vVertex.w );                \n"
			"    g_vVSColor = g_vColor;											 \n"	
			"    g_vVTexCoord = vec2(g_vTexCoord.x, (1 - g_vTexCoord.y));		 \n"
			"}																	 \n";


		const char* g_strFSProgram =
			"#ifdef GL_FRAGMENT_PRECISION_HIGH									 \n"
			"   precision highp float;											 \n"
			"#else																 \n"
			"   precision mediump float;										 \n"
			"#endif																 \n"
			"																	 \n"
			"varying   vec4 g_vVSColor;											 \n"
			"varying   vec2 g_vVTexCoord;										 \n"
			"																	 \n"
			"uniform float totalTime;											 \n"
			"																	 \n"
			"void main()														 \n"
			"{																	 \n"
			"																	 \n"
			"	float x = g_vVTexCoord.x * 500;									 \n"
			"	float y = g_vVTexCoord.y * 500;									 \n"
			"	float t = totalTime;											 \n"
			"	float vv = 0.25 * tan(											 \n"
			"(0.5 + (0.5 * sin(x / 32.0 + t)))  +								 \n"
			"(0.5 + (0.5 * sin(x / 21.0 - t)))  + 								 \n"
			"(0.5 + (0.5 * sqrt((x + y)/ 6.0 - t)))  +							 \n"
			"(0.5 + (0.5 * sin(sqrt(float(x*x + y*y)) /4.0 - t))));			 \n"
			"gl_FragColor = vec4(vv, vv, vv, 1.0) * g_vVSColor;					 \n"
			"}																	 \n";
			//gl_FragColor = vec4((g_vVTexCoord.x + g_vVTexCoord.y)/2);
		

		FRM_SHADER_ATTRIBUTE attributes[3] = {
			{ "g_vVertex", 0 },
			{ "g_vColor", 1 },
			{ "g_vTexCoord", 2 }
		};

		FrmCompileShaderProgram(g_strVSProgram, g_strFSProgram, &m_hShaderProgram, attributes, sizeof(attributes) / sizeof(FRM_SHADER_ATTRIBUTE));

		checkOpenGL();
	}


	virtual ~QuadScene()
	{
		glDeleteProgram(m_hShaderProgram);
		LOG("TriangleScene destruct");
	}


	virtual void update(graphics::ESContext* esContext, float deltaTime)
	{
		m_count += deltaTime;
		

		if (m_timer < 12 && timerZeroed)
		{
			m_timer += deltaTime;
			if (m_timer > 12)
			{
				timerZeroed = false;
			}
		}
		else
		{
			m_timer -= deltaTime;
			if (m_timer < 0)
			{
				timerZeroed = true;
			}
		
		}

		if (m_count > 1.0f)
			m_count = 0.0f;
	}


	virtual void render(graphics::ESContext* esContext)
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
		glUseProgram(m_hShaderProgram);
		checkOpenGL();

		GLint loc = glGetUniformLocation(m_hShaderProgram, "totalTime");
		if (loc != -1)
		{
			glUniform1f(loc, 1.0f*m_timer);
		}

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
private:
	float m_count;
	float m_timer;
	bool timerZeroed = true;
	GLuint       m_hShaderProgram;

};


#endif


