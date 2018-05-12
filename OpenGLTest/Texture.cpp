#include "Texture.h"

unsigned int Texture::LoadTexture( const char* filename )
{
	unsigned int texture;
	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load( true );
	unsigned char* data = stbi_load( filename, &width, &height, &nrChannels, 0 );
	if ( data )
	{
		if ( nrChannels == 3 )
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data );
		else if (nrChannels == 4 )
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
	
		glGenerateMipmap( GL_TEXTURE_2D );
	}

	stbi_image_free( data );
	return texture;
}