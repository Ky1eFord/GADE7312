#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// SOIL2
#include "SOIL2/SOIL2.h"

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//header files
#include "Camera.h" 
#include "Shader.h"

// Window Dimensions
const GLint WIDTH = 1080, HEIGHT = 720;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Declaring our methods
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
void MouseCallback(GLFWwindow* window, double xPos, double yPos); // Get mouse pos in order to hide it
void cameraMovement(GLFWwindow* window); // Move camera

// Setting the values for the camera's position
Camera camera(glm::vec3(0.0f, 2.0f, 8.0f), glm::vec3(0.0f, 1.0f, 0.0f), -128.1f, -42.4f);
GLfloat lastX = WIDTH / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;

//bool variables and values
bool keys[1024]; // Array of 1024 different types of keys
bool firstMouse = true;
bool isCameraLocked = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

//texture methods

GLuint CreateTexture(GLuint texture, const char* img, int width, int height);
GLuint CreateSkyboxTexture(GLuint texture, vector<std::string> faces, int width, int height);

int i = 0;

// MAIN FUNCTION for MAIN GAME LOOP
int main()
{
	// Initialize GLFW
	glfwInit();

	// Set all required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create our Window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GADE7311_POE_by_FullSend", nullptr, nullptr);

	// Getting and setting the previously set screen resolution
	glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

	// Checking if window was created and was created successfully
	if (window == nullptr)
	{
		cout << "Failed to create window." << endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	// Set the required callback functions ***
	glfwSetKeyCallback(window, KeyCallback);
	glfwSetCursorPosCallback(window, MouseCallback);
	glfwSetScrollCallback(window, ScrollCallback);

	// Center cursor to window and Hide the cursor for a more immersive experience ***
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Enable GLEW
	glewExperimental = GL_TRUE;

	// Initialize GLEW
	if (GLEW_OK != glewInit())
	{
		cout << "Failed to initialise GLEW." << endl;
		return EXIT_FAILURE;
	}

	// Setup OpenGL viewport
	// Define viewport dimensions
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Enable depth in the project
	glEnable(GL_DEPTH_TEST);

	int widthTexture = 0, heightTexture = 0;

	 //Builds chess board shader 
	//implemented pragma regions to organise code better
#pragma region chessboard shader
		
	Shader chessBoardShader("chessBoardVert.vs", "chessBoardFrag.frag");

	// Vertex data that conatins position and texture for our cube
	GLfloat chessBoardVerts[] =
	{
		//Positions				//Texture Coords
		-0.5f, 0.0f, -0.5f,		0.0f, 0.0f,
		0.5f, 0.0f, -0.5f,		1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 0.0f, // Left side of cube

		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		0.5f, 0.0f,  0.5f,		1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f,
		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f, // Right side of cube

		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, // Back side of cube

		0.5f,  0.5f,  0.5f,		1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 0.0f, // Front side of cube

		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		0.5f, 0.0f, -0.5f,		1.0f, 1.0f,
		0.5f, 0.0f,  0.5f,		1.0f, 0.0f,
		0.5f, 0.0f,  0.5f,		1.0f, 0.0f,
		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f, // Bottom side of cube

		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f // Top side of cube
	};

	// Positions of the different cubes in the same row
	glm::vec3 cubePos[] =
	{
		// Row creation for chessboard tiles
		glm::vec3(-3.0f, 0.0f, 4.0f),
		glm::vec3(-2.0f, 0.0f, 4.0f),
		glm::vec3(-1.0f, 0.0f, 4.0f),
		glm::vec3(0.0f, 0.0f, 4.0f),
		glm::vec3(1.0f, 0.0f, 4.0f),
		glm::vec3(2.0f, 0.0f, 4.0f),
		glm::vec3(3.0f, 0.0f, 4.0f),
		glm::vec3(4.0f, 0.0f, 4.0f)
	};

	// Generate the vertex arrays and vertex buffers and save them into variables
	GLuint VBA_Board, VOA_Board;
	glGenVertexArrays(1, &VOA_Board);
	glGenBuffers(1, &VBA_Board);

	// Bind the vertex array object
	glBindVertexArray(VOA_Board);

	// Bind and set the vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, VBA_Board);
	glBufferData(GL_ARRAY_BUFFER, sizeof(chessBoardVerts), chessBoardVerts, GL_STATIC_DRAW);

	// Create the vertex pointer and enable the vertex array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Texture coordinate attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	// Unbinding the vertex array
	glBindVertexArray(0);

	// Create and load white texture
#pragma region white texture
	GLuint setWhiteTexture, setBlackTexture;
	int widthB, heightB;
	glGenTextures(1, &setWhiteTexture);
	glBindTexture(GL_TEXTURE_2D, setWhiteTexture);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Actual texture loading code
	unsigned char* setWhiteTile = SOIL_load_image("Textures/whiteMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	// Specify 2D texture image
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, setWhiteTile);

	// Generate mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(setWhiteTile);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

	// Create and load black texture
#pragma region black texture

	glGenTextures(1, &setBlackTexture);
	glBindTexture(GL_TEXTURE_2D, setBlackTexture);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Actual texture loading code
	unsigned char* setBlackTile = SOIL_load_image("Textures/blackMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	// Specify 2D texture image
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, setBlackTile);

	// Generate mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(setBlackTile);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma endregion

	//Builds the border for the Chessboard
#pragma region chessboard border shader

	//Following the same coding principles used to generate the chessboard
	Shader borderShader("chessBoardVert.vs", "chessBoardFrag.frag");

	GLfloat borderVerts[] =
	{
		-0.5f, 0.0f, -0.5f,		0.0f, 0.0f,
		0.5f, 0.0f, -0.5f,		1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 0.0f, 

		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		0.5f, 0.0f,  0.5f,		1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f,
		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f, 

		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 

		0.5f,  0.5f,  0.5f,		1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 0.0f, 

		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f,
		0.5f, 0.0f, -0.5f,		1.0f, 1.0f,
		0.5f, 0.0f,  0.5f,		1.0f, 0.0f,
		0.5f, 0.0f,  0.5f,		1.0f, 0.0f,
		-0.5f, 0.0f,  0.5f,		0.0f, 0.0f,
		-0.5f, 0.0f, -0.5f,		0.0f, 1.0f, 

		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,		1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,		1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f 
	};

	// Positions of the border around the chessboard
	glm::vec3 cubeBorderPos[] =
	{
		// Creating the border
		glm::vec3(-4.0f, 0.0f, 5.0f),			//Border
		glm::vec3(-3.0f, 0.0f, 5.0f),
		glm::vec3(-2.0f, 0.0f, 5.0f),
		glm::vec3(-1.0f, 0.0f, 5.0f),
		glm::vec3(0.0f, 0.0f, 5.0f),
		glm::vec3(1.0f, 0.0f, 5.0f),
		glm::vec3(2.0f, 0.0f, 5.0f),
		glm::vec3(3.0f, 0.0f, 5.0f),
		glm::vec3(4.0f, 0.0f, 5.0f), 
		glm::vec3(5.0f, 0.0f, 5.0f)			//Border
	};

	GLuint VBA_Boarder, VOA_Boarder;
	glGenVertexArrays(1, &VOA_Boarder);
	glGenBuffers(1, &VBA_Boarder);

	glBindVertexArray(VOA_Boarder);

	glBindBuffer(GL_ARRAY_BUFFER, VBA_Boarder);
	glBufferData(GL_ARRAY_BUFFER, sizeof(borderVerts), borderVerts, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	
	glBindVertexArray(0);

	GLuint borderTexture = 0;
	borderTexture = CreateTexture(borderTexture, "Textures/Border.png", widthTexture, heightTexture);

#pragma endregion

	//Builds height map shader
#pragma region Height map shader

	Shader heightMapShader("heightMapVert.vs", "heightMapFrag.frag");

	int width, height, nrChannels;

	unsigned char* data = SOIL_load_image("resource folder/heightMap.png", &width, &height, &nrChannels, 0); //initializing heightmap from our heightmap image

	if (data)
	{
		cout << "Loaded heightmap of size " << height << " x " << width << endl;
	}
	else
	{
		cout << "Failed to load texture" << endl;
	}

	vector<GLfloat> vertices; 

	GLfloat yScale = 0.05f;	//64.0f / 256.0f; //normalize the height map data and scale it to the desired height
	GLfloat yShift = 12.0f; //16.0f; // translate the elevations to our final desired range
	int rez = 1;
	GLuint bytePerPixel = nrChannels;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			unsigned char* pixelOffset = data + (j + width * i) * bytePerPixel;
			unsigned char y = pixelOffset[0];

			// vertex
			vertices.push_back(-height / 2.0f + height * i / (float)height); // vx
			vertices.push_back((int)y * yScale - yShift); // vy
			vertices.push_back(-width / 2.0f + width * j / (float)width); // vz
		}
	}
	cout << "Loaded " << vertices.size() / 3 << " vertices" << endl;
	SOIL_free_image_data(data);

	vector<GLuint> indices;
	for (int i = 0; i < height - 1; i += rez)
	{
		for (int j = 0; j < width; j += rez)
		{
			for (int k = 0; k < 2; k++)
			{
				indices.push_back(j + width * (i + k * rez));
			}
		}
	}
	cout << "Loaded " << indices.size() << " indices" << endl;

	const int numStrips = (height - 1) / rez;
	const int numTrisPerStrip = (width / rez) * 2 - 2;
	cout << "Created lattice of " << numStrips << " strips with " << numTrisPerStrip << " triangles each" << endl;
	cout << "Created " << numStrips * numTrisPerStrip << " triangles total" << endl;

	// Generate the vertex arrays, vertex buffers and index buffers and save them into variables
	unsigned int VAO, VBO, IBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Texture attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned), &indices[0], GL_STATIC_DRAW);

	GLuint heightMapTexture = 0;
	heightMapTexture = CreateTexture(heightMapTexture, "Textures/HeightTexture.png", widthTexture, heightTexture);



