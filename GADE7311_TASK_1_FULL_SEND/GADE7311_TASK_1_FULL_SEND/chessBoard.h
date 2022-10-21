#include <GL/glew.h>
#include "glm.hpp"
#include <iostream>

class ChessBoard
{

private:

	GLuint vertex_array_id = 0;

	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		//"layout (location = 1) in vec3 color;\n"
		"layout (location = 2) in vec2 texCoord;\n"
		//"out vec4 ourcolor;\n"
		"out vec2 TexCoord;\n" //
		"uniform mat4 MVP;\n"
		//"uniform mat4 model;\n"
		//"uniform mat4 view;\n"
		//"uniform mat4 projection;\n"
		"void main()\n"
		"{\n"
		"gl_Position = MVP * vec4(position.x, position.y, position.z, 1.0);\n"
		//"gl_Position = projection * view * model * vec4(position, 1.0f);\n"
		//"ourcolor = vec4(color, 1.0);\n"
		"TexCoord = vec2(texCoord.x, 1.0f - texCoord.y);\n"
		"}\0";

	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"in vec2 TexCoord; \n"
		"out vec4 color;\n"
		//"in vec4 ourcolor;\n"
		//"out vec2 TexCoord;\n"                       //
		"uniform sampler2D mytexture;\n"             //
		"void main()\n"
		"{\n"
		"color = texture(mytexture, TexCoord);\n"
		"}\n\0";

	GLuint VBO[86], VAO[86];
	GLuint shaderProgram;
	int cam_index = 0;

public:

	// Camera Positions
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraPos1 = glm::vec3(2.0f, 0.0f, 3.0f);
	glm::vec3 cameraPos2 = glm::vec3(2.0f, 2.0f, 3.0f);

	glm::vec3 cam_positions[3] = {
		glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(2.0f, 0.0f, 3.0f),
		glm::vec3(2.0f, 2.0f, 3.0f)
	};

	GLuint getShaderProgram();

	GLuint* getVertexArrayIds();

	void setNewCameraPosition(int process_counter);

	glm::vec3 getCameraPosition();

	void generate1();

	void compileShaders();

	void generate2();

};

