#include "SimpleMeshRenderingScene.h"

Simple3DScene::Simple3DScene()
{
	LOG("Simple3DScene construct");
	//shader lataus
	FRM_SHADER_ATTRIBUTE attributes[2] = {
		{ "g_vPositionOS", graphics::ATTRIB_POSITION },
		{ "g_vNormalOS", graphics::ATTRIB_NORMAL }
	};

	//load shader
	core::Ref<graphics::Shader> m_shader =
		new graphics::Shader("assets/Simple3d.glvs", "assets/Simple3d.glfs",
		attributes, sizeof(attributes) / sizeof(FRM_SHADER_ATTRIBUTE));
	
	m_mesh = createTeapotMesh();

	checkOpenGL();

	//m_count = 0.0f;
	m_totalTime = 0.0f;

	m_material = new GlobalShaderUniforms(m_shader, &m_sharedValues);




}

Simple3DScene::~Simple3DScene()
{
	LOG("Simple3DScene destructor");
}

void Simple3DScene::update(graphics::ESContext* esContext, float deltaTime)
{

	m_totalTime += deltaTime;


	//camera perspective matrix * field of view, aspect ratio, near plane distance and far plane distance
	float fAspect = (float)esContext->width / (float)esContext->height;
	m_matProjection = slmath::perspectiveFovRH(
		slmath::radians(45.0f),
	fAspect,
		5.0f,
		1000.0f
		);

	//look at view matrix = eya point, look at point and world up vector
	m_matView = slmath::lookAtRH(
		slmath::vec3(0.0f, 70.0f, 70.0f),
		slmath::vec3(0.0f, 15.0f, 0.0f),
		slmath::vec3(0.0f, 1.0f, 0.0f));

	//update teapot model matrix
	m_matModel = slmath::rotationX(-3.1415f*0.5f); //-90 degrees around first
	m_matModel = slmath::rotationY(m_totalTime) * m_matModel; // rotate according to total time
	m_matModel = slmath::translation(slmath::vec3(0.0f, 0.0f, 0.0f)) * m_matModel; //Translate


}

void Simple3DScene::render(graphics::ESContext* esContext)
{	
	//set the viewport
	glViewport(0, 0, esContext->width, esContext->height);

	//clear the backbuffer and depth buffer
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	checkOpenGL();

	//initialize GL state
	glDisable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	checkOpenGL();

	//these values are needed to update for each mesh which is rendered (different model matrix)
	slmath::mat4 matModelView = m_matView * m_matModel;
	slmath::mat4 matModelViewProj = m_matProjection * matModelView;

	//set matrix to shared values
	m_sharedValues.matModelViewProj = matModelViewProj;

	//bind material (sets uniform values)
	m_material->bind();
	checkOpenGL();

	//render the mesh using active material
	m_mesh->render();
	checkOpenGL();
}

graphics::Mesh* Simple3DScene::createTeapotMesh()
{
	//index buffer
	graphics::IndexBuffer *ib = new graphics::IndexBuffer(TeapotData::indices, TeapotData::numIndices);

	//create vertex array
	graphics::VertexArray *va[] =
	{
		new graphics::VertexArrayImpl<slmath::vec3>(
		graphics::ATTRIB_POSITION, (slmath::vec3*)TeapotData::positions, TeapotData::numVertices),

		new graphics::VertexArrayImpl<slmath::vec3>(
		graphics::ATTRIB_NORMAL, (slmath::vec3*)TeapotData::normals, TeapotData::numVertices)
	};

	//create vertex buffer from vertex array
	graphics::VertexBuffer *vb = new graphics::VertexBuffer(&va[0], sizeof(va) / sizeof(va[0]));

	//create mesh from ib and vb
	return new graphics::Mesh(ib, vb);

}