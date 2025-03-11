#include "buffers.hpp"

void Buffers::generateBufferID()
{
    glGenBuffers(1, buffer_id.get());
}

void VBO::bindBuffer( const GLenum bufferType )
{
    glBindBuffer( bufferType, *buffer_id );

}


VBO::VBO(const std::vector<float> &vertices, const GLenum &DRAW_TYPE)
{
    generateBufferID();
    bindBuffer(GL_ARRAY_BUFFER);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 vertices.data(), DRAW_TYPE);
}


