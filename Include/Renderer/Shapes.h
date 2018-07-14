#pragma once

namespace Acmen
{
class Shapes
{
public:
	Shapes();
	~Shapes();

	glm::mat4		mTransform;

	_bool CreateShader( );
	_void OnRender( Renderer* renderer, _float elapse );

};

}