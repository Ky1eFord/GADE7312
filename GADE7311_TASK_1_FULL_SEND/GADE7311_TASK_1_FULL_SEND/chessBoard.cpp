#include "chessBoard.h"

GLuint ChessBoard::getShaderProgram() {
    return this->shaderProgram;
}

GLuint* ChessBoard::getVertexArrayIds() {
    return this->VAO;
}


void ChessBoard::setNewCameraPosition(int process_counter) {

    if (process_counter == 0) {
        ++this->cam_index;

        if (this->cam_index == 3) {
            this->cam_index = 0;
        }

    }
}

glm::vec3 ChessBoard::getCameraPosition() {
    return this->cam_positions[this->cam_index];
}


void ChessBoard::generate1() {
    glGenVertexArrays(86, VAO);
    glGenBuffers(86, VBO);

    //intializing all float variables
    float blackTile = 0.0f;
    float whiteTile = 1.0f;
    float switchTile = blackTile;

    float firstXcord = -0.4f;
    float secondXcord = -0.3f;
    float secondYcord = 0.5f;
    float firstYcord = 0.4f;
    float ori = -0.02f;
    float raise = 0.02f;

   
    //intializing all boolean variables
    bool firstrow = true;
    bool secrow = false;
    bool thirdrow = false;
    bool fourthrow = false;
    bool fifthrow = false;
    bool sixrow = false;
    bool sevenrow = false;
    bool eightrow = false;
    bool ninerow = false;

    //intializing all integer variables
    int index = 0;  
    int rowOne = 1;
    int rowTwo = 0;
    int rowThree = 0;
    int rowFour = 0;
    int rowFive = 0;
    int rowSix = 0;
    int rowSeven = 0;
    int rowEight = 0;
    int rowNine = 0;
 

    srand(time(NULL));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            float random = ori + (float)rand() / (float)RAND_MAX * raise;
            if (firstrow)
            {

                if (rowOne == 1 || rowOne == 3 || rowOne == 5 || rowOne == 7)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                         
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                          
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                      
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                        
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                             
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowOne == 2 || rowOne == 4 || rowOne == 6 || rowOne == 8)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                       
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                            
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                           
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

             
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowOne++;
            }

            if (rowOne == 10)
            {
                secrow = true;
                firstrow = false;
            }
            if (secrow)
            {
                if (rowTwo == 1 || rowTwo == 3 || rowTwo == 5 || rowTwo == 7)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                          //back
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }

                if (rowTwo == 2 || rowTwo == 4 || rowTwo == 6 || rowTwo == 8)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                          
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                       
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                       
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                    
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                          
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowTwo++;
            }
            if (rowTwo == 10)
            {
                thirdrow = true;

            }
            if (thirdrow)
            {
                if (rowThree == 1 || rowThree == 3 || rowThree == 5 || rowThree == 7)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                     
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowThree == 2 || rowThree == 4 || rowThree == 6 || rowThree == 8)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowThree++;
            }
            if (rowThree == 10)
            {
                fourthrow = true;
                thirdrow = false;
            }
            if (fourthrow)
            {
                if (rowFour == 1 || rowFour == 3 || rowFour == 5 || rowFour == 7)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

     
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowFour == 2 || rowFour == 4 || rowFour == 6 || rowFour == 8)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowFour++;
            }
            if (rowFour == 10)
            {
                fifthrow = true;
                fourthrow = false;

            }
            if (fifthrow)
            {
                if (rowFive == 1 || rowFive == 3 || rowFive == 5 || rowFive == 7)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

   
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,


                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowFive == 2 || rowFive == 4 || rowFive == 6 || rowFive == 8)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,


                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,


                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowFive++;
            }
            if (rowFive == 10)
            {
                sixrow = true;
                fifthrow = false;
            }
            if (sixrow)
            {
                if (rowSix == 1 || rowSix == 3 || rowSix == 5 || rowSix == 7)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowSix == 2 || rowSix == 4 || rowSix == 6 || rowSix == 8)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowSix++;
            }
            if (rowSix == 10)
            {
                sevenrow = true;
                sixrow = false;
            }
            if (sevenrow)
            {
                if (rowSeven == 1 || rowSeven == 3 || rowSeven == 5 || rowSeven == 7)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowSeven == 2 || rowSeven == 4 || rowSeven == 6 || rowSeven == 8)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,

                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                      
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                      
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };
            
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowSeven++;
            }
            if (rowSeven == 10)
            {
                eightrow = true;
                sevenrow = false;
            }
            if (eightrow)
            {
                if (rowEight == 1 || rowEight == 3 || rowEight == 5 || rowEight == 7)
                {
                    switchTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,


                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile


                    };
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowEight == 2 || rowEight == 4 || rowEight == 6 || rowEight == 8)
                {
                    switchTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,

                           secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                          firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,

                  
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                           firstXcord, firstYcord, random,      switchTile, switchTile, switchTile,

                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, -0.1f,       switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                            firstXcord, firstYcord, random,       switchTile, switchTile, switchTile,
                            firstXcord, secondYcord, random,        switchTile, switchTile, switchTile,


                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, -0.1f,      switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                            secondXcord, firstYcord, random,      switchTile, switchTile, switchTile,
                            secondXcord, secondYcord, random,       switchTile, switchTile, switchTile,

                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, random,    switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             secondXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, -0.1f,     switchTile, switchTile, switchTile,
                             firstXcord, firstYcord, random,    switchTile, switchTile, switchTile,

                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, random,     switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              secondXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, -0.1f,      switchTile, switchTile, switchTile,
                              firstXcord, firstYcord, random,     switchTile, switchTile, switchTile
                    };

                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowEight++;
            }


            index++;
            firstXcord += 0.1f;
            secondXcord += 0.1f;
        }


        firstXcord = -0.4f;
        secondXcord = -0.3f;
        secondYcord -= 0.1f;
        firstYcord -= 0.1f;

    }
}


