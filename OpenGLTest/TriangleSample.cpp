//#include <glad/glad.h>
//#include "GLFW/glfw3.h"
//#include <iostream>
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//GLFWwindow* window = nullptr;
//bool InitOpenGL( );
//void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode );
//void Render( );
//void InitData( );
//
//unsigned int VBO;
//unsigned int VAO;
//unsigned int shaderProgram;
//
//int main( )
//{
//	if ( InitOpenGL( ) == false )
//	{
//		glfwTerminate( );
//		return -1;
//	}
//
//	while( !glfwWindowShouldClose( window ) )
//	{
//		glfwPollEvents( );
//		Render( );
//		glfwSwapBuffers( window );
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
//	glfwMakeContextCurrent( window );
//	glfwSetKeyCallback( window, OnKeyCallback );
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
//	InitData( );
//	return true;
//}
//
//void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
//{
//	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
//		glfwSetWindowShouldClose( window, GLFW_TRUE );
//}
//
//void Render( )
//{
//	glUseProgram( shaderProgram );
//
//	glBindVertexArray( VAO );
//	glDrawArrays( GL_TRIANGLES, 0, 3 );
//}
//
//void InitData( )
//{
//	float vertices[] = {
//		-0.5f, -0.5f, 0.0f,
//		 0.5f, -0.5f, 0.0f,
//		 0.0f,  0.5f, 0.0f
//	};
//
//	glGenBuffers( 1, &VBO );
//	glGenVertexArrays( 1, &VAO );
//	glBindVertexArray( VAO );
//
//	glBindBuffer( GL_ARRAY_BUFFER, VBO );
//	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices), vertices, GL_STATIC_DRAW );
//
//	// Create vertex shader
//	char* vertexShaderSource = "#version 330 core \n"
//		"layout (location = 0) in vec3 aPos;\n"
//		"void main()\n"
//		"{ gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }";
//	unsigned int vertexShader;
//	vertexShader = glCreateShader( GL_VERTEX_SHADER );
//	glShaderSource( vertexShader, 1, &vertexShaderSource, NULL );
//	glCompileShader( vertexShader );
//
//	int success;
//	char infoLog[512];
//	glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &success );
//	if (!success )
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "[ERROR] Compile vertex shader failed! info:\n" << infoLog << std::endl;
//	}
//
//	// Create fragment shader
//	char* fragmentShaderSource = "#version 330 core\n"
//	"out vec4 FragColor;\n"
//	"void main()\n"
//	"{ FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); }";
//
//	unsigned int fragmentShader;
//	fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
//	glShaderSource( fragmentShader, 1, &fragmentShaderSource, NULL );
//	glCompileShader( fragmentShader );
//
//	glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &success );
//	if (!success )
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "[ERROR] Compile fragment shader failed! info:\n" << infoLog << std::endl;
//	}
//
//	shaderProgram = glCreateProgram( );
//	glAttachShader( shaderProgram, vertexShader );
//	glAttachShader( shaderProgram, fragmentShader );
//	glLinkProgram( shaderProgram );
//	glGetProgramiv( shaderProgram, GL_LINK_STATUS, &success );
//	if( !success )
//	{
//		glGetProgramInfoLog( shaderProgram, 512, NULL, infoLog );
//		std::cout << "[ERROR] Link shader Program failed! info:\n" << infoLog << std::endl;
//	}
//	glUseProgram( shaderProgram );
//
//	glDeleteShader( vertexShader );
//	glDeleteShader( fragmentShader );
//	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void*)0 );
//	glEnableVertexAttribArray( 0 );
//}