#include "bindings.hpp"

void VBO::generateBufferID()
{
    glGenBuffers(1, bufferID_.get());
}

void VBO::bindBuffer()
{
    glBindBuffer( GL_ARRAY_BUFFER, *bufferID_ );

}


VBO::VBO(const std::vector<float> &vertices, const GLenum &DRAW_TYPE)
{
    generateBufferID();
    bindBuffer();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 vertices.data(), DRAW_TYPE);
}


