#include "VertexBufferManager.h"




int VertexBufferManager::initTringleVertices()
{
    GLuint tringleVBO;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    glGenBuffers(1, &tringleVBO);
    glBindBuffer(GL_ARRAY_BUFFER, tringleVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    return sizeof(vertices) / 3;
}

int VertexBufferManager::initSquareVertices()
{
    GLuint squareVBO;

    float squareVertices[] = {
        50.0f,  50.0f, 0.0f, // Vertex 1 (X, Y)
        50.0f, -50.f, 0.0f, // Vertex 2 (X, Y)
       -50.0f, -50.0f, 0.0f, // Vertex 3 (X, Y)

       -50.0f, 50.0f, 0.0f, // Vertex 1 (X, Y)
       -50.0f, -50.0f, 0.0f, // Vertex 2 (X, Y)
        50.0f,  50.0f, 0.0f, // Vertex 3 (X, Y)
    };


    glGenBuffers(1, &squareVBO); // Generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, squareVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(squareVertices), squareVertices, GL_STATIC_DRAW);

    return sizeof(squareVertices) / 3;
}


