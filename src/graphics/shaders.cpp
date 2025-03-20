#include "shaders.hpp"

void Shader::generateID(GLenum shaderType)
{
    shaderID_ = glCreateShader(shaderType);
}

void Shader::compileShader()
{
    glShaderSource(shaderID_, 1, &shaderSource_, NULL);
    glCompileShader(shaderID_);
}


void Shader::checkShaderCompilation(const std::string& shaderType)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shaderID_, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderID_, 512, NULL, infoLog);
        throw std::logic_error(std::string("ERROR::SHADER::") + shaderType + 
                                std::string("::COMPILATION_FAILED\n ") 
                                + infoLog);
    }
}


VertexShader::VertexShader(const char *source) 
    : Shader(source)
{
    generateID(GL_VERTEX_SHADER);
    compileShader();
    checkShaderCompilation("VERTEX");
}


FragmentShader::FragmentShader(const char *source) 
    : Shader(source)
{
    generateID(GL_FRAGMENT_SHADER);
    compileShader();
    checkShaderCompilation("FRAGMENT");
}

Program::Program(const unsigned int vertexShaderID, const unsigned int fragShaderID)
{
    int success;
    char infoLog[512];
    shaderProgram_ = glCreateProgram();
    glAttachShader(shaderProgram_, vertexShaderID);
    glAttachShader(shaderProgram_, fragShaderID);
    glLinkProgram(shaderProgram_);
    // check for linking errors
    glGetProgramiv(shaderProgram_, GL_LINK_STATUS, &success);
    if (!success) 
    {
        glGetProgramInfoLog(shaderProgram_, 512, NULL, infoLog);
        throw std::logic_error(std::string("ERROR::SHADER::PROGRAM::LINKING_FAILED\n") 
        + infoLog);
    }
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragShaderID);
}
