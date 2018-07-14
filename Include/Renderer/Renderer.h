#pragma once

namespace Acmen
{

class Renderer
{
public:
	static Renderer* sRenderer;
	static Renderer* GetInstance( );

public:
	vector<RenderObject*>	mRenderList;
	Camera*					mCamera;
	glm::vec2				mSize;
	glm::mat4				mProjection3D;
	glm::mat4				mProjection2D;

public:
	inline Renderer( );
	inline ~Renderer( );

	_void Resize( _dword width, _dword height );
	_void AddToRenderList( RenderObject* object );
	_void RemoveFromRenderList( RenderObject* object );
	_void ClearRenderList( );
	_void OnRender( _float elapse );
};


}