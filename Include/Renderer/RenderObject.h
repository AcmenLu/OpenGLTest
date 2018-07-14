#pragma once

namespace Acmen
{
class Renderer;
class RenderObject
{
public:
	inline RenderObject( ){ }
	inline ~RenderObject( ) { }
	virtual _void OnRender( Renderer* renderer, _float elapse ) = 0;
};

}