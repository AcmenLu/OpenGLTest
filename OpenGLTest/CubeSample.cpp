//#include <glad/glad.h>
//#include "GLFW/glfw3.h"
//#include <iostream>
//#include "Shader.h"
//
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//GLFWwindow* window = nullptr;
//bool InitOpenGL();
//void OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void Render();
//void InitData();
//unsigned int loadImage(char* filename);
//
//unsigned int VBO;
//unsigned int EBO;
//unsigned int VAO;
//unsigned int mTexture;
//unsigned int mTexture2;
//
//Shader* shader;
//
//int main()
//{
//	if (InitOpenGL() == false)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		Render();
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//bool InitOpenGL()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	window = glfwCreateWindow(WIDTH, HEIGHT, "Acmen", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		return false;
//	}
//
//	glfwMakeContextCurrent(window);
//	glfwSetKeyCallback(window, OnKeyCallback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return false;
//	}
//
//	int width, height;
//	glfwGetFramebufferSize( window, &width, &height );
//	glViewport( 0, 0, width, height );
//	glEnable( GL_DEPTH_TEST );
//	InitData( );
//	return true;
//}
//
//void OnKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//void Render()
//{
//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, mTexture);
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, mTexture2);
//
//	glm::mat4 model;
//	glm::mat4 view;
//	glm::mat4 projection;
//	model = glm::rotate( model, glm::radians( -55.0f ), glm::vec3( 1.0f, 0.0f, 0.0f ) );
//	view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//	projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//
//	shader->Use();
//	shader->SetMatrix4("mModel", glm::value_ptr(model), false);
//	shader->SetMatrix4("mView", glm::value_ptr(view), false);
//	shader->SetMatrix4("mProj", glm::value_ptr(projection), false);
//	glBindVertexArray( VAO );
//	glDrawArrays( GL_TRIANGLES, 0, 36 );
//	// glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
//}
//
//void InitData()
//{
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	glGenBuffers(1, &VBO);
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//unsigned int indices[] = {
//	//	0, 1, 3,
//	//	1, 2, 3
//	//};
//	//glGenBuffers(1, &EBO);
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	shader = new Shader("./Shader/coordinatesample.vs", "./Shader/coordinatesample.fs");
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	mTexture = loadImage("texture/container.jpg");
//	mTexture2 = loadImage("texture/awesomeface.png");
//	shader->Use();
//	shader->SetInt("texture1", 0);
//	shader->SetInt("texture2", 1);
//}
//
//unsigned int loadImage(char * filename)
//{
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int width, height, nrChannels;
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		if (nrChannels == 3)
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		else if (nrChannels == 4)
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	stbi_image_free(data);
//	return texture;
//}