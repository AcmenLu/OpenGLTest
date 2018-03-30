#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <iostream>
#include "Shader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

const GLuint WIDTH = 800, HEIGHT = 600;
GLFWwindow* window = nullptr;
bool InitOpenGL( );
void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode );
void Render( );
void InitData( );

unsigned int VBO;
unsigned int VAO;
unsigned int shaderProgram;

Shader* shader;

int main( )
{
	if ( InitOpenGL( ) == false )
	{
		glfwTerminate( );
		return -1;
	}

	while( !glfwWindowShouldClose( window ) )
	{
		glfwPollEvents( );
		Render( );
		glfwSwapBuffers( window );
	}

	glfwTerminate( );
	return 0;
}

bool InitOpenGL( )
{
	glfwInit( );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	window = glfwCreateWindow( WIDTH, HEIGHT, "Acmen", NULL, NULL );
	if ( window == NULL )
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		return false;
	}

	glfwMakeContextCurrent( window );
	glfwSetKeyCallback( window, OnKeyCallback );
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	int width, height;
	glfwGetFramebufferSize( window, &width, &height );
	glViewport( 0, 0, width, height );
	InitData( );
	return true;
}

void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
{
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
		glfwSetWindowShouldClose( window, GLFW_TRUE );
}

void Render( )
{
	shader->Use( );
	glBindVertexArray( VAO );
	glDrawArrays( GL_TRIANGLES, 0, 3 );
}

void InitData( )
{
	float vertices[] = {
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
	};

	glGenBuffers( 1, &VBO );
	glGenVertexArrays( 1, &VAO );
	glBindVertexArray( VAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices), vertices, GL_STATIC_DRAW );

	shader = new Shader( "./Shader/texturesample_vs.txt", "./Shader/texturesample_fs.txt" );

	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), (void*)0 );
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( float ), (void*)( 3 * sizeof(float) ) );
	glEnableVertexAttribArray( 1 );
}