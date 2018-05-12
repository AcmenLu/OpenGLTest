//#include <glad/glad.h>
//#include "GLFW/glfw3.h"
//#include <iostream>
//#include "Shader.h"
//#include "Camera.h"
//
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//GLFWwindow* window = nullptr;
//bool InitOpenGL( );
//void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode );
//void Update( );
//void Render( );
//void InitData( );
//void ReleaseData( );
//
//unsigned int loadImage( char* filename );
//
//unsigned int lightVBO;
//unsigned int lightEBO;
//unsigned int lightVAO;
//
//Shader* lightshader;
//Shader* shader;
//Camera* camera;
//
//glm::mat4 identity;
//glm::mat4 lightmodel;
//glm::mat4 lighttransform;
//glm::mat4 projection = glm::perspective( glm::radians( 45.0f ), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f );
//
//int main()
//{
//	if (InitOpenGL() == false)
//	{
//		glfwTerminate();
//		return -1;
//	}
//	camera = new Camera( );
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		Update( );
//		Render( );
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate( );
//	return 0;
//}
//
//bool InitOpenGL( )
//{
//	glfwInit( );
//	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
//	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
//	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
//
//	window = glfwCreateWindow( WIDTH, HEIGHT, "Acmen", NULL, NULL );
//	if ( window == NULL )
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		return false;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetKeyCallback(window, OnKeyCallback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return false;
//	}
//
//	int width, height;
//	glfwGetFramebufferSize( window, &width, &height );
//	glViewport( 0, 0, width, height );
//	glEnable( GL_DEPTH_TEST );
//	InitData( );
//	return true;
//}
//
//void OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
//		glfwSetWindowShouldClose( window, true );
//}
//
//void Update( )
//{
//	lightmodel = glm::rotate( identity, glm::radians( 45.0f ), glm::vec3( 1.0f, 1.0f, 0.0f ) );
//	lightmodel = glm::scale( lightmodel, glm::vec3( 0.5f, 0.5f, 0.5f ) );
//	lighttransform = projection * camera->GetMatrix( ) * lightmodel;
//}
//
//void Render( )
//{
//	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	lightshader->Use( );
//
//	lightshader->SetMatrix4( "model", glm::value_ptr( lightmodel ), false );
//	lightshader->SetMatrix4( "transform", glm::value_ptr( lighttransform ), false );
//
//	lightshader->SetVector3( "viewpos", camera->mPosition );
//
//	lightshader->SetVector3( "material.ambient", 1.0f, 0.5f, 0.31f );
//	lightshader->SetVector3( "material.diffuse", 1.0f, 0.5f, 0.31f );
//	lightshader->SetVector3( "material.specular", 0.5f, 0.5f, 0.5f );
//	lightshader->SetFloat( "material.shininess", 32.0f );
//
//	glm::vec3 lightColor;
//	lightColor.x =  sin( glfwGetTime( ) * 2.0f );
//	lightColor.y =  sin( glfwGetTime( ) * 0.7f );
//	lightColor.z =  sin( glfwGetTime( ) * 1.3f );
//	glm::vec3 diffuseColor = lightColor   * glm::vec3( 0.5f );
//	glm::vec3 ambientColor = diffuseColor * glm::vec3( 0.2f );
//	lightshader->SetVector3( "light.position", 1.2f, 1.0f, 2.0f );
//	lightshader->SetVector3( "light.ambient", ambientColor );
//	lightshader->SetVector3( "light.diffuse", diffuseColor );
//	lightshader->SetVector3( "light.specular", 1.0f, 1.0f, 1.0f );
//
//	glBindVertexArray( lightVAO );
//	glDrawArrays( GL_TRIANGLES, 0, 36 );
//}
//
//void InitData()
//{
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
//
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
//	};
//
//	glGenBuffers( 1, &lightVBO );
//	glGenVertexArrays( 1, &lightVAO );
//	glBindVertexArray( lightVAO );
//
//	glBindBuffer( GL_ARRAY_BUFFER, lightVBO );
//	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );
//
//	lightshader = new Shader("./Shader/Light/Material/materialsample.vs", "./Shader/Light/Material/materialsample.fs");
//
//	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), (void*)0 );
//	glEnableVertexAttribArray( 0 );
//
//	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), (void*)( 3 * sizeof( float ) ) );
//	glEnableVertexAttribArray( 1 );
//
//	lightshader->Use( );
//}
//
//void ReleaseData( )
//{
//	if ( lightshader != nullptr )
//		delete lightshader;
//
//	if ( camera != nullptr )
//		delete camera;
//}
