#include "buffers.hpp"

void Buffers::generateBuffer()
{
    glGenBuffers(&buffer_id);
}

void Buffers::bindBuffer(const auto &BUFFER_TYPE)
{
    glBindBuffer(BUFFER_TYPE, &buffer_id);

}

VBO::VBO(const auto vertexArray, const auto &DRAW_TYPE)
{
    generateBuffer();
    bindBuffer(GL_ARRAY_BUFFER);
}
