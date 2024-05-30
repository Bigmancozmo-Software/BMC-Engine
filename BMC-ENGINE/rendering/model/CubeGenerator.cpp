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