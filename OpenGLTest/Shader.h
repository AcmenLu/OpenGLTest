#ifndef _SHADER_H
#define _SHADER_H

#include "glad/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int mShaderProgram;

	Shader( const GLchar* vertexPath, const GLchar* fragmentPath );
	~Shader();

	void Use( );
	void SetBool( const std::string &name, bool value );
	void SetInt( const std::string &name, int value );
	void SetFloat( const std::string &name, float value );
	void SetMatrix4( const std::string &name, float* value, bool transpose = GL_FALSE );
};

#endif