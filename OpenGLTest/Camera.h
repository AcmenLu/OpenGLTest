
#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
	glm::mat4 mTransform;

	Camera();
	~Camera();

private:
	glm::vec3 mPosition;
	glm::vec3 mTarget;
	glm::vec3 mUp;
};

#endif