#pragma endregion

	//Builds ChessPiece Pawn
#pragma region Pawn

	Shader ourShaderPawn("chessBoardVert.vs", "chessBoardFrag.frag");

	// Vertex data for our pawn piece
	GLfloat verticesPawn[11430];

	// Reads the vertex information from the text file 
	ifstream myFile("Pawn.txt");
	i = 0;

	if (myFile.is_open())
	{
		string line;

		while (!myFile.eof())
		{
			getline(myFile, line, ' ');
			verticesPawn[i] = stof(line);
			i++;
			getline(myFile, line, ' ');
			verticesPawn[i] = stof(line);
			i++;
			getline(myFile, line, '\n');
			verticesPawn[i] = stof(line);
			i++;
		}
		myFile.close();
	}
	else
	{
		cout << "Can't open the file";
	}

	// Placing the pawns onto the chess board
	glm::vec3 pawnPositions[] =
	{
		// White chess pieces
		glm::vec3(-3.0f, 0.5f, 3.0f),
		glm::vec3(-2.0f, 0.5f, 3.0f),
		glm::vec3(-1.0f, 0.5f, 3.0f),
		glm::vec3(0.0f, 0.5f, 3.0f),
		glm::vec3(1.0f, 0.5f, 3.0f),
		glm::vec3(2.0f, 0.5f, 3.0f),
		glm::vec3(3.0f, 0.5f, 3.0f),
		glm::vec3(4.0f, 0.5f, 3.0f),

		// Black chess pieces
		glm::vec3(-3.0f, 0.5f, -2.0f),
		glm::vec3(-2.0f, 0.5f, -2.0f),
		glm::vec3(-1.0f, 0.5f, -2.0f),
		glm::vec3(0.0f, 0.5f, -2.0f),
		glm::vec3(1.0f, 0.5f, -2.0f),
		glm::vec3(2.0f, 0.5f, -2.0f),
		glm::vec3(3.0f, 0.5f, -2.0f),
		glm::vec3(4.0f, 0.5f, -2.0f),
	};

	// Generate the vertex arrays and vertex buffers and save them into variables
	GLuint VBA_Pawn, VOA_Pawn;
	glGenVertexArrays(1, &VOA_Pawn);
	glGenBuffers(1, &VBA_Pawn);

	// Bind the vertex array for the object
	glBindVertexArray(VOA_Pawn);

	// Bind and set the vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, VBA_Pawn);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPawn), verticesPawn, GL_STATIC_DRAW);

	// Create the vertex pointer and the vertex array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Texture coordinate attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	// Unbind the vertex array
	glBindVertexArray(0);

	// Chess Piece Pawn texture variables
	GLuint pawnTextureW, pawnTextureB;
	int widthPawn, heightPawn;

#pragma region Pawn Texture White
	// Create and load White texture
	glGenTextures(1, &pawnTextureW);
	glBindTexture(GL_TEXTURE_2D, pawnTextureW);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Actual texture loading code
	unsigned char* pawnImageW = SOIL_load_image("Textures/whiteMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	// Specify the 2D texture image
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, pawnImageW);

	// Generate mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(pawnImageW);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma region Pawn Texture Black
	// Create and load Black texture
	glGenTextures(1, &pawnTextureB);
	glBindTexture(GL_TEXTURE_2D, pawnTextureB);

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Actual texture loading code
	unsigned char* pawnImageB = SOIL_load_image("Textures/blackMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	// Specify the 2D texture image
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, pawnImageB);

	// Generate mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(pawnImageB);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion
#pragma endregion

	//Builds ChessPiece Rook
