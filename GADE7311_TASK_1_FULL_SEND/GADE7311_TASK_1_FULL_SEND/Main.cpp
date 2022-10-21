#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "shader_m.h"
#include "camera.h"

#include "stb_image.h"
#include <vector>
#include "chessBoard.h"



// Window dimensions
const GLuint WIDTH = 1080, HEIGHT = 1000;

ChessBoard cb = ChessBoard();

// settings
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 1000;
int useWireframe = 0;
int displayGrayscale = 0;

// camera - give pretty starting point
Camera camera(glm::vec3(67.0f + 300.0f, 627.5f - 250.0f, 169.9f),
    glm::vec3(0.0f, 1.0f, 0.0f),
    -128.1f, -42.4f);
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;

int process_counter = 0;

void processInput(GLFWwindow* window);

int setWhiteTexture()
{
    unsigned int texture1;

    // setting up the texture 1
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

    unsigned char* data = stbi_load("Textures/whiteMarble.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    return texture1; 
}

int setBlackTexture()
{
    unsigned int texture1; 
    // setting up the texture 1
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

    unsigned char* data = stbi_load("Textures/blackMarble.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    
    return texture1; 
}


int setBorderTexture()
{
    unsigned int texture1;
    // setting up the texture 1
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

    unsigned char* data = stbi_load("Textures/Border.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    return texture1;
}

int setTextureHeight()
{
    unsigned int textureHeight;

    // setting up the texture 1
    glGenTextures(1, & textureHeight);
    glBindTexture(GL_TEXTURE_2D, textureHeight);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

    unsigned char* data = stbi_load("Textures/HeightTexture.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    return textureHeight;
}

//creating pawn first chess piece 
void Pawn()
{
    //Top sphere
    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model = glm::scale(model, glm::vec3(0.1, 0.1, 0.1));
    model = glm::translate(model, glm::vec3(-3.6f, -7.6f, -4.05f));
    view = glm::translate(view, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp1 = projection * view * model;

    unsigned int matricID1 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID1, 1, GL_FALSE, &mvp1[0][0]);

    glPushMatrix();
    GLUquadricObj* sphere = gluNewQuadric();

    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluSphere(sphere, 0.25, 20, 20);

    gluDeleteQuadric(sphere);

    //Cone Base
    glm::mat4 modelCone = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 viewCone = glm::mat4(1.0f);
    glm::mat4 projectionCone = glm::mat4(1.0f);
    modelCone = glm::rotate(modelCone, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    modelCone = glm::scale(modelCone, glm::vec3(0.1, 0.1, 0.1));
    modelCone = glm::translate(modelCone, glm::vec3(-3.6f, -7.6f, -5.0f));
    viewCone = glm::translate(viewCone, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projectionCone = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvpCone = projectionCone * viewCone * modelCone;

    unsigned int matricIdCone = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricIdCone, 1, GL_FALSE, & mvpCone[0][0]);

    glPushMatrix();
    GLUquadricObj* cylinder = gluNewQuadric();

    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluCylinder(cylinder, 0.3, 0.0, 1.0, 20, 20);

    gluDeleteQuadric(cylinder);

    //Small Cylinder
    glm::mat4 model3 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view3 = glm::mat4(1.0f);
    glm::mat4 projection3 = glm::mat4(1.0f);
    model3 = glm::rotate(model3, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model3 = glm::scale(model3, glm::vec3(0.1, 0.1, 0.1));
    model3 = glm::translate(model3, glm::vec3(-3.6f, -7.6f, -5.0f));
    view3 = glm::translate(view3, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection3 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp3 = projection3 * view3 * model3;

    unsigned int matricID3 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID3, 1, GL_FALSE, &mvp3[0][0]);

    glPushMatrix();
    GLUquadricObj* cylinderSmallPawn = gluNewQuadric();

    gluQuadricDrawStyle(cylinderSmallPawn, GLU_FILL);
    gluCylinder(cylinderSmallPawn, 0.33, 0.33, 0.16, 20, 20);

    gluDeleteQuadric(cylinderSmallPawn);
}

void Rook()
{
    //Cylinder
    glm::mat4 model4 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view4 = glm::mat4(1.0f);
    glm::mat4 projection4 = glm::mat4(1.0f);
    model4 = glm::rotate(model4, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model4 = glm::scale(model4, glm::vec3(0.1, 0.1, 0.1));
    model4 = glm::translate(model4, glm::vec3(-3.6f, -6.7f, -5.0f));
    view4 = glm::translate(view4, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection4 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp4 = projection4 * view4 * model4;

    unsigned int matricID3 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID3, 1, GL_FALSE, &mvp4[0][0]);

    glPushMatrix();
    GLUquadricObj* cylinder = gluNewQuadric();

    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluCylinder(cylinder, 0.3, 0.3, 1.0, 20, 20);

    gluDeleteQuadric(cylinder);
}

void Knight()
{
    glm::mat4 model9 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view9 = glm::mat4(1.0f);
    glm::mat4 projection9 = glm::mat4(1.0f);
    model9 = glm::rotate(model9, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model9 = glm::scale(model9, glm::vec3(0.1, 0.1, 0.1));
    model9 = glm::translate(model9, glm::vec3(-2.7f, -6.7f, -5.0f));
    view9 = glm::translate(view9, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection9 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp3 = projection9 * view9 * model9;

    unsigned int matricID3 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID3, 1, GL_FALSE, &mvp3[0][0]);

    glPushMatrix();
    GLUquadricObj* cylinder = gluNewQuadric();

    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluCylinder(cylinder, 0.3, 0.2, 1.0, 20, 20);

    gluDeleteQuadric(cylinder);

}

void Bishop()
{
    //sphere
    glm::mat4 model7 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view7 = glm::mat4(1.0f);
    glm::mat4 projection7 = glm::mat4(1.0f);
    model7 = glm::rotate(model7, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model7 = glm::scale(model7, glm::vec3(0.1, 0.1, 0.1));
    model7 = glm::translate(model7, glm::vec3(-1.85f, -6.65f, -3.8f));
    view7 = glm::translate(view7, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection7 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp7 = projection7 * view7 * model7;

    unsigned int matricID1 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID1, 1, GL_FALSE, &mvp7[0][0]);

    glPushMatrix();
    GLUquadricObj* sphere = gluNewQuadric();

    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluSphere(sphere, 0.25, 20, 20);

    gluDeleteQuadric(sphere);

    //Cylinder
    glm::mat4 model3 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view3 = glm::mat4(1.0f);
    glm::mat4 projection3 = glm::mat4(1.0f);
    model3 = glm::rotate(model3, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model3 = glm::scale(model3, glm::vec3(0.1, 0.1, 0.1));
    model3 = glm::translate(model3, glm::vec3(-1.85f, -6.65f, -5.0f));
    view3 = glm::translate(view3, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection3 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp3 = projection3 * view3 * model3;

    unsigned int matricID3 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID3, 1, GL_FALSE, &mvp3[0][0]);

    glPushMatrix();
    GLUquadricObj* cylinder = gluNewQuadric();

    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluCylinder(cylinder, 0.3, 0.0, 1.0, 20, 20);

    gluDeleteQuadric(cylinder);

}
void Queen()
{

    //Cylinder
    glm::mat4 model5 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view5 = glm::mat4(1.0f);
    glm::mat4 projection5 = glm::mat4(1.0f);
    model5 = glm::rotate(model5, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model5 = glm::scale(model5, glm::vec3(0.1, 0.1, 0.1));
    model5 = glm::translate(model5, glm::vec3(-1.f, -6.65f, -5.0f));
    view5 = glm::translate(view5, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection5 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp5 = projection5 * view5 * model5;

    unsigned int matricID3 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID3, 1, GL_FALSE, &mvp5[0][0]);

    glPushMatrix();
    GLUquadricObj* cylinder = gluNewQuadric();

    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluCylinder(cylinder, 0.3, 0.1, 1.0, 20, 20);

    gluDeleteQuadric(cylinder);
}

void King()
{
    //Cylinder
    glm::mat4 model8 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view8 = glm::mat4(1.0f);
    glm::mat4 projection8 = glm::mat4(1.0f);
    model8 = glm::rotate(model8, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    model8 = glm::scale(model8, glm::vec3(0.1, 0.1, 0.1));
    model8 = glm::translate(model8, glm::vec3(0.035f, -6.65f, -5.0f));
    view8 = glm::translate(view8, glm::vec3(0.5f, 1.0f, -3.0f));// DON'T CHANGE 
    projection8 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

    glm::mat4 mvp8 = projection8 * view8 * model8;

    unsigned int matricID3 = glGetUniformLocation(cb.getShaderProgram(), "MVP");
    glUniformMatrix4fv(matricID3, 1, GL_FALSE, &mvp8[0][0]);

    glPushMatrix();
    GLUquadricObj* cylinder = gluNewQuadric();

    gluQuadricDrawStyle(cylinder, GLU_FILL);
    gluCylinder(cylinder, 0.3, 0.1, 1.0, 20, 20);

    gluDeleteQuadric(cylinder);

}
// The MAIN function, from here we start the application and run the game loop
int main()
{
    glfwInit();
    /* glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

    glfwWindowHint(GLFW_SAMPLES, 4);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GADE7311_TASK_1_FULL_SEND", nullptr, nullptr);

    int screenWidth, screenHeight;
    //callback everytime the window has been resized
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // Define the viewport dimensions
    glViewport(0, 0, screenWidth, screenHeight);
    glEnable(GL_DEPTH_TEST);

    //added task 2 
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);



    Shader heightMapShader("cpuheightVertex.vs", "cpuheightFrag.fs");//intialzing fragment shader found in the source file 

    stbi_set_flip_vertically_on_load(true);
    int width, height, nChannels;
    unsigned char* data = stbi_load("resource folder/render(2).png", //intialzing heightmap image 
        &width, &height, &nChannels,
        0);

    std::vector<float> vertices;
    float yScale = 64.0f / 256.0f, yShift = 16.0f;
    int rez = 1;
    unsigned bytePerPixel = nChannels;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned char* pixelOffset = data + (j + width * i) * bytePerPixel;
            unsigned char y = pixelOffset[0];

            // vertex
            vertices.push_back(-height / 2.0f + height * i / (float)height);
            vertices.push_back((int)y * yScale - yShift);
            vertices.push_back(-width / 2.0f + width * j / (float)width);
        }
    }
    stbi_image_free(data);

    std::vector<unsigned> indices;
    for (unsigned i = 0; i < height - 1; i += rez)
    {
        for (unsigned j = 0; j < width; j += rez)
        {
            for (unsigned k = 0; k < 2; k++)
            {
                indices.push_back(j + width * (i + k * rez));
            }
        }
    }
    std::cout << "Loaded " << indices.size() << " indices" << std::endl;

    const int numStrips = (height - 1) / rez;
    const int numTrisPerStrip = (width / rez) * 2 - 2;
    std::cout << "Created lattice of " << numStrips << " strips with " << numTrisPerStrip << " triangles each" << std::endl;
    std::cout << "Created " << numStrips * numTrisPerStrip << " triangles total" << std::endl;

    // first, configure the cube's VAO (and terrainVBO + terrainIBO)
    unsigned int terrainVAO, terrainVBO, terrainIBO;
    glGenVertexArrays(1, &terrainVAO);
    glBindVertexArray(terrainVAO);

    glGenBuffers(1, &terrainVBO);
    glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    //texture attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0,0); //Texture
    glEnableVertexAttribArray(2);

    glGenBuffers(1, &terrainIBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned), &indices[0], GL_STATIC_DRAW);

    

    //Set up chessboard
    cb.compileShaders();
    cb.generate1();
    cb.generate2();



    // Game loop until the user presses exit
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        heightMapShader.use();

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100000.0f);
        glm::mat4 view = camera.GetViewMatrix();
        heightMapShader.setMat4("projection", projection);
        heightMapShader.setMat4("view", view);

        // world transformation
        glm::mat4 model = glm::mat4(1.0f);
        heightMapShader.setMat4("model", model);

        //draw terrain
        glBindVertexArray(terrainVAO);
        for (unsigned strip = 0; strip < numStrips; strip++)
        {
            glDrawElements(GL_TRIANGLE_STRIP,   // primitive type
                numTrisPerStrip + 2,   // number of indices to render
                GL_UNSIGNED_INT,     // index data type
                (void*)(sizeof(unsigned) * (numTrisPerStrip + 2) * strip)); // offset to starting index

            //Linking the Height Map texture
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, setTextureHeight());
        }

        glBindVertexArray(0);



        //Draw Chessboard
        glUseProgram(cb.getShaderProgram());


        glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view2 = glm::mat4(1.0f);
        glm::mat4 projection2 = glm::mat4(1.0f);
        model2 = glm::rotate(model2, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
        view2 = glm::lookAt(cb.getCameraPosition(), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        projection2 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

        glm::mat4 mvp = projection2 * view2 * model2;

        unsigned int matricID = glGetUniformLocation(cb.getShaderProgram(), "MVP");
        glUniformMatrix4fv(matricID, 1, GL_FALSE, &mvp[0][0]);

       /* unsigned int matricIdProj = glGetUniformLocation(cb.getShaderProgram(), "projection");
        glUniformMatrix4fv(matricIdProj, 1, GL_FALSE, &mvp[0][0]);

        unsigned int matricIdView = glGetUniformLocation(cb.getShaderProgram(), "view");
        glUniformMatrix4fv(matricIdView, 1, GL_FALSE, &mvp[0][0]);

        unsigned int matricIdModel = glGetUniformLocation(cb.getShaderProgram(), "model");
        glUniformMatrix4fv(matricIdModel, 1, GL_FALSE, &mvp[0][0]);*/

        for (int i = 0; i < 85; i++)
        {
            if (i % 2 == 0)
            {
                glBindTexture(GL_TEXTURE_2D, setWhiteTexture());
            }
            else
            {
                glBindTexture(GL_TEXTURE_2D, setBlackTexture());
            }
            glBindVertexArray(cb.getVertexArrayIds()[i]);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        //Border
        glBindTexture(GL_TEXTURE_2D, setBorderTexture());
        glBindVertexArray(cb.getVertexArrayIds()[85]);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glUseProgram(cb.getShaderProgram());

        glBindTexture(GL_TEXTURE_2D, setWhiteTexture());               //setting the texture 

        Pawn();
        Rook();
        Queen();
        King();
        Bishop();
        Knight();

        glfwSwapBuffers(window);
        glfwPollEvents();

        ++process_counter;

        if (process_counter == 8) {
            process_counter = 0;
        }
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

/*void key_callback(GLFWwindow* window, int key, int scancode, int action, int modifiers)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case GLFW_KEY_RIGHT:
            //cb.setNewCameraPosition();
            break;
        default:
            break;
        }
    }
}*/


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        cb.setNewCameraPosition(process_counter);

}



