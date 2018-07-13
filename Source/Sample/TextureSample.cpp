#include "Acmen.h"
#pragma comment( lib, "Common" )
#pragma comment( lib, "Renderer" )
#pragma comment( lib, "Platform" )

Windows* win;

_void onKeyDown( _dword keycode )
{
	if ( keycode == 32 )
		win->Close( );
}

_void onLaunched()
{
	Sprite* spr = new Sprite( string( "resources/textures/window.png" ) );
	Renderer::GetInstance( )->AddToRenderList( spr );
}

int main( )
{
	Application::GetInstance( )->SetKeyDownCallback( onKeyDown );
	Application::GetInstance( )->SetLaunchedCallback( onLaunched );
	win = new Windows( 1000.0f, 700.0f );
	win->Run( );
}