#pragma region Rook

	Shader ourShaderRook("chessBoardVert.vs", "chessBoardFrag.frag");

	GLfloat rookVerts[3780];

	ifstream myFileRook("Rook.txt");
	i = 0;

	if (myFileRook.is_open())
	{
		string line;

		while (!myFileRook.eof())
		{
			getline(myFileRook, line, ' ');
			rookVerts[i] = stof(line);
			i++;
			getline(myFileRook, line, ' ');
			rookVerts[i] = stof(line);
			i++;
			getline(myFileRook, line, '\n');
			rookVerts[i] = stof(line);
			i++;
		}
		myFileRook.close();
	}
	else
	{
		cout << "Can't open the file";
	}

	glm::vec3 rookPos[] =
	{
		// White chess pieces
		glm::vec3(-3.0f, 0.5f, 4.0f),
		glm::vec3(4.0f, 0.5f, 4.0f),

		// Black chess pieces
		glm::vec3(-3.0f, 0.5f, -3.0f),
		glm::vec3(4.0f, 0.5f, -3.0f),
	};

	GLuint VBA_Rook, VOA_Rook;
	glGenVertexArrays(1, &VOA_Rook);
	glGenBuffers(1, &VBA_Rook);

	glBindVertexArray(VOA_Rook);

	glBindBuffer(GL_ARRAY_BUFFER, VBA_Rook);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rookVerts), rookVerts, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	GLuint rookTextureW, rookTextureB;
	int widthRook, heightRook;

