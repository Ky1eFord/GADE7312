#include <GADE7311_TASK_1_FULL_SEND/Library Extenstion Holders/glew-2.1.0/include/GL/glew.h>
#include"Library Extenstion Holders/glm-master/glm/glm.hpp"

#include <iostream>

class ChessBoard
{

private:

	GLuint vertex_array_id = 0;

	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"layout (location = 1) in vec3 color;\n"
		"out vec4 ourcolor;\n"
		"uniform mat4 MVP;\n"
		"void main()\n"
		"{\n"
		"gl_Position = MVP * vec4(position.x, position.y, position.z, 1.0);\n"
		"ourcolor = vec4(color, 1.0);\n"
		"}\0";

	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"out vec4 color;\n"
		"in vec4 ourcolor;\n"
		"void main()\n"
		"{\n"
		"color = ourcolor;\n"
		"}\n\0";

	GLuint VBO[86], VAO[86];
	GLuint shaderProgramgl;
	int camIndex_ = 0;

public:

	// Camera Positions
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraPos1 = glm::vec3(1.0f, 1.0f, 2.0f);
	glm::vec3 cameraPos2 = glm::vec3(0.0f, 2.0f, 3.0f);

	glm::vec3 camPositions_[3] = {
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(1.0f, 1.0f, 2.0f),
		glm::vec3(0.0f, 2.0f, 3.0f)
	};

	GLuint getShaderProgram();

	GLuint* getVertexArrayIds();

	void setNewCameraPos(int process_counter);

	glm::vec3 getCameraPos();

	void create1();

	void ImplementShaders();

	void Create2();

};

