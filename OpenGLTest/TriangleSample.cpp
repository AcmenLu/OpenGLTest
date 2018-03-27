#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <iostream>

const GLuint WIDTH = 800, HEIGHT = 600;
GLFWwindow* window = nullptr;
bool InitOpenGL( );
void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode );
void Render( );
void InitData( );

float vertices[3];

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

	return true;
}

void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
{
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
		glfwSetWindowShouldClose( window, GLFW_TRUE );
}

void Render( )
{
	glClearColor( 1.0f, 0.3f, 0.2f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void InitData( )
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};
	unsigned int VBO;
	glGenBuffers( 1, &VBO );
	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices), vertices, GL_STATIC_DRAW );

	char* vertexShaderSource = "";
	unsigned int vertexShader;
	vertexShader = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertexShader, 1, &vertexShaderSource, NULL );
	glCompileShader( vertexShader );

	int success;
	char infoLog[512];
	glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &success );
	if (!success )
	{
		 glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

}