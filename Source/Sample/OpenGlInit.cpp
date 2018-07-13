//
//#define GLEW_STATIC
//
//#include <glad/glad.h>
//#include <glfw/glfw3.h>
//
//#pragma comment( lib, "glfw3" )
//#pragma comment( lib, "opengl32" )
//
//int main( )
//{
//	glfwInit( );
//	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
//	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
//	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
//
//	GLFWwindow* mGLFWWindow = glfwCreateWindow( 800, 600, "Acmen", NULL, NULL );
//	if ( mGLFWWindow == NULL )
//	{
//		return 0;
//	}
//
//	glfwMakeContextCurrent( mGLFWWindow );
//	/*GLint err = glGetError( );*/
//
//	if ( !gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ) )
//	{
//		return 0;
//	}
//
//	GLint errerr = glGetError( );
//	return 0;
//}