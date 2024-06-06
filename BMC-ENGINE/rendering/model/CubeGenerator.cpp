#include "Generators.h"

void CubeGenerator::vertices(GLfloat verts[], float size)
{
    static const GLfloat defaultVerts[] = {
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
    };

    const int numVerts = sizeof(defaultVerts) / sizeof(defaultVerts[0]);

    for (int i = 0; i < numVerts; ++i) {
        verts[i] = defaultVerts[i] * size;
    }
}

void CubeGenerator::indices(GLuint inds[])
{
    GLuint defaultInds[] = {
        0, 1, 3,
        1, 2, 3,
        4, 5, 7,
        5, 6, 7,
        1, 2, 4,
        2, 4, 7,
        1, 4, 5,
        0, 1, 5,
        0, 5, 6,
        0, 3, 6,
        2, 6, 7,
        2, 3, 6
    };

    const int numVerts = sizeof(defaultInds) / sizeof(defaultInds[0]);
    std::cout << numVerts << std::endl;

    for (int i = 0; i < numVerts; ++i) {
        inds[i] = defaultInds[i];
    }
}