void ChessBoard::compileShaders() {
    // Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint success;
    GLchar infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void ChessBoard::generate2() {
    float xcoord = -0.4f;
    float xxcoord = -0.3f;
    float ycoord = 0.5f;
    float yycoord = 0.4f;
    int indexborder = 81;
    int ten = 0;
    int eleven = 0;
    int twelf = 0;
    //for (int x = 0; x < 4; x++)
    //{
    //    if (ten == 0)
    //    {
    //        GLfloat vertices[] =
    //        {
    //            //colour co-oridinates       colour assigned to the co-ordinates, in this example the colour is blue 
    //            -0.4f, 0.5f, -0.05f,   0.0f, 1.0f, 1.0f,
    //            -0.45f, 0.55f, -0.05f,   0.0f, 1.0f, 1.0f,
    //            -0.45f, -0.45f, -0.05f,  0.0f, 1.0f, 1.0f,

    //             -0.4f, -0.4f, -0.05f,   0.0f, 1.0f, 1.0f,
    //             -0.4f, 0.5f, -0.05f,    0.0f, 1.0f, 1.0f,
    //             -0.45f, -0.45f, -0.05f,   0.0f, 1.0f, 1.0f
    //        };
    //        glBindVertexArray(VAO[indexborder]);

    //        glBindBuffer(GL_ARRAY_BUFFER, VBO[indexborder]);
    //        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    //        glEnableVertexAttribArray(0);

    //        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    //        glEnableVertexAttribArray(1);

    //    }
    //    if (ten == 1)
    //    {
    //        GLfloat vertices[] =
    //        {
    //            -0.4f, 0.5f, -0.05f,   0.0f, 1.0f, 1.0f,
    //            -0.45f, 0.55f, -0.05f,   0.0f, 1.0f, 1.0f,
    //             0.55f, 0.55f, -0.05f,  0.0f, 1.0f, 1.0f,

    //             0.5f, 0.5f, -0.05f,   0.0f, 1.0f, 1.0f,
    //             0.55f, 0.55f, -0.05f,    0.0f, 1.0f, 1.0f,
    //             -0.4f, 0.5f, -0.05f,   0.0f, 1.0f, 1.0f
    //        };
    //        glBindVertexArray(VAO[indexborder]);

    //        glBindBuffer(GL_ARRAY_BUFFER, VBO[indexborder]);
    //        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    //        glEnableVertexAttribArray(0);

    //        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    //        glEnableVertexAttribArray(1);
    //    }
    //    if (ten == 2)
    //    {
    //        GLfloat vertices[] =
    //        {
    //            0.5f, 0.5f, -0.05f,   0.0f, 1.0f, 1.0f,
    //            0.55f, 0.55f, -0.05f,   0.0f, 1.0f, 1.0f,
    //             0.55f, -0.45f, -0.05f,  0.0f, 1.0f, 1.0f,

    //             0.5f, -0.45f, -0.05f,   0.0f, 1.0f, 1.0f,
    //             0.55f, -0.45f, -0.05f,    0.0f, 1.0f, 1.0f,
    //             0.5f, 0.5f, -0.05f,   0.0f, 1.0f, 1.0f
    //        };
    //        glBindVertexArray(VAO[indexborder]);

    //        glBindBuffer(GL_ARRAY_BUFFER, VBO[indexborder]);
    //        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    //        glEnableVertexAttribArray(0);

    //        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    //        glEnableVertexAttribArray(1);
    //    }
    //    if (ten == 3)
    //    {
    //        GLfloat vertices[] =
    //        {
    //            0.5f, -0.4f, -0.05f,   0.0f, 1.0f, 1.0f,
    //            0.55f, -0.45f, -0.05f,   0.0f, 1.0f, 1.0f,
    //            -0.4f, -0.4f, -0.05f,  0.0f, 1.0f, 1.0f,

    //             -0.45f, -0.45f, -0.05f,   0.0f, 1.0f, 1.0f,
    //             -0.4f, -0.4f, -0.05f,    0.0f, 1.0f, 1.0f,
    //             0.55f, -0.45f, -0.05f,   0.0f, 1.0f, 1.0f
    //        };
    //        glBindVertexArray(VAO[indexborder]);

    //        glBindBuffer(GL_ARRAY_BUFFER, VBO[indexborder]);
    //        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    //        glEnableVertexAttribArray(0);

    //        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    //        glEnableVertexAttribArray(1);
    //    }

    //    ten++;
    //    indexborder++;
    //}

    GLfloat verticesb[] =
    {

         -0.45f, -0.45f, -0.1f,    0.0f, 0.0f,
          0.55f, -0.45f, -0.1f,     1.0f, 0.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f,
         -0.45f, 0.55f, -0.1f,      0.0f, 1.0f,
         -0.45f, -0.45f, -0.1f,     0.0f, 0.0f, //Right


         -0.45f, -0.45f, -0.05f,      1.0f, 0.0f,
          0.55f, -0.45f, -0.05f,      1.0f, 1.0f,
          0.55f, 0.55f, -0.05f,       0.0f, 1.0f,
          0.55f, 0.55f, -0.05f,       0.0f, 1.0f, 
         -0.45f, 0.55f, -0.05f,       0.0f, 0.0f, 
         -0.45f, -0.45f, -0.05f,      1.0f, 0.0f, //Back 


         -0.45f, 0.55f, -0.02f,        1.0f, 0.0f, 
         -0.45f, 0.55f, -0.1f,         1.0f, 1.0f, 
         -0.45f, -0.45f, -0.1f,        0.0f, 1.0f, 
         -0.45f, -0.45f, -0.1f,        0.0f, 1.0f, 
         -0.45f, -0.45f, -0.02f,       0.0f, 0.0f, 
         -0.45f, 0.55f, -0.02f,        1.0f, 0.0f,


         0.55f, 0.55f, -0.02f,       0.0f, 1.0f, 
         0.55f, 0.55f, -0.1f,        1.0f, 1.0f, 
         0.55f, -0.45f, -0.1f,       1.0f, 0.0f, 
         0.55f, -0.45f, -0.1f,       1.0f, 0.0f, 
         0.55f, -0.45f, -0.02f,      0.0f, 0.0f,
         0.55f, 0.55f, -0.02f,       0.0f, 1.0f, //Bottom


         -0.45f, -0.45f, -0.02f,    0.0f, 1.0f, 
          0.55f, -0.45f, -0.02f,    1.0f, 1.0f, 
          0.55f, -0.45f, -0.1f,     1.0f, 0.0f, 
          0.55f, -0.45f, -0.1f,     1.0f, 0.0f, 
         -0.45f, -0.45f, -0.1f,     0.0f, 0.0f, 
         -0.45f, -0.45f, -0.02f,    0.0f, 1.0f, //Top


        /* -0.45f, 0.55f, -0.02f,     0.0f, 1.0f, 
          0.55f, 0.55f, -0.02f,     0.0f, 1.0f, 
          0.55f, 0.55f, -0.1f,      0.0f, 1.0f, 
          0.55f, 0.55f, -0.1f,      0.0f, 1.0f, 
         -0.45f, 0.55f, -0.1f,      0.0f, 1.0f, 
         -0.45f, 0.55f, -0.02f,     0.0f, 1.0f,*/




         /*-0.45f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,
          0.55f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,
          0.55f, 0.55f, -0.1f,      0.0f, 1.0f, 1.0f,

          0.55f, 0.55f, -0.1f,      0.0f, 1.0f, 1.0f,
         -0.45f, 0.55f, -0.1f,      0.0f, 1.0f, 1.0f,
         -0.45f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,

     
         -0.45f, -0.45f, -0.05f,      0.0f, 1.0f, 1.0f,
          0.55f, -0.45f, -0.05f,      0.0f, 1.0f, 1.0f,
          0.55f, 0.55f, -0.05f,       0.0f, 1.0f, 1.0f,
          0.55f, 0.55f, -0.05f,       0.0f, 1.0f, 1.0f,
         -0.45f, 0.55f, -0.05f,       0.0f, 1.0f, 1.0f,
         -0.45f, -0.45f, -0.05f,      0.0f, 1.0f, 1.0f,


         -0.45f, 0.55f, -0.02f,        0.0f, 1.0f, 1.0f,
         -0.45f, 0.55f, -0.1f,       0.0f, 1.0f, 1.0f,
         -0.45f, -0.45f, -0.1f,      0.0f, 1.0f, 1.0f,
         -0.45f, -0.45f, -0.1f,      0.0f, 1.0f, 1.0f,
         -0.45f, -0.45f, -0.02f,       0.0f, 1.0f, 1.0f,
         -0.45f, 0.55f, -0.02f,        0.0f, 1.0f, 1.0f,

      
         0.55f, 0.55f, -0.02f,       0.0f, 1.0f, 1.0f,
         0.55f, 0.55f, -0.1f,      0.0f, 1.0f, 1.0f,
         0.55f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,
         0.55f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,
         0.55f, -0.45f, -0.02f,      0.0f, 1.0f, 1.0f,
         0.55f, 0.55f, -0.02f,       0.0f, 1.0f, 1.0f,

    
         -0.45f, -0.45f, -0.02f,    0.0f, 1.0f, 1.0f,
          0.55f, -0.45f, -0.02f,    0.0f, 1.0f, 1.0f,
          0.55f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,
          0.55f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,
         -0.45f, -0.45f, -0.1f,     0.0f, 1.0f, 1.0f,
         -0.45f, -0.45f, -0.02f,    0.0f, 1.0f, 1.0f,


         -0.45f, 0.55f, -0.02f,     0.0f, 1.0f, 1.0f,
          0.55f, 0.55f, -0.02f,     0.0f, 1.0f, 1.0f,
          0.55f, 0.55f, -0.1f,      0.0f, 1.0f, 1.0f,
          0.55f, 0.55f, -0.1f,      0.0f, 1.0f, 1.0f,
         -0.45f, 0.55f, -0.1f,      0.0f, 1.0f, 1.0f,
         -0.45f, 0.55f, -0.02f,     0.0f, 1.0f, 1.0f,*/
    };

    glBindVertexArray(VAO[85]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[85]);

    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesb), verticesb, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
}
