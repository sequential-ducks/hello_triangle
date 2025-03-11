#include "shaders.hpp"

VertexShader::VertexShader()
{
    vertexShaderID_ = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID_, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderID_);
}

VertexShader::VertexShader(const char *source)
{
    vertexShaderID_ = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID_, 1, &source, NULL);
    glCompileShader(vertexShaderID_);
}

VertexShader::~VertexShader()
{
    vertexShaderSource = nullptr;
    delete vertexShaderSource;
}

