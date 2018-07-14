#include "Acmen.h"

Sprite::Sprite( glm::vec2 size )
	:mTexture( _null ), mSize( size ),mTransform( glm::mat4( ) )
{
	mVertices.push_back( Vertex( ) );
	mVertices.push_back( Vertex( glm::vec3( size.x, 0.0f, 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 0.0f ), glm::vec4( ) ) );
	mVertices.push_back( Vertex( glm::vec3( size.x, size.y, 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 1.0f ), glm::vec4( ) ) );
	mVertices.push_back( Vertex( glm::vec3( 0.0f, size.y, 0.0f ), glm::vec3( ), glm::vec2( 0.0f, 1.0f ), glm::vec4( ) ) );

	mIndices.push_back( 0 );
	mIndices.push_back( 1 );
	mIndices.push_back( 2 );
	mIndices.push_back( 0 );
	mIndices.push_back( 2 );
	mIndices.push_back( 3 );
	mShaderParms = ShaderParms( );
	mShaderParms.UseNormal = _false;
	mShaderParms.UseColor = _false;
	mShaderParms.UseTexCoord = _true;
	CreateGeometry( );
	CreateShader( );
}

Sprite::Sprite( string& filename )
{
	mTexture = new GLTexture( filename );
	mVertices.push_back( Vertex( ) );
	mVertices.push_back( Vertex( glm::vec3( mTexture->GetWidth( ), 0.0f, 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 0.0f ), glm::vec4( ) ) );
	mVertices.push_back( Vertex( glm::vec3( mTexture->GetWidth( ), mTexture->GetHeight( ), 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 1.0f ), glm::vec4( ) ) );
	mVertices.push_back( Vertex( glm::vec3( 0.0f, mTexture->GetHeight( ), 0.0f ), glm::vec3( ), glm::vec2( 0.0f, 1.0f ), glm::vec4( ) ) );

	//mVertices.push_back( Vertex( glm::vec3(0.5f,  0.5f, 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 1.0f ), glm::vec4( ) ) );
	//mVertices.push_back( Vertex( glm::vec3(0.5f, -0.5f, 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 0.0f ), glm::vec4( ) ) );
	//mVertices.push_back( Vertex( glm::vec3(-0.5f, -0.5f, 0.0f ), glm::vec3( ), glm::vec2( 0.0f, 0.0f ), glm::vec4( ) ) );
	//mVertices.push_back( Vertex( glm::vec3(-0.5f,  0.5f, 0.0f ), glm::vec3( ), glm::vec2( 0.0f, 1.0f ), glm::vec4( ) ) );

	mIndices.push_back( 0 );
	mIndices.push_back( 1 );
	mIndices.push_back( 2 );
	mIndices.push_back( 0 );
	mIndices.push_back( 2 );
	mIndices.push_back( 3 );
	mShaderParms = ShaderParms( );
	mShaderParms.UseNormal = _false;
	mShaderParms.UseColor = _false;
	mShaderParms.UseTexCoord = _true;
	CreateGeometry( );
	CreateShader( );
}

Sprite::~Sprite( )
{
	SAFE_RELESE( mTexture )
}

_bool Sprite::CreateShader( )
{
	string vsstr = "#version 330 core\n" \
		"layout (location = 0) in vec3 position;\n" \
		"layout (location = 1) in vec2 texcoord;\n" \
		"uniform mat4 projection;\n" \
		"uniform mat4 model;\n" \
		"out vec2 TexCoord;\n" \
		"void main()\n" \
		"{\n" \
		"TexCoord = texcoord;\n" \
		"gl_Position = projection * model * vec4(position, 1.0);\n" \
		"}";

	string psstr = "#version 330 core\n" \
		"in vec2 TexCoord;" \
		"out vec4 FragColor;\n" \
		"uniform sampler2D texture0;\n" \
		"void main()\n" \
		"{\n" \
		"FragColor = texture(texture0, TexCoord);\n" \
		"}\n";
	mShader = new Shader( vsstr, psstr );
	return _true;
}

_void Sprite::OnRender( Renderer* renderer, _float elapse )
{
	if ( mShader == _null )
		return;

	mShader->Use( );
	//SetUniform( );
	glBindVertexArray( mVAO );
	GLuint err = glGetError( );
	if ( mTexture->GetGLId( ) > 0 )
	{
		mShader->SetInt( "texture0", 0 );
		mShader->SetMatrix4( "projection", renderer->mProjection2D, _false );
		mShader->SetMatrix4( "model", mTransform, _false );
		glActiveTexture( GL_TEXTURE0 );
		glBindTexture( GL_TEXTURE_2D, mTexture->GetGLId( ) );
	}

	if ( mIndices.size( ) > 0 )
		glDrawElements( GL_TRIANGLES, mIndices.size( ), GL_UNSIGNED_INT, 0 );
	else
		glDrawArrays( GL_TRIANGLES, 0, mVertices.size( ) );

	glBindVertexArray( 0 );
}