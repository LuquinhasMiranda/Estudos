#include "../include/Render/OGLHandler.hpp"

#include "../include/Render/ShaderClass.h"
#include "../include/Render/VBO.h"
#include "../include/Render/VAO.h"
#include "../include/Render/EBO.h"

OGLHandler::OGLHandler(void (*_GameLoop)(int), int _width, int _height, char* _window_name){
   GameLoop = _GameLoop;
   width = _width;
   height = _height;
   window_name = _window_name;
}

int OGLHandler::init() {
   //  GLFW SETUP DO OPENGL
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   // CRIA JANELA
   GLFWwindow* window = glfwCreateWindow(width,height, window_name, NULL, NULL);
   if (window == NULL) {
      printf("Erro ao criar janela GLFW!\n");
      glfwTerminate();
      return -1;
   }
   glfwMakeContextCurrent(window);
   gladLoadGL();
   

   GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f, // DL
		 0.5f, -0.5f, 0.0f, // DR
		-0.5f,  0.5f, 0.0f, // UL
		 0.5f,  0.5f, 0.0f  // UR
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 1, 3,
		3, 2, 0
	};

   // SHADER
   Shader shaderProgram("../../src/Shaders/default.vert", "../../src/Shaders/default.frag");

   // Create reference for VAO VBO and EBO
   VAO VAO1;
   VAO1.Bind();

   VBO VBO1(vertices, sizeof(vertices));
   EBO EBO1(indices,  sizeof(indices ));

   VAO1.LinkVBO(VBO1, 0);
   VAO1.Unbind();
   VBO1.Unbind();
   EBO1.Unbind();

   // FUNCAO LOOP
   while (!glfwWindowShouldClose(window)) 
   {
      glViewport(0,0,width,height);
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
   }

   // CLEARING
   VAO1.Delete();
   VBO1.Delete();
   EBO1.Delete();
   //shaderProgram.Delete();
   glfwDestroyWindow(window);
   glfwTerminate();

   return 0;
}