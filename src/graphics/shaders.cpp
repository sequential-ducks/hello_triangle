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

void VertexShader::checkShaderCompilation()
{
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShaderID_, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShaderID_, 512, NULL, infoLog);
        throw std::logic_error(std::string("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n ") 
                                + infoLog);
    }

}
