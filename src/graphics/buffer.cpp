#include "buffer.hpp"

BufferSetup::BufferSetup(const std::vector<float> &vertices, 
                            const GLenum &DRAW_TYPE)
{
    // Generate and bind VAO first
    glGenVertexArrays(1, &VAO_);
    glBindVertexArray(VAO_);

    // Then generate and bind VBO
    glGenBuffers(1, &VBO_);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_);
    
    // Copy vertex data
    glBufferData(GL_ARRAY_BUFFER, 
                    vertices.size() * sizeof(float), 
                    vertices.data(), 
                    DRAW_TYPE);

    // Set vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  // Enable vertex attribute 0

    // Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


