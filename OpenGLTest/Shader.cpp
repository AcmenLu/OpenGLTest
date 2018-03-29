#include "Shader.h"

Shader::Shader( const GLchar* vertexPath, const GLchar* fragmentPath )
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	vShaderFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );
	fShaderFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );

	try
	{
		vShaderFile.open( vertexPath );
		fShaderFile.open( fragmentPath );
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf( );
		fShaderStream << fShaderFile.rdbuf( );

		vShaderFile.close( );
		fShaderFile.close( );

		vertexCode = vShaderStream.str( );
		fragmentCode = fShaderStream.str( );
	}
	catch( std::ifstream::failure e )
	{
		 std::cout << "[ERROR]: Read file failed!" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str( );
	const char* fShaderCode = fragmentCode.c_str( );

	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	vertex = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertex, 1, &vShaderCode, NULL );
	glCompileShader( vertex );

	glGetShaderiv( vertex, GL_COMPILE_STATUS, &success );
	if ( !success )
	{
		glGetShaderInfoLog( vertex, 512, NULL, infoLog );
		std::cout << "[ERROR]: Compile vertex shader failed:\n" << infoLog << std::endl;
	}

	fragment = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( fragment, 1, &fShaderCode, NULL );
	glCompileShader( fragment );
	glGetShaderiv( fragment, GL_COMPILE_STATUS, &success );
	if ( !success )
	{
		glGetShaderInfoLog( fragment, 512, NULL, infoLog );
		std::cout << "[ERROR]: Compile fragment shader failed!\n" << infoLog << std::endl;
	}

	mShaderProgram = glCreateProgram( );
	glAttachShader( mShaderProgram, vertex );
	glAttachShader( mShaderProgram, fragment );
	glLinkProgram( mShaderProgram );

	glGetProgramiv( mShaderProgram, GL_LINK_STATUS, &success );
	if ( !success )
	{
		glGetProgramInfoLog( mShaderProgram, 512, NULL, infoLog );
		std::cout << "[ERROR]:Link progrma failed!\n" << infoLog << std::endl;
	}

	glDeleteShader( vertex );
	glDeleteShader( fragment );
}

void Shader::Use( )
{
	glUseProgram( mShaderProgram );
}

void Shader::SetBool( const std::string &name, bool value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, int( value ) );
}

void Shader::SetInt( const std::string &name, int value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, value );
}

void Shader::SetFloat( const std::string &name, float value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, value );
}