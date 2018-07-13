#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <glad/glad.h>
#include <glfw/glfw3.h>
// Math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Common
#include "Common/Typedef.h"
#include "Common/Trace.h"
#include "Common/Math.h"
#include "Common/Timer.h"
//#include "Common/glm::vec2.h"
//#include "Common/Vector3.h"
//#include "Common/glm::vec4.h"
//#include "Common/glm::mat4.h"
#include "Common/Camera.h"
#include "Common/Texture.h"
#include "Common/String.h"

// Renderer
#include "Renderer/Shader.h"
#include "Renderer/RenderObject.h"
#include "Renderer/Renderer.h"
#include "Renderer/GLRenderObject.h"
#include "Renderer/GLTexture.h"
#include "Renderer/Sprite.h"

// Platform
//#include "Platform/System.h"
#include "Platform/Application.h"
#include "Platform/Windows.h"

using namespace Acmen;
using namespace std;