#pragma region Rook Texture White
	glGenTextures(1, &rookTextureW);
	glBindTexture(GL_TEXTURE_2D, rookTextureW);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* rookImageW = SOIL_load_image("Textures/whiteMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, rookImageW);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(rookImageW);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma region Rook Texture Black
	glGenTextures(1, &rookTextureB);
	glBindTexture(GL_TEXTURE_2D, rookTextureB);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* rookImageB = SOIL_load_image("Textures/blackMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, rookImageB);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(rookImageB);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma endregion 

	//Builds ChessPiece Knight
#pragma region knight

	Shader ourShaderKnight("chessBoardVert.vs", "chessBoardFrag.frag");

	GLfloat knightVerts[4014];

	ifstream myFileKnight("Knight.txt");
	i = 0;

	if (myFileKnight.is_open())
	{
		string line;

		while (!myFileKnight.eof())
		{
			getline(myFileKnight, line, ' ');
			knightVerts[i] = stof(line);
			i++;
			getline(myFileKnight, line, ' ');
			knightVerts[i] = stof(line);
			i++;
			getline(myFileKnight, line, '\n');
			knightVerts[i] = stof(line);
			i++;
		}
		myFileKnight.close();
	}
	else
	{
		cout << "Can't open the file";
	}

	glm::vec3 knightPos[] =
	{
		// Black chess pieces
		glm::vec3(3.0f, 0.5f, 4.0f),
		glm::vec3(-2.0f, 0.5f, 4.0f),

		// White chess pieces
		glm::vec3(-2.0f, 0.5f, -3.0f),
		glm::vec3(3.0f, 0.5f, -3.0f),
	};

	GLuint VBA_Knight, VOA_Knight;
	glGenVertexArrays(1, &VOA_Knight);
	glGenBuffers(1, &VBA_Knight);

	glBindVertexArray(VOA_Knight);

	glBindBuffer(GL_ARRAY_BUFFER, VBA_Knight);
	glBufferData(GL_ARRAY_BUFFER, sizeof(knightVerts), knightVerts, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	GLuint knightTextureW, knightTextureB;
	int widthKnight, heightKnight;

#pragma region Knight Texture White
	glGenTextures(1, &knightTextureW);
	glBindTexture(GL_TEXTURE_2D, knightTextureW);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* knightImageW = SOIL_load_image("Textures/whiteMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, knightImageW);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(knightImageW);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma region Knight Texture Black
	glGenTextures(1, &knightTextureB);
	glBindTexture(GL_TEXTURE_2D, knightTextureB);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* knightImageB = SOIL_load_image("Textures/blackMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, knightImageB);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(knightImageB);
	glBindTexture(GL_TEXTURE_2D, 0);


#pragma endregion

#pragma endregion

	//Builds ChessPiece Bishop
#pragma region Bishop

	Shader ourShaderBishop("chessBoardVert.vs", "chessBoardFrag.frag");

	GLfloat bishopVerts[19512];

	ifstream myFileBishop("Bishop.txt");
	i = 0;

	if (myFileBishop.is_open())
	{
		string line;

		while (!myFileBishop.eof())
		{
			getline(myFileBishop, line, ' ');
			bishopVerts[i] = stof(line);
			i++;
			getline(myFileBishop, line, ' ');
			bishopVerts[i] = stof(line);
			i++;
			getline(myFileBishop, line, '\n');
			bishopVerts[i] = stof(line);
			i++;
		}
		myFileBishop.close();
	}
	else
	{
		cout << "Can't open the file";
	}

	glm::vec3 bishopPos[] =
	{
		// Black chess pieces
		glm::vec3(2.0f, 0.5f, 4.0f),
		glm::vec3(-1.0f, 0.5f, 4.0f),

		// White chess pieces
		glm::vec3(-1.0f, 0.5f, -3.0f),
		glm::vec3(2.0f, 0.5f, -3.0f),
	};

	GLuint VBA_Bishop, VOA_Bishop;
	glGenVertexArrays(1, &VOA_Bishop);
	glGenBuffers(1, &VBA_Bishop);

	glBindVertexArray(VOA_Bishop);

	glBindBuffer(GL_ARRAY_BUFFER, VBA_Bishop);
	glBufferData(GL_ARRAY_BUFFER, sizeof(bishopVerts), bishopVerts, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	GLuint bishopTextureW, bishopTextureB;
	int widthBishop, heightBishop;

#pragma region Bishop Texture White
	glGenTextures(1, &bishopTextureW);
	glBindTexture(GL_TEXTURE_2D, bishopTextureW);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* bishopImageW = SOIL_load_image("Textures/whiteMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, bishopImageW);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(bishopImageW);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma region Bishop Texture Black
	glGenTextures(1, &bishopTextureB);
	glBindTexture(GL_TEXTURE_2D, bishopTextureB);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* bishopImageB = SOIL_load_image("Textures/blackMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, bishopImageB);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(bishopImageB);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma endregion

	//Builds ChessPiece Queen
#pragma region Queen

	Shader ourShaderQueen("chessBoardVert.vs", "chessBoardFrag.frag");

	GLfloat QueenVerts[21186];

	ifstream myFileQueen("Queen.txt");
	i = 0;

	if (myFileQueen.is_open())
	{
		string line;

		while (!myFileQueen.eof())
		{
			getline(myFileQueen, line, ' ');
			QueenVerts[i] = stof(line);
			i++;
			getline(myFileQueen, line, ' ');
			QueenVerts[i] = stof(line);
			i++;
			getline(myFileQueen, line, '\n');
			QueenVerts[i] = stof(line);
			i++;
		}
		myFileQueen.close();
	}
	else
	{
		cout << "Can't open the file";
	}

	glm::vec3 queenPos[] =
	{
		// White chess pieces
		glm::vec3(0.0f, 0.5f, 4.0f),

		// Black chess pieces
		glm::vec3(0.0f, 0.5f, -3.0f),
	};

	GLuint VBA_Queen, VOA_Queen;
	glGenVertexArrays(1, &VOA_Queen);
	glGenBuffers(1, &VBA_Queen);

	glBindVertexArray(VOA_Queen);

	glBindBuffer(GL_ARRAY_BUFFER, VBA_Queen);
	glBufferData(GL_ARRAY_BUFFER, sizeof(QueenVerts), QueenVerts, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	GLuint queenTextureW, queenTextureB;
	int widthQueen, heightQueen;

#pragma region Queen Texture White
	glGenTextures(1, &queenTextureW);
	glBindTexture(GL_TEXTURE_2D, queenTextureW);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* queenImageW = SOIL_load_image("Textures/whiteMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, queenImageW);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(queenImageW);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma region Queen Texture Black
	glGenTextures(1, &queenTextureB);
	glBindTexture(GL_TEXTURE_2D, queenTextureB);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* queenImageB = SOIL_load_image("Textures/blackMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, queenImageB);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(queenImageB);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma endregion

	//Builds ChessPiece King
#pragma region King

	Shader ourShaderKing("chessBoardVert.vs", "chessBoardFrag.frag");

	GLfloat KingVerts[3564];

	ifstream myFileKing("King.txt");
	i = 0;

	if (myFileKing.is_open())
	{
		string line;

		while (!myFileKing.eof())
		{
			getline(myFileKing, line, ' ');
			KingVerts[i] = stof(line);
			i++;
			getline(myFileKing, line, ' ');
			KingVerts[i] = stof(line);
			i++;
			getline(myFileKing, line, '\n');
			KingVerts[i] = stof(line);
			i++;
		}
		myFileKing.close();
	}
	else
	{
		cout << "Can't open the file";
	}

	glm::vec3 kingPos[] =
	{
		// Black chess pieces
		glm::vec3(1.0f, 0.5f, 4.0f),

		// White chess pieces
		glm::vec3(1.0f, 0.5f, -3.0f),
	};

	GLuint VBA_King, VOA_King;
	glGenVertexArrays(1, &VOA_King);
	glGenBuffers(1, &VBA_King);

	glBindVertexArray(VOA_King);

	glBindBuffer(GL_ARRAY_BUFFER, VBA_King);
	glBufferData(GL_ARRAY_BUFFER, sizeof(KingVerts), KingVerts, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	GLuint kingTextureW, kingTextureB;
	int widthKing, heightKing;

#pragma region King Texture White
	glGenTextures(1, &kingTextureW);
	glBindTexture(GL_TEXTURE_2D, kingTextureW);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* kingImageW = SOIL_load_image("Textures/whiteMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, kingImageW);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(kingImageW);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma region King Texture Black
	glGenTextures(1, &kingTextureB);
	glBindTexture(GL_TEXTURE_2D, kingTextureB);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* kingImageB = SOIL_load_image("Textures/blackMarble.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, kingImageB);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(kingImageB);
	glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma endregion

#pragma region 3DModels

//Builds Model1
#pragma region model1

Shader modelShaderOne("chessBoardVert.vs", "chessBoardFrag.frag");

// Vertex data for our Custom model
GLfloat modelVert1[10584];

// Reads the vertex information from the text file 
ifstream myFileModel1("model1.txt");

i = 0;

if (myFileModel1.is_open())
{
	string line;

	while (!myFileModel1.eof())
	{
		getline(myFileModel1, line, ' ');
		modelVert1[i] = stof(line);
		i++;
		getline(myFileModel1, line, ' ');
		modelVert1[i] = stof(line);
		i++;
		getline(myFileModel1, line, '\n');
		modelVert1[i] = stof(line);
		i++;
	}
	myFileModel1.close();
}
else
{
	cout << "Can't open the file";
}

// Placing the Custom Model in the world
glm::vec3 modelPos1[] =
{
	glm::vec3(-2.0f, -2.5f, 10.0f),
};

// Generates the vertex arrays and vertex buffers and save them into variables
GLuint VBA_Model1, VOA_Model1;
glGenVertexArrays(1, &VOA_Model1);
glGenBuffers(1, &VBA_Model1);

// Bind the vertex array to the object
glBindVertexArray(VOA_Model1);

// Bind and set the vertex buffers
glBindBuffer(GL_ARRAY_BUFFER, VBA_Model1);
glBufferData(GL_ARRAY_BUFFER, sizeof(modelVert1), modelVert1, GL_STATIC_DRAW);

// Create the vertex pointer and enable the vertex array
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0); //Position
glEnableVertexAttribArray(0);

// Texture coordinate attribute
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
glEnableVertexAttribArray(2);

// Unbind the vertex array to prevent strange bugs
glBindVertexArray(0);

// Custom Model1 texture variables
GLuint textureModel1;
int widthModel1, heightModel1;

#pragma region Model Texture
// Create and load Custom Model Texture
glGenTextures(1, &textureModel1);
glBindTexture(GL_TEXTURE_2D, textureModel1);

// Set texture parameters
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

// Set texture filtering
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// Texture loading from the code
unsigned char* imageModel1 = SOIL_load_image("Textures/model1.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

// Specify the 2D texture image for texturing the object
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageModel1);

// Generate mipmaps
glGenerateMipmap(GL_TEXTURE_2D);
SOIL_free_image_data(imageModel1);
glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma endregion

//Builds Model2
#pragma region model2

Shader modelShaderTwo("chessBoardVert.vs", "chessBoardFrag.frag");

GLfloat modelVert2[15336];

ifstream myFileModel2("model2.txt");

i = 0;

if (myFileModel2.is_open())
{
	string line;

	while (!myFileModel2.eof())
	{
		getline(myFileModel2, line, ' ');
		modelVert2[i] = stof(line);
		i++;
		getline(myFileModel2, line, ' ');
		modelVert2[i] = stof(line);
		i++;
		getline(myFileModel2, line, '\n');
		modelVert2[i] = stof(line);
		i++;
	}
	myFileModel2.close();
}
else
{
	cout << "Can't open the file";
}

glm::vec3 modelPos2[] =
{
	glm::vec3(5.0f, -3.0f, -10.0f),
};

GLuint VBA_Model2, VOA_Model2;
glGenVertexArrays(1, &VOA_Model2);
glGenBuffers(1, &VBA_Model2);

glBindVertexArray(VOA_Model2);

glBindBuffer(GL_ARRAY_BUFFER, VBA_Model2);
glBufferData(GL_ARRAY_BUFFER, sizeof(modelVert2), modelVert2, GL_STATIC_DRAW);

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
glEnableVertexAttribArray(0);

glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
glEnableVertexAttribArray(2);

glBindVertexArray(0);

GLuint textureModel2;
int widthModel2, heightModel2;

#pragma region Model Texture

glGenTextures(1, &textureModel2);
glBindTexture(GL_TEXTURE_2D, textureModel2);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

unsigned char* imageModel2 = SOIL_load_image("Textures/model3.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageModel2);

glGenerateMipmap(GL_TEXTURE_2D);
SOIL_free_image_data(imageModel2);
glBindTexture(GL_TEXTURE_2D, 0);

#pragma endregion

#pragma endregion

//Builds Model3
#pragma region model3

Shader modelShaderThree("chessBoardVert.vs", "chessBoardFrag.frag");

GLfloat modelVert3[20034];

ifstream myFileModel3("model3.txt");

i = 0;

if (myFileModel3.is_open())
{
	string line;

	while (!myFileModel3.eof())
	{
		getline(myFileModel3, line, ' ');
		modelVert3[i] = stof(line);
		i++;
		getline(myFileModel3, line, ' ');
		modelVert3[i] = stof(line);
		i++;
		getline(myFileModel3, line, '\n');
		modelVert3[i] = stof(line);
		i++;
	}
	myFileModel3.close();
}
else
{
	cout << "Can't open the file";
}

glm::vec3 modelPos3[] =
{
	glm::vec3(8.0f, -7.0f, 10.0f),
};

GLuint VBA_Model3, VOA_Model3;
glGenVertexArrays(1, &VOA_Model3);
glGenBuffers(1, &VBA_Model3);

glBindVertexArray(VOA_Model3);

glBindBuffer(GL_ARRAY_BUFFER, VBA_Model3);
glBufferData(GL_ARRAY_BUFFER, sizeof(modelVert3), modelVert3, GL_STATIC_DRAW);

glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0); 
glEnableVertexAttribArray(0);


glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
glEnableVertexAttribArray(2);

glBindVertexArray(0);

GLuint textureModel3;
int widthModel3, heightModel3;

#pragma region Model Texture
glGenTextures(1, &textureModel3);
glBindTexture(GL_TEXTURE_2D, textureModel3);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

unsigned char* imageModel3 = SOIL_load_image("Textures/model2.png", &widthB, &heightB, 0, SOIL_LOAD_RGBA);

glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthB, heightB, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageModel3);

glGenerateMipmap(GL_TEXTURE_2D);
SOIL_free_image_data(imageModel3);
glBindTexture(GL_TEXTURE_2D, 0);
#pragma endregion

#pragma endregion


#pragma endregion

	//Builds SKYBOX shader
#pragma region SKYBOX shader

	Shader skyboxShader("skyboxVert.vs", "skyboxFrag.frag");

	float skyboxVerts[] = {
		// positions          
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f
	};

	// Generate the vertex arrays and vertex buffers and save them into variables
	unsigned int skyboxVAO, skyboxVBO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);

	// Bind the vertex array object
	glBindVertexArray(skyboxVAO);

	// Bind and set the vertex buffers
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVerts), &skyboxVerts, GL_STATIC_DRAW);

	// Create the vertex pointer and enable the vertex array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Load textures
	vector<std::string> skyboxFaces
	{
		"Skybox3/skybox_right.png",
		"Skybox3/skybox_left.png",
		"Skybox3/skybox_top.png",
		"Skybox3/skybox_bottom.png",
		"Skybox3/skybox_front.png",
		"Skybox3/skybox_back.png"
	};

	// Skybox texture variable
	GLuint skyboxTexture = 0;
	skyboxTexture = CreateSkyboxTexture(skyboxTexture, skyboxFaces, widthTexture, heightTexture);
#pragma endregion


	//While loop to update the program
	while (!glfwWindowShouldClose(window))
	{
		// Set frame time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		cout << 1.0f / deltaTime << " FPS)" << endl; //FPS COUNTER

		// Checks for events and calls corresponding response
		glfwPollEvents();

		// Handle the movement ***
		cameraMovement(window);

		// Clearing the colour and depth buffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Chess board 
#pragma region chess board code inside the while loop

		chessBoardShader.Use();

		// Create Projection Matrix *** (moved into while loop in order to update zoom)
		glm::mat4 projection_Board(1.0f);
		//Perspective view ***
		projection_Board = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 100000.0f);

		// Create camera transformation ***
		glm::mat4 view_Board(1.0f);
		view_Board = camera.GetViewMatrix();

		// Get the uniform locations for our matrices
		GLint modelLoc_Board = glGetUniformLocation(chessBoardShader.Program, "model");
		GLint viewLoc_Board = glGetUniformLocation(chessBoardShader.Program, "view");
		GLint projLoc_Board = glGetUniformLocation(chessBoardShader.Program, "projection");

		// Pass locations to shaders ***
		glUniformMatrix4fv(viewLoc_Board, 1, GL_FALSE, glm::value_ptr(view_Board));
		glUniformMatrix4fv(projLoc_Board, 1, GL_FALSE, glm::value_ptr(projection_Board));

		// Draw container
		glBindVertexArray(VOA_Board);

		for (GLuint i = 0; i < 8; i++)
		{
			for (GLuint j = 0; j < 8; j++)
			{
				if ((i + j) % 2 == 0)
				{
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, setWhiteTexture);
					glUniform1i(glGetUniformLocation(chessBoardShader.Program, "ourTexture1"), 0);
				}
				else
				{
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, setBlackTexture);
					glUniform1i(glGetUniformLocation(chessBoardShader.Program, "ourTexture1"), 0);
				}

				// Calculate the model matrix for each object and pass it to the shader before drawing
				glm::mat4 model_Board(1.0f);
				glm::vec3 tilePos(cubePos[i].x, cubePos[i].y, cubePos[i].z - j);
				model_Board = glm::translate(model_Board, tilePos);
				GLfloat angle = 0.0f;
				model_Board = glm::rotate(model_Board, angle, glm::vec3(1.0f, 0.0f, 0.0f));
				glUniformMatrix4fv(modelLoc_Board, 1, GL_FALSE, glm::value_ptr(model_Board));

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
		
		}
		
#pragma endregion

		//Chessboard border
#pragma region chessboard border code inside while loop

		//Following the same coding principles that was used to setup the chessboard above whilst changing variables to suit the chessboard's border
		borderShader.Use();

		glm::mat4 projection_Boarder(1.0f);

		projection_Boarder = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 100000.0f);

		glm::mat4 view_Boarder(1.0f);
		view_Boarder = camera.GetViewMatrix();

		GLint modelLoc_Boarder = glGetUniformLocation(chessBoardShader.Program, "model");
		GLint viewLoc_Boarder = glGetUniformLocation(chessBoardShader.Program, "view");
		GLint projLoc_Boarder = glGetUniformLocation(chessBoardShader.Program, "projection");

		glUniformMatrix4fv(viewLoc_Boarder, 1, GL_FALSE, glm::value_ptr(view_Boarder));
		glUniformMatrix4fv(projLoc_Boarder, 1, GL_FALSE, glm::value_ptr(projection_Boarder));

		glBindVertexArray(VOA_Boarder);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, borderTexture);
		glUniform1i(glGetUniformLocation(chessBoardShader.Program, "ourTexture1"), 0);

		for (GLuint i = 0; i < 10; i++)
		{
			for (GLuint j = 0; j < 10; j++)
			{
				if (i == 0 || i == 9 || j == 0 || j == 9)
				{
					glm::mat4 model_Boarder(1.0f);
					glm::vec3 chessborderPos(cubeBorderPos[i].x, cubeBorderPos[i].y, cubeBorderPos[i].z - j);
					model_Boarder = glm::translate(model_Boarder, chessborderPos);
					GLfloat angle = 0.0f;
					model_Boarder = glm::rotate(model_Boarder, angle, glm::vec3(1.0f, 0.0f, 0.0f));
					glUniformMatrix4fv(modelLoc_Boarder, 1, GL_FALSE, glm::value_ptr(model_Boarder));

					glDrawArrays(GL_TRIANGLES, 0, 36);

				}

			}
		}



#pragma endregion

		//Height map
#pragma region height map code inside the while loop
		// Activate Shader
		heightMapShader.Use();

		// view/projection transformations
		glm::mat4 projection = glm::perspective(glm::radians(camera.GetZoom()), (float)WIDTH / (float)HEIGHT, 0.1f, 100000.0f);
		glm::mat4 view = camera.GetViewMatrix();
		GLint projLoc = glGetUniformLocation(heightMapShader.Program, "projection");
		GLint viewLoc = glGetUniformLocation(heightMapShader.Program, "view");

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		// world transformation
		glm::mat4 model = glm::mat4(1.0f);
		GLint modelLoc = glGetUniformLocation(heightMapShader.Program, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		// Draw container
		glBindVertexArray(VAO);

		for (int strip = 0; strip < numStrips; strip++)
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, heightMapTexture);
			glUniform1i(glGetUniformLocation(heightMapShader.Program, "ourTexture1"), 0);

			glDrawElements(GL_TRIANGLE_STRIP, // primitive type
			numTrisPerStrip + 2, // number of indices to render
			GL_UNSIGNED_INT, // index data type
			(void*)(sizeof(GLuint) * (numTrisPerStrip + 2) * strip)); // offset to starting index
		}

		glBindVertexArray(0); // Unbinding

#pragma endregion

#pragma region Chess Pieces

		//Pawn
#pragma region Code for pawn in the while loop 

// Activate Shader
		ourShaderPawn.Use();

		// Create Projection Matrix
		glm::mat4 projection_Pawn(1.0f);

		//Perspective view
		projection_Pawn = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

		// Create the camera movement
		glm::mat4 view_Pawn(1.0f);
		view_Pawn = camera.GetViewMatrix();

		// This will get the locations for our pawn matrices
		GLint modelLoc_Pawn = glGetUniformLocation(ourShaderPawn.Program, "model");
		GLint viewLoc_Pawn = glGetUniformLocation(ourShaderPawn.Program, "view");
		GLint projLoc_Pawn = glGetUniformLocation(ourShaderPawn.Program, "projection");

		// Send the locations to the designated shaders
		glUniformMatrix4fv(viewLoc_Pawn, 1, GL_FALSE, glm::value_ptr(view_Pawn));
		glUniformMatrix4fv(projLoc_Pawn, 1, GL_FALSE, glm::value_ptr(projection_Pawn));

		// Draw the container
		glBindVertexArray(VOA_Pawn);

		for (GLuint i = 0; i < 16; i++)
		{
			if (i <= 7)
			{
				// Activate Black Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, pawnTextureB);
				glUniform1i(glGetUniformLocation(ourShaderPawn.Program, "ourTexture1"), 0);
			}
			else
			{
				// Activate White Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, pawnTextureW);
				glUniform1i(glGetUniformLocation(ourShaderPawn.Program, "ourTexture1"), 0);
			}



			// Calculate the model matrix for each object and pass it to the shader before drawing
			glm::mat4 model_Pawn(1.0f);
			model_Pawn = glm::translate(model_Pawn, pawnPositions[i]);
			GLfloat anglePawn = 0.0f;
			model_Pawn = glm::rotate(model_Pawn, anglePawn, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_Pawn, 1, GL_FALSE, glm::value_ptr(model_Pawn));

			glDrawArrays(GL_TRIANGLES, 0, 3810);
		}
#pragma endregion

		//Rook
#pragma region Code for rook in the while loop 

		ourShaderRook.Use();

		glm::mat4 projection_Rook(1.0f);

		projection_Rook = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

		glm::mat4 view_Rook(1.0f);
		view_Rook = camera.GetViewMatrix();

		GLint modelLoc_Rook = glGetUniformLocation(ourShaderRook.Program, "model");
		GLint viewLoc_Rook = glGetUniformLocation(ourShaderRook.Program, "view");
		GLint projLoc_Rook = glGetUniformLocation(ourShaderRook.Program, "projection");

		glUniformMatrix4fv(viewLoc_Rook, 1, GL_FALSE, glm::value_ptr(view_Rook));
		glUniformMatrix4fv(projLoc_Rook, 1, GL_FALSE, glm::value_ptr(projection_Rook));

		glBindVertexArray(VOA_Rook);

		for (GLuint i = 0; i < 4; i++)
		{
			if (i <= 1)
			{
				// Activate Black Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, rookTextureB);
				glUniform1i(glGetUniformLocation(ourShaderRook.Program, "ourTexture1"), 0);
			}
			else
			{
				// Activate White Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, rookTextureW);
				glUniform1i(glGetUniformLocation(ourShaderRook.Program, "ourTexture1"), 0);
			}

			glm::mat4 model_Rook(1.0f);
			model_Rook = glm::translate(model_Rook, rookPos[i]);
			GLfloat angleRook = 0.0f;
			model_Rook = glm::rotate(model_Rook, angleRook, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_Rook, 1, GL_FALSE, glm::value_ptr(model_Rook));

			glDrawArrays(GL_TRIANGLES, 0, 1260);
		}
#pragma endregion

		//Knight
#pragma region Code for knight in the while loop

		ourShaderKnight.Use();

		glm::mat4 projection_Knight(1.0f);

		projection_Knight = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

		glm::mat4 view_Knight(1.0f);
		view_Knight = camera.GetViewMatrix();

		GLint modelLoc_Knight = glGetUniformLocation(ourShaderKnight.Program, "model");
		GLint viewLoc_Knight = glGetUniformLocation(ourShaderKnight.Program, "view");
		GLint projLoc_Knight = glGetUniformLocation(ourShaderKnight.Program, "projection");

		glUniformMatrix4fv(viewLoc_Knight, 1, GL_FALSE, glm::value_ptr(view_Knight));
		glUniformMatrix4fv(projLoc_Knight, 1, GL_FALSE, glm::value_ptr(projection_Knight));

		glBindVertexArray(VOA_Knight);

		for (GLuint i = 0; i < 4; i++)
		{
			if (i <= 1)
			{
				// Activate Black Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, knightTextureB);
				glUniform1i(glGetUniformLocation(ourShaderKnight.Program, "ourTexture1"), 0);
			}
			else
			{
				// Activate White Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, knightTextureW);
				glUniform1i(glGetUniformLocation(ourShaderKnight.Program, "ourTexture1"), 0);
			}

			glm::mat4 model_Knight(1.0f);
			model_Knight = glm::translate(model_Knight, knightPos[i]);
			GLfloat angleKnight = 0.0f;
			model_Knight = glm::rotate(model_Knight, angleKnight, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_Knight, 1, GL_FALSE, glm::value_ptr(model_Knight));

			glDrawArrays(GL_TRIANGLES, 0, 1338);
		}


#pragma endregion

		//Bishop
#pragma region Code for Bishop in the while loop

		ourShaderBishop.Use();

		glm::mat4 projection_Bishop(1.0f);

		projection_Bishop = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

		glm::mat4 view_Bishop(1.0f);
		view_Bishop = camera.GetViewMatrix();

		GLint modelLoc_Bishop = glGetUniformLocation(ourShaderBishop.Program, "model");
		GLint viewLoc_Bishop = glGetUniformLocation(ourShaderBishop.Program, "view");
		GLint projLoc_Bishop = glGetUniformLocation(ourShaderBishop.Program, "projection");

		glUniformMatrix4fv(viewLoc_Bishop, 1, GL_FALSE, glm::value_ptr(view_Bishop));
		glUniformMatrix4fv(projLoc_Bishop, 1, GL_FALSE, glm::value_ptr(projection_Bishop));

		glBindVertexArray(VOA_Bishop);

		for (GLuint i = 0; i < 4; i++)
		{
			if (i <= 1)
			{
				// Activate Black Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, bishopTextureB);
				glUniform1i(glGetUniformLocation(ourShaderBishop.Program, "ourTexture1"), 0);
			}
			else
			{
				// Activate White Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, bishopTextureW);
				glUniform1i(glGetUniformLocation(ourShaderBishop.Program, "ourTexture1"), 0);
			}



			glm::mat4 model_Bishop(1.0f);
			model_Bishop = glm::translate(model_Bishop, bishopPos[i]);
			GLfloat angleBishop = 0.0f;
			model_Bishop = glm::rotate(model_Bishop, angleBishop, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_Bishop, 1, GL_FALSE, glm::value_ptr(model_Bishop));

			glDrawArrays(GL_TRIANGLES, 0, 6504);
		}

#pragma endregion

		// Queen
#pragma region Code for rook in the while loop 

		ourShaderQueen.Use();

		glm::mat4 projection_Queen(1.0f);

		projection_Queen = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

		glm::mat4 view_Queen(1.0f);
		view_Queen = camera.GetViewMatrix();

		GLint modelLoc_Queen = glGetUniformLocation(ourShaderQueen.Program, "model");
		GLint viewLoc_Queen = glGetUniformLocation(ourShaderQueen.Program, "view");
		GLint projLoc_Queen = glGetUniformLocation(ourShaderQueen.Program, "projection");

		glUniformMatrix4fv(viewLoc_Queen, 1, GL_FALSE, glm::value_ptr(view_Queen));
		glUniformMatrix4fv(projLoc_Queen, 1, GL_FALSE, glm::value_ptr(projection_Queen));

		glBindVertexArray(VOA_Queen);

		for (GLuint i = 0; i < 2; i++)
		{
			if (i <= 0)
			{
				// Activate Black Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, queenTextureB);
				glUniform1i(glGetUniformLocation(ourShaderQueen.Program, "ourTexture1"), 0);
			}
			else
			{
				// Activate White Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, queenTextureW);
				glUniform1i(glGetUniformLocation(ourShaderQueen.Program, "ourTexture1"), 0);
			}

			glm::mat4 model_Queen(1.0f);
			model_Queen = glm::translate(model_Queen, queenPos[i]);
			GLfloat angleQueen = 0.0f;
			model_Queen = glm::rotate(model_Queen, angleQueen, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_Queen, 1, GL_FALSE, glm::value_ptr(model_Queen));

			glDrawArrays(GL_TRIANGLES, 0, 7062);
		}
#pragma endregion

		// King
#pragma region Code for rook in the while loop 

		ourShaderKing.Use();

		glm::mat4 projection_King(1.0f);

		projection_King = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

		glm::mat4 view_King(1.0f);
		view_King = camera.GetViewMatrix();

		GLint modelLoc_King = glGetUniformLocation(ourShaderKing.Program, "model");
		GLint viewLoc_King = glGetUniformLocation(ourShaderKing.Program, "view");
		GLint projLoc_King = glGetUniformLocation(ourShaderKing.Program, "projection");

		glUniformMatrix4fv(viewLoc_King, 1, GL_FALSE, glm::value_ptr(view_King));
		glUniformMatrix4fv(projLoc_King, 1, GL_FALSE, glm::value_ptr(projection_King));

		glBindVertexArray(VOA_King);

		for (GLuint i = 0; i < 2; i++)
		{
			if (i <= 0)
			{
				// Activate Black Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, kingTextureB);
				glUniform1i(glGetUniformLocation(ourShaderKing.Program, "ourTexture1"), 0);
			}
			else
			{
				// Activate White Texture
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, kingTextureW);
				glUniform1i(glGetUniformLocation(ourShaderKing.Program, "ourTexture1"), 0);
			}

			glm::mat4 model_King(1.0f);
			model_King = glm::translate(model_King, kingPos[i]);
			GLfloat angleKing = 0.0f;
			model_King = glm::rotate(model_King, angleKing, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_King, 1, GL_FALSE, glm::value_ptr(model_King));

			glDrawArrays(GL_TRIANGLES, 0, 3564);
		}
#pragma endregion

#pragma endregion


#pragma region 3DModels in the while loop

		//Model 1
#pragma region code for model1 in the while loop
		modelShaderOne.Use();

		// Create Projection Matrix
		glm::mat4 projection_Model1(1.0f);

		//Perspective view
		projection_Model1 = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

		// Create the camera movement
		glm::mat4 view_Model1(1.0f);
		view_Model1 = camera.GetViewMatrix();

		// This will get the locations for our pawn matrices
		GLint modelLoc_Model1 = glGetUniformLocation(modelShaderOne.Program, "model");
		GLint viewLoc_Model1 = glGetUniformLocation(modelShaderOne.Program, "view");
		GLint projLoc_Model1 = glGetUniformLocation(modelShaderOne.Program, "projection");

		// Send the locations to the designated shaders
		glUniformMatrix4fv(viewLoc_Model1, 1, GL_FALSE, glm::value_ptr(view_Model1));
		glUniformMatrix4fv(projLoc_Model1, 1, GL_FALSE, glm::value_ptr(projection_Model1));

		// Draw the container
		glBindVertexArray(VOA_Model1);

		// Activate Model Texture
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureModel1);
		glUniform1i(glGetUniformLocation(modelShaderOne.Program, "ourTexture1"), 0);

		// Calculate the model matrix for each object and pass it to the shader before drawing
		glm::mat4 model_Model1(1.0f);
		model_Model1 = glm::translate(model_Model1, modelPos1[0]);
		GLfloat angle = 0.0f;
		model_Model1 = glm::rotate(model_Model1, angle, glm::vec3(1.0f, 0.0f, 0.0f));
		glUniformMatrix4fv(modelLoc_Model1, 1, GL_FALSE, glm::value_ptr(model_Model1));

		glDrawArrays(GL_TRIANGLES, 0, 3528);
#pragma endregion

		//Model 2
#pragma region code for model2 in the while loop
			modelShaderTwo.Use();

			glm::mat4 projection_Model2(1.0f);

			projection_Model2 = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

			glm::mat4 view_Model2(1.0f);
			view_Model2 = camera.GetViewMatrix();

			GLint modelLoc_Model2 = glGetUniformLocation(modelShaderTwo.Program, "model");
			GLint viewLoc_Model2 = glGetUniformLocation(modelShaderTwo.Program, "view");
			GLint projLoc_Model2 = glGetUniformLocation(modelShaderTwo.Program, "projection");

			glUniformMatrix4fv(viewLoc_Model2, 1, GL_FALSE, glm::value_ptr(view_Model2));
			glUniformMatrix4fv(projLoc_Model2, 1, GL_FALSE, glm::value_ptr(projection_Model2));

			glBindVertexArray(VOA_Model2);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, textureModel2);
			glUniform1i(glGetUniformLocation(modelShaderTwo.Program, "ourTexture1"), 0);

			glm::mat4 model_Model2(1.0f);
			model_Model2 = glm::translate(model_Model2, modelPos2[0]);
			GLfloat angle2 = 0.0f;
			model_Model2 = glm::rotate(model_Model2, angle2, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_Model2, 1, GL_FALSE, glm::value_ptr(model_Model2));

			glDrawArrays(GL_TRIANGLES, 0, 5112);
#pragma endregion

		//Model 3
#pragma region code for model3 in the while loop
			modelShaderThree.Use();

			glm::mat4 projection_Model3(1.0f);

			//Perspective view
			projection_Model3 = glm::perspective(camera.GetZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 10000.0f);

			// Create the camera movement
			glm::mat4 view_Model3(1.0f);
			view_Model3 = camera.GetViewMatrix();

			// This will get the locations for our pawn matrices
			GLint modelLoc_Model3 = glGetUniformLocation(modelShaderThree.Program, "model");
			GLint viewLoc_Model3 = glGetUniformLocation(modelShaderThree.Program, "view");
			GLint projLoc_Model3 = glGetUniformLocation(modelShaderThree.Program, "projection");

			// Send the locations to the designated shaders
			glUniformMatrix4fv(viewLoc_Model3, 1, GL_FALSE, glm::value_ptr(view_Model3));
			glUniformMatrix4fv(projLoc_Model3, 1, GL_FALSE, glm::value_ptr(projection_Model3));

			// Draw the container
			glBindVertexArray(VOA_Model3);

			// Activate Black Texture
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, textureModel3);
			glUniform1i(glGetUniformLocation(modelShaderThree.Program, "ourTexture1"), 0);

			// Calculate the model matrix for each object and pass it to the shader before drawing
			glm::mat4 model_Model3(1.0f);
			model_Model3 = glm::translate(model_Model3, modelPos3[0]);
			GLfloat angle3 = 0.0f;
			model_Model3 = glm::rotate(model_Model3, angle3, glm::vec3(1.0f, 0.0f, 0.0f));
			glUniformMatrix4fv(modelLoc_Model3, 1, GL_FALSE, glm::value_ptr(model_Model3));

			glDrawArrays(GL_TRIANGLES, 0, 6678);
#pragma endregion

#pragma endregion 

		//This is where our code for the SKYBOX in the whileloop starts
#pragma region skybox code inside the while loop
		
		glDepthFunc(GL_LEQUAL);

		skyboxShader.Use();

		// Create Projection Matrix
		glm::mat4 projection_Skybox = glm::perspective(glm::radians(camera.GetZoom()), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

		// Create camera transformation
		// remove translation from the view matrix
		glm::mat4 view_Skybox = glm::mat4(glm::mat3(camera.GetViewMatrix()));

		// Get the uniform locations for our matrices
		GLint viewLoc_Skybox = glGetUniformLocation(skyboxShader.Program, "view");
		GLint projLoc_Skybox = glGetUniformLocation(skyboxShader.Program, "projection");

		// Pass locations to shaders ***
		glUniformMatrix4fv(viewLoc_Skybox, 1, GL_FALSE, glm::value_ptr(view_Skybox));
		glUniformMatrix4fv(projLoc_Skybox, 1, GL_FALSE, glm::value_ptr(projection_Skybox));

		glBindVertexArray(skyboxVAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTexture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		glDepthFunc(GL_LESS);
#pragma endregion

		// Draw the OpenGl window/viewport
		glfwSwapBuffers(window);
	}

	// Properly deallocate all resources
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);
	glDeleteVertexArrays(1, &skyboxVAO);
	glDeleteBuffers(1, &skyboxVBO);

	// Terminate GLFW and clear any resources from GLFW
	glfwTerminate();

	return EXIT_SUCCESS;
}

// This method handles the movement of the camera when the user wants to move the camera
void cameraMovement(GLFWwindow* window)
{
	if (isCameraLocked == false)
	{
		// Camera controls
		if (keys[GLFW_KEY_W])
		{
			camera.ProcessKeyboard(FORWARD, deltaTime);
		}

		if (keys[GLFW_KEY_S])
		{
			camera.ProcessKeyboard(BACKWARD, deltaTime);
		}

		if (keys[GLFW_KEY_A])
		{
			camera.ProcessKeyboard(LEFT, deltaTime);
		}

		if (keys[GLFW_KEY_D])
		{
			camera.ProcessKeyboard(RIGHT, deltaTime);
		}
	}
}

// This method is used when there is a key tha has been pressed	
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if (key == GLFW_KEY_TAB && action == GLFW_PRESS)
	{
		if (isCameraLocked == true)
		{
			isCameraLocked = false;
		}
		else
		{
			isCameraLocked = true;
		}
	}

	// Move static camera to the left
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		isCameraLocked = true;
		camera.ChangeCameraView("Left");
	}

	// Move static camera to the right
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		isCameraLocked = true;
		camera.ChangeCameraView("Right");
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			keys[key] = false;
		}
	}
}

// This method is used whenever the mouse is used
void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	GLfloat xOffset = xPos - lastX;
	GLfloat yOffset = lastY - yPos;  

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset);
}

// This method is used whenever the scroll wheel on the mouse is used
void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	camera.ProcessMouseScroll(yOffset);
}

GLuint CreateTexture(GLuint texture, const char* img, int width, int height)
{
	// Createing the textures
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Setting the type of parameters for the textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Setting the type of filtering for the textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Loading the texures
	unsigned char* textureImg = SOIL_load_image(img, &width, &height, 0, SOIL_LOAD_RGBA);

	// Specify that the texture is a 2D image
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureImg);

	// Generatinting the mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(textureImg);
	glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}


GLuint CreateSkyboxTexture(GLuint texture, vector<std::string> faces, int width, int height)
{
	// Same coding principles and methods in the CreateTexture method but tuned to display the skybox
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

	int nrChannels;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char* textureImg = SOIL_load_image(faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (textureImg)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureImg);
			SOIL_free_image_data(textureImg);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
			SOIL_free_image_data(textureImg);
		}
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return texture;
}