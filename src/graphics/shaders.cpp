#include "shaders.hpp"


void Shader::checkShaderCompilation()
{
    int success;
    char infoLog[512];
    glGetShaderiv(shaderID_, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderID_, 512, NULL, infoLog);
        throw std::logic_error(std::string("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n ") 
                                + infoLog);
    }
}

void Shader::compileShader()
{
    if (shaderID_)
    {
        glShaderSource(shaderID_, 1, &shaderSource_, NULL);
        glCompileShader(shaderID_);
    }
}

void VertexShader::generateID()
{
    shaderID_ = glCreateShader(GL_VERTEX_SHADER);
}

VertexShader::VertexShader(const char *source) : Shader(source)
{
    generateID();
    compileShader();
    checkShaderCompilation();
}


FragmentShader::FragmentShader(const char *source) : Shader(source)
{
    generateID();
    compileShader();
    checkShaderCompilation();
}

void FragmentShader::generateID()
{
    shaderID_ = glCreateShader(GL_FRAGMENT_SHADER);
}
