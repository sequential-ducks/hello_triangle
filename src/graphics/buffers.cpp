#include "buffers.hpp"

void Buffers::generateBufferID()
{
    glGenBuffers(1, &buffer_id);
}

void VBO::bindBuffer(const GLenum GL_ARRAY_BUFFER)
{
    glBindBuffer(BUFFER_TYPE, buffer_id);

}


VBO::VBO(const std::vector<float> &vertices, const GLenum &DRAW_TYPE)
{
    generateBuffer();
    bindBuffer(GL_ARRAY_BUFFER);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 vertices.data(), DRAW_TYPE);
}


