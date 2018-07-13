#pragma once
namespace Acmen
{
class Sprite : public GLRenderObject
{
public:
	GLTexture*		mTexture;
	glm::vec2		mSize;
	glm::mat4		mTransform;

	Sprite( glm::vec2 size );
	Sprite( string& filename );
	~Sprite( );

	_bool CreateShader( );
	_void OnRender( _float elapse );
};
}