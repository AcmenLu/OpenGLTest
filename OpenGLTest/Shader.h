#ifndef _SHADER_H
#define _SHADER_H

#include "glad/glad.h"
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int mShaderProgram;

	Shader( const char* vertexPath, const char* fragmentPath );
	inline ~Shader( )
		{ }

	void Use( );
	void SetBool( const std::string &name, bool value );
	void SetInt( const std::string &name, int value );
	void SetFloat( const std::string &name, float value );
	void Shader::SetVector3( const std::string &name, float x, float y, float z );
	void Shader::SetVector3( const std::string &name, glm::vec3 vec );
	void SetMatrix4( const std::string &name, float* value, bool transpose = false );
};

#endif