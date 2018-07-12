#include "Acmen.h"
#pragma comment( lib, "Common" )
#pragma comment( lib, "Renderer" )
#pragma comment( lib, "Platform" )


namespace Acmen
{
	class Sprite : public GLRenderObject
	{

	public:
		GLTexture*		mTexture;
		glm::vec2		mSize;
		glm::mat4		mTransform;

		inline Sprite( glm::vec2 size )
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
		}

		inline Sprite( string& filename )
		{
			mTexture = new GLTexture( filename );
			mVertices.push_back( Vertex( ) );
			mVertices.push_back( Vertex( glm::vec3( mTexture->GetWidth( ), 0.0f, 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 0.0f ), glm::vec4( ) ) );
			mVertices.push_back( Vertex( glm::vec3( mTexture->GetWidth( ), mTexture->GetHeight( ), 0.0f ), glm::vec3( ), glm::vec2( 1.0f, 1.0f ), glm::vec4( ) ) );
			mVertices.push_back( Vertex( glm::vec3( 0.0f, mTexture->GetHeight( ), 0.0f ), glm::vec3( ), glm::vec2( 0.0f, 1.0f ), glm::vec4( ) ) );

			mIndices.push_back( 0 );
			mIndices.push_back( 1 );
			mIndices.push_back( 2 );
			mIndices.push_back( 0 );
			mIndices.push_back( 2 );
			mIndices.push_back( 3 );
		}

		inline ~Sprite( )
		{
			SAFE_RELESE( mTexture )
		}

		inline _void OnRender( _float elapse )
		{

		}
	};
}



Windows* win;

_void onKeyDown( _dword keycode )
{
	if ( keycode == 32 )
		win->Close( );
}

_void onInited()
{

}
int main( )
{
	win = new Windows( 1000.0f, 700.0f );
	Sprite* spr = new Sprite( string( "resources/textures/window.png" ) );
	Renderer::GetInstance( )->AddToRenderList( spr );
	Application::GetInstance( )->SetKeyDownCallback( onKeyDown );
	win->Run( );
}