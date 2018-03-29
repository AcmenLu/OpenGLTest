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
//unsigned int VAO; // Vertex buffer object.
//unsigned int EBO; // Index buffer object.
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
//	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
//	glClear( GL_COLOR_BUFFER_BIT );
//	float timeValue = glfwGetTime( );
//	float greenValue = ( sin( timeValue) / 2.0f ) + 0.5f;
//	int verLocation = glGetUniformLocation( shaderProgram, "ourColor" );
//	glUseProgram( shaderProgram );
//	glUniform4f( verLocation, 1.0f, greenValue, 1.0f, 1.0f );
//	glBindVertexArray( VAO );
//	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
//	glBindVertexArray( 0 );
//}
//
//void InitData( )
//{
//	float vertices[] = {
//		0.5f, 0.5f, 0.0f,	// 右上角
//		0.5f, -0.5f, 0.0f,	// 右下角
//		-0.5f, -0.5f, 0.0f,	// 左下角
//		-0.5f, 0.5f, 0.0f	// 左上角
//	};
//
//	unsigned int indices[] = { // 注意索引从0开始! 
//		0, 1, 3,	// 第一个三角形
//		1, 2, 3		// 第二个三角形
//	};
//
//	glGenBuffers( 1, &VBO );
//	glGenVertexArrays( 1, &VAO );
//	glBindVertexArray( VAO );
//
//	glBindBuffer( GL_ARRAY_BUFFER, VBO );
//	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices), vertices, GL_STATIC_DRAW );
//
//	glGenBuffers( 1, &EBO );
//	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
//	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );
//	// Create vertex shader
//	char* vertexShaderSource = "#version 330 core \n"
//		"layout (location = 0) in vec3 aPos;\n"
//		"void main()\n"
//		"{ gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}";
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
//	"uniform vec4 ourColor;\n"
//	"void main()\n"
//	"{ FragColor = ourColor;}";
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
//	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
//}