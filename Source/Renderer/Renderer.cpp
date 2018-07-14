#include "Acmen.h"

Renderer* Renderer::sRenderer = _null;
Renderer* Renderer::GetInstance( )
{
	if ( sRenderer == _null )
		sRenderer = new Renderer( );

	return sRenderer;
}

Renderer::Renderer( ):mSize( glm::vec2( 0, 0 ) )
{
	mCamera = new Camera( );
	if ( sRenderer == _null )
		sRenderer = this;
}

Renderer::~Renderer( )
{
	SAFE_RELESE( mCamera );
}

_void Renderer::Resize( _dword width, _dword height )
{
	mSize = glm::vec2( width, height );
	mProjection3D = glm::perspectiveRH( glm::radians( 45.0f ), (_float)width / (_float)height, 0.1f, 100.0f );
	mProjection2D = glm::ortho(0.0f, (_float)width, (_float)height, 0.0f, 0.0f, 100.0f );
}

_void Renderer::AddToRenderList( RenderObject* object )
{
	vector<RenderObject*>::iterator iter = find( mRenderList.begin( ), mRenderList.end( ), object );
	if ( iter == mRenderList.end( ) )
		mRenderList.push_back( object );
}

_void Renderer::RemoveFromRenderList( RenderObject* object )
{
	vector<RenderObject*>::iterator iter = find( mRenderList.begin( ), mRenderList.end( ), object );
	if ( iter != mRenderList.end( ) )
		mRenderList.erase( iter );
}

_void Renderer::ClearRenderList( )
{
	mRenderList.clear( );
}

_void Renderer::OnRender( _float elapse )
{
	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
		mRenderList[i]->OnRender( this, elapse );

	//ClearRenderList( );
}