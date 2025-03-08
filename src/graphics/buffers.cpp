#include "buffers.hpp"

void Buffers::generateBufferID()
{
    glGenBuffers(&buffer_id);
}

void VBO::bindBuffer(const GLenum GL_ARRAY_BUFFER)
{
    glBindBuffer(BUFFER_TYPE, &buffer_id);

}

VBO::VBO(const std::vector<float> &vertices, const GLenum &DRAW_TYPE=GL_STATIC_DRAW)
{
    generateBuffer();
    bindBuffer(GL_ARRAY_BUFFER);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, DRAW_TYPE);
}


