#include "Acmen.h"

GLRenderObject::GLRenderObject( vector< Vertex > vertices, vector< _dword > indices )
	:mVertices( vector< Vertex >( ) ), mIndices( vector< _dword >( ) ),
	mShader( _null ), mVAO( 0 ), mVBO( 0 ), mEBO( 0 ), mShaderParms( ShaderParms( ) )
{
	if ( vertices.size( ) > 0 )
		mVertices.assign( vertices.begin( ), vertices.end( ) );

	if ( indices.size( ) > 0 )
		mIndices.assign( indices.begin( ), indices.end( ) );
}

GLRenderObject::~GLRenderObject( )
{
	if ( mVBO > 0 )
		glDeleteBuffers( 1, &mVBO );

	if ( mEBO > 0 )
		glDeleteBuffers( 1, &mEBO );

	if ( mVAO > 0 )
		glDeleteVertexArrays( 1, &mVAO );

	mVertices.clear( );
	mIndices.clear( );
	mVBO = 0;
	mEBO = 0;
	mVAO = 0;

	SAFE_RELESE( mShader )
}

_bool GLRenderObject::CreateGeometry( )
{
	if ( mVertices.size( ) <= 0 )
		return _false;

	glGenVertexArrays( 1, &mVAO );
	glBindVertexArray( mVAO );

	glGenBuffers( 1, &mVBO );
	glBindBuffer( GL_ARRAY_BUFFER, mVBO );
	glBufferData( GL_ARRAY_BUFFER, mVertices.size( ) * sizeof( Vertex ), &mVertices[0], GL_STATIC_DRAW );

	if ( mIndices.size( ) > 0 )
	{
		glGenBuffers( 1, &mEBO );
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mEBO );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, mIndices.size( ) * sizeof( _dword ), &mIndices[0], GL_STATIC_DRAW );
	}

	_dword location = 0;
	// Position
	glVertexAttribPointer( location, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)0 );
	glEnableVertexAttribArray( location );
	location++;

	// Normal
	if ( mShaderParms.UseNormal )
	{
		glVertexAttribPointer( location, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)offsetof( Vertex, Normal ) );
		glEnableVertexAttribArray( location );
		location++;
	}

	// Texcoord
	if ( mShaderParms.UseNormal )
	{
		glVertexAttribPointer( location, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)offsetof( Vertex, TexCoord ) );
		glEnableVertexAttribArray( location );
		location++;
	}

	if ( mShaderParms.UseColor )
	{
		glVertexAttribPointer( location, 4, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)offsetof( Vertex, Color ) );
		glEnableVertexAttribArray( location );
		location++;
	}

	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
	return _true;
}