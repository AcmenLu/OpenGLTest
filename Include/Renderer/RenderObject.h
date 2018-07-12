#pragma once

namespace Acmen
{

class RenderObject
{
protected:
	glm::mat4		mTransform;

public:
	inline RenderObject( ) : mTransform( glm::mat4( ) ){ }
	inline ~RenderObject( ) { }

	virtual glm::mat4& GetTransform( )
		{ return mTransform; }
	virtual _void SetTransform( glm::mat4& mat4 )
		{ mTransform = mat4; }

	virtual _void OnRender( _float elapse ) = 0;
};

}