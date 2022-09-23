#include <iostream>
#include <GADE7311_TASK_1_FULL_SEND/Library Extenstion Holders/glew-2.1.0/include/GL/glew.h>
#include<GADE7311_TASK_1_FULL_SEND/Library Extenstion Holders/glfw-3.3.8/include/GLFW/glfw3.h>



#include"Library Extenstion Holders/glm-master/glm/glm.hpp"
#include "Library Extenstion Holders/glm-master/glm/gtc/matrix_transform.hpp"

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

// camera view
Camera camera(glm::vec3(67.0f + 300.0f, 627.5f - 250.0f, 169.9f), glm::vec3(0.0f, 1.0f, 0.0f),-128.1f, -42.4f);
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;

int process_counter = 0;

void processInput(GLFWwindow* window);

// The MAIN function, from here we start the application and run the game loop
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

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

    glGenBuffers(1, &terrainIBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, terrainIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned), &indices[0], GL_STATIC_DRAW);





    //Set up chessboard


    cb.ImplementShaders();
    cb.create1();
    cb.Create2();



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
        }

        glBindVertexArray(0);



        //Draw Chessboard
        glUseProgram(cb.getShaderProgram());


        glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view2 = glm::mat4(1.0f);
        glm::mat4 projection2 = glm::mat4(1.0f);
        model2 = glm::rotate(model2, glm::radians(-55.0f), glm::vec3(1.0f, 0.3f, 0.5f));
        view2 = glm::lookAt(cb.getCameraPos(), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        projection2 = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

        glm::mat4 mvp = projection2 * view2 * model2;

        unsigned int matricID = glGetUniformLocation(cb.getShaderProgram(), "MVP");
        glUniformMatrix4fv(matricID, 1, GL_FALSE, &mvp[0][0]);



        for (int i = 0; i < 85; i++)
        {
            glBindVertexArray(cb.getVertexArrayIds()[i]);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glBindVertexArray(cb.getVertexArrayIds()[85]);
        glDrawArrays(GL_TRIANGLES, 0, 36);

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



void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        cb.setNewCameraPos(process_counter);

}



