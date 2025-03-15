#include "shaders.hpp"

void Shader::generateID(GLenum shaderType)
{
    shaderID_ = glCreateShader(shaderType);
    shaders_.push_back(shaderID_);
}

void Shader::compileShader()
{
    if (shaderID_ != 0)
    {
        glShaderSource(shaderID_, 1, &shaderSource_, NULL);
        glCompileShader(shaderID_);
    }
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

void Shader::generateProgramID()
{
    programID_ = glCreateProgram();
}

void Shader::checkProgramCompilation()
{
    int success;
    char infoLog[512];
    glGetProgramiv(programID_, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(programID_, 512, NULL, infoLog);
        throw std::logic_error(std::string("ERROR::PROGRAM::LINKING_FAILED\n") 
                                + infoLog);
    }
}

unsigned int Shader::linkProgram()
{
    generateProgramID();
    if (programID_ != 0 and !shaders_.empty())
    {
        for (const auto &s : shaders_)
        {
            glAttachShader(programID_, s);
            glDeleteShader(s);
        }
        glLinkProgram(programID_);
    }
    checkProgramCompilation();
    glUseProgram(programID_);
    return programID_;
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

