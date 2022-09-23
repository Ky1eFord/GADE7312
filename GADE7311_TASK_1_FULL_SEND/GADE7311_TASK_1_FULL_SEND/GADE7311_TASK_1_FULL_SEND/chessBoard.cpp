#include "chessBoard.h"

GLuint ChessBoard::getShaderProgram() {
    return this->shaderProgramgl;
}

GLuint* ChessBoard::getVertexArrayIds() {
    return this->VAO;
}


void ChessBoard::setNewCameraPos(int counter) {

    if (counter == 0) {
        ++this->camIndex_;

        if (this->camIndex_ == 3) {
            this->camIndex_ = 0;
        }

    }
}

glm::vec3 ChessBoard::getCameraPos() {
    return this->camPositions_[this->camIndex_];
}


void ChessBoard::create1() {
    glGenVertexArrays(86, VAO);
    glGenBuffers(86, VBO);

    //intializing all float variables
    float blackTile = 0.0f;
    float whiteTile = 1.0f;
    float changeTile = blackTile;

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

    // Code does not work for looping the tiles ERROR
    //void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
    //{
    //    // if color is 0 then draw white box and change value of color = 1
    //    if (c == 0)
    //    {
    //        glColor3f(1, 1, 1); // white color value is 1 1 1
    //        c = 1;
    //    }
    //    // if color is 1 then draw black box and change value of color = 0
    //    else
    //    {
    //        glColor3f(0, 0, 0); // black color value is 0 0 0
    //        c = 0;
    //    }

    //    // Draw Square
    //    glBegin(GL_POLYGON);
    //    glVertex2i(x1, y1);
    //    glVertex2i(x2, y2);
    //    glVertex2i(x3, y3);
    //    glVertex2i(x4, y4);
    //    glEnd();
    //}
    //void chessboard()
    //{
    //    glClear(GL_COLOR_BUFFER_BIT); // Clear display window
    //    GLint firstXcord, firstYcord;

    //    for (x = 0; firstXcord <= 800; firstXcord += 100)
    //    {
    //        for (y = 0; firstYcord <= 600; firstYcord += 75)
    //        {
    //            drawSquare(firstXcord, firstYcord + 75, firstXcord + 100, firstYcord + 75, firstXcord + 100, firstYcord, firstXcord, firstYcord);
    //        }
    //    }
    //    // Process all OpenGL routine s as quickly as possible
    //    glFlush();
    //}

    //int main(int agrc, char** argv)
    //{
    //    // Initialize GLUT
    //    glutInit(&agrc, argv);
    //    // Set display mode
    //    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //    // Set top - left display window position.
    //    glutInitWindowPosition(100, 100);
    //    // Set display window width and height
    //    glutInitWindowSize(800, 600);
    //    // Create display window with the given title
    //    glutCreateWindow("Chess Board using OpenGL in C++");
    //    // Execute initialization procedure
    //    init();
    //    // Send graphics to display window
    //    glutDisplayFunc(chessboard);
    //    // Display everything and wait.
    //    glutMainLoop();
    //}


    int count = 9;
    float ver = -0.1f;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            float random = ori + (float)rand() / (float)RAND_MAX * raise;
            if (firstrow)
            {
                
                if (rowOne == 1 || rowOne == 3 || rowOne == 5 || rowOne == 7 || rowOne == 9)
                {
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, ver,              changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,             changeTile, changeTile, changeTile,

                           secondXcord, secondYcord, ver,             changeTile, changeTile, changeTile,
                          firstXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord, ver,                changeTile, changeTile, changeTile,

                         
                           firstXcord, firstYcord, random,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,              changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,               changeTile, changeTile, changeTile,

                          
                            firstXcord, secondYcord, random,              changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,ver,               changeTile, changeTile, changeTile,
                            firstXcord, firstYcord, ver,                changeTile, changeTile, changeTile,
                            firstXcord, firstYcord, ver,               changeTile, changeTile, changeTile,
                            firstXcord, firstYcord, random,               changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,              changeTile, changeTile, changeTile,

                      
                            secondXcord, secondYcord, random,       changeTile, changeTile, changeTile,
                            secondXcord, secondYcord,   ver,      changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,    ver,     changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,    ver,     changeTile, changeTile, changeTile,
                            secondXcord, firstYcord, random,      changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,       changeTile, changeTile, changeTile,

                        
                             firstXcord, firstYcord, random,    changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,    changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, ver,     changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, ver,     changeTile, changeTile, changeTile,
                             firstXcord, firstYcord,  ver,     changeTile, changeTile, changeTile,
                             firstXcord, firstYcord, random,    changeTile, changeTile, changeTile,

                             
                              firstXcord, firstYcord, random,     changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,     changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,      changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,      changeTile, changeTile, changeTile,
                              firstXcord, firstYcord,  ver,      changeTile, changeTile, changeTile,
                              firstXcord, firstYcord, random,     changeTile, changeTile, changeTile


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
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile

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
                if (rowTwo == 1 || rowTwo == 3 || rowTwo == 5 || rowTwo == 7 || rowTwo == 9)
                {
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile

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
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile

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
                if (rowThree == 1 || rowThree == 3 || rowThree == 5 || rowThree == 7 || rowThree == 9)
                {
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,        
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                if (rowFour == 1 || rowFour == 3 || rowFour == 5 || rowFour == 7 || rowFour == 9)
                {
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                          firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile

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
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                          firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                if (rowFive == 1 || rowFive == 3 || rowFive == 5 || rowFive == 7 || rowFive == 9)
                {
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                if (rowSix == 1 || rowSix == 3 || rowSix == 5 || rowSix == 7 || rowSix == 9)
                {
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                          firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                          firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                if (rowSeven == 1 || rowSeven == 3 || rowSeven == 5 || rowSeven == 7 || rowSeven == 9)
                {
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                          firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                if (rowEight == 1 || rowEight == 3 || rowEight == 5 || rowEight == 7 || rowEight == 9)
                {
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


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
            if (rowEight == 10)
            {
                ninerow = true;
                eightrow = false;
            }
            if (ninerow)
            {
                if (rowNine == 1 || rowNine == 3 || rowNine == 5 || rowNine == 7 || rowNine == 9)
                {
                    changeTile = blackTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


                    };
            
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (rowNine == 2 || rowNine == 4 || rowNine == 6 || rowNine == 8)
                {
                    changeTile = whiteTile;
                    GLfloat vertices[] =
                    {

                           firstXcord, firstYcord,   ver,               changeTile, changeTile, changeTile,
                           secondXcord, firstYcord,  ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, ver,               changeTile, changeTile, changeTile,
                          firstXcord, secondYcord,   ver,               changeTile, changeTile, changeTile,
                          firstXcord, firstYcord,    ver,               changeTile, changeTile, changeTile,

                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,
                           secondXcord, firstYcord, random,             changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           secondXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                           firstXcord, secondYcord, random,             changeTile, changeTile, changeTile,
                           firstXcord, firstYcord, random,              changeTile, changeTile, changeTile,

                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord,    ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,     ver,            changeTile, changeTile, changeTile,
                            firstXcord, firstYcord,  random,            changeTile, changeTile, changeTile,
                            firstXcord, secondYcord, random,            changeTile, changeTile, changeTile,

                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  ver,              changeTile, changeTile, changeTile,
                            secondXcord, firstYcord,  random,           changeTile, changeTile, changeTile,
                            secondXcord, secondYcord, random,           changeTile, changeTile, changeTile,

                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord, random,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             secondXcord, firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord,    ver,           changeTile, changeTile, changeTile,
                             firstXcord,  firstYcord, random,           changeTile, changeTile, changeTile,

                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, random,          changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              secondXcord, firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, ver,             changeTile, changeTile, changeTile,
                              firstXcord,  firstYcord, random,          changeTile, changeTile, changeTile


                    };            
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                rowNine++;
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


void ChessBoard::ImplementShaders() {
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
    shaderProgramgl = glCreateProgram();
    glAttachShader(shaderProgramgl, vertexShader);
    glAttachShader(shaderProgramgl, fragmentShader);
    glLinkProgram(shaderProgramgl);

    glGetProgramiv(shaderProgramgl, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgramgl, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void ChessBoard::Create2() {
    float firstCordX = -0.4f;
    float secondCordX = -0.3f;
    float firstCordY = 0.5f;
    float secondCordY = 0.4f;
    int borderIndex = 81;
    int ten = 0;
    int eleven = 0;
    int twelf = 0;

    float vertValone = -0.4f;
    float vertValtwo = -0.45f;
    float vertValthree = 0.5f;
    float vertValfour = -0.05f;
    float vertValfive = 0.55f;

    int vexCount = 4;
    for (int x = 0; x < vexCount; x++)
    {
        if (ten == 0)
        {
            GLfloat colourVertices[] =
            { 
                 //x   //y   //z
                vertValone, vertValthree, vertValfour,   1.0f, 1.0f, 0.0f,
                vertValtwo, vertValfive, vertValfour,   1.0f, 1.0f, 0.0f,
                vertValtwo, vertValtwo, vertValfour,  1.0f, 1.0f, 0.0f,

                 vertValone, vertValone, vertValfour,   1.0f, 1.0f, 0.0f,
                 vertValone, vertValthree,vertValfour,    1.0f, 1.0f, 0.0f,
                 vertValtwo, vertValtwo, vertValfour,   1.0f, 1.0f, 0.0f
            };
            glBindVertexArray(VAO[borderIndex]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[borderIndex]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(colourVertices), colourVertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);

        }
        if (ten == 1)
        {
            GLfloat colourVertices[] =
            {
                vertValone, vertValthree, vertValfour,   0.0f, 1.0f, 1.0f,
               vertValtwo, vertValfive, vertValfour,   0.0f, 1.0f, 1.0f,
                 vertValfive, vertValfive, vertValfour,  0.0f, 1.0f, 1.0f,

                 vertValthree, vertValthree, vertValfour,   0.0f, 1.0f, 1.0f,
                 vertValfive, vertValfive, vertValfour,    0.0f, 1.0f, 1.0f,
                vertValone, vertValthree, vertValfour,   0.0f, 1.0f, 1.0f
            };
            glBindVertexArray(VAO[borderIndex]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[borderIndex]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(colourVertices), colourVertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        }
        if (ten == 2)
        {
            GLfloat colourVertices[] =
            {
                vertValthree, vertValthree, vertValfour,   0.0f, 1.0f, 1.0f,
                vertValfive, vertValfive, vertValfour,   0.0f, 1.0f, 1.0f,
                 vertValfive, vertValtwo,vertValfour,  0.0f, 1.0f, 1.0f,

                 vertValthree, vertValtwo,vertValfour,   0.0f, 1.0f, 1.0f,
                 vertValfive, vertValtwo,vertValfour,    0.0f, 1.0f, 1.0f,
                 vertValthree, vertValthree, vertValfour,   0.0f, 1.0f, 1.0f
            };
            glBindVertexArray(VAO[borderIndex]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[borderIndex]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(colourVertices), colourVertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        }
        if (ten == 3)
        {
            GLfloat colourVertices[] =
            {
                vertValthree, vertValone, vertValfour,   0.0f, 1.0f, 1.0f,
                vertValfive, vertValtwo, vertValfour,   0.0f, 1.0f, 1.0f,
                vertValone,vertValone, vertValfour,  0.0f, 1.0f, 1.0f,

                 vertValtwo, vertValtwo, vertValfour,   0.0f, 1.0f, 1.0f,
                 vertValone, vertValone, vertValfour,    0.0f, 1.0f, 1.0f,
                 vertValfive, vertValtwo, vertValfour,   0.0f, 1.0f, 1.0f
            };
            glBindVertexArray(VAO[borderIndex]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[borderIndex]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(colourVertices), colourVertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        }

        ten++;
        borderIndex++;
    }

    GLfloat vertice[] =
    {

        
         -0.45f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,

          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,

     
         -0.45f, -0.45f, -0.05f,      1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.05f,      1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.05f,       1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.05f,       1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.05f,       1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.05f,      1.0f, 1.0f, 0.0f,


         -0.45f, 0.55f, -0.02f,        1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.1f,       1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.02f,       1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.02f,        1.0f, 1.0f, 0.0f,

      
         0.55f, 0.55f, -0.02f,       1.0f, 1.0f, 0.0f,
         0.55f, 0.55f, -0.1f,        1.0f, 1.0f, 0.0f,
         0.55f, -0.45f, -0.1f,       1.0f, 1.0f, 0.0f,
         0.55f, -0.45f, -0.1f,       1.0f, 1.0f, 0.0f,
         0.55f, -0.45f, -0.02f,      1.0f, 1.0f, 0.0f,
         0.55f, 0.55f, -0.02f,       1.0f, 1.0f, 0.0f,

    
         -0.45f, -0.45f, -0.02f,    1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.02f,    1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.02f,    1.0f, 1.0f, 0.0f,


         -0.45f, 0.55f, -0.02f,     1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.02f,     1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.02f,     1.0f, 1.0f, 0.0f,

    };
    glBindVertexArray(VAO[85]);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[85]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertice), vertice, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
}
