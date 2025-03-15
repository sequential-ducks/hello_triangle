/**
 * @file shaders.hpp
 * @brief Header file for shader-related classes and functions.
 */

#pragma once
#include <glad/glad.h>
#include <cstddef>
#include <stdexcept>
#include <vector>
#include <iostream>

/**
 * @class Shader
 * @brief A class representing a GLSL shader.
 * This class provides functionality to manage and compile GLSL shaders.
 * It holds the shader source code and the compiled shader ID.
 */
class Shader
{
public:
    /**
     * @fn Shader::Shader(const std::string& source)
     * @brief Initializes source data from the provided source code.
     * @param source The GLSL source code for the shader.
     * @return void This function does not return a value.
    */
    Shader(const char* source) : shaderSource_(source), shaderID_{0}, 
                                 programID_{0}{};

    /**
     * @fn Shader::virtual ~Shader()
     * @brief Default virtual destructor.
     * @return void This function does not return a value.
     */
    virtual ~Shader() = default;

    // Delete copy constructor and copy assignment operator.
    Shader(const Shader&) = delete;  
    Shader& operator=(const Shader&) = delete;

    /**
     * @fn unsigned int Shader::linkProgram
     * @brief Attaches shaders to form a linked shader program.
     * @return unsigned int The ID of a linked program.
     * @throws 
     */
    unsigned int linkProgram();

protected:

    /**
     * @fn void Shader::generateID(GLenum shaderType);
     * @brief Generates a shader ID for the specified shader type.
     * This function creates a new shader object and assigns it an ID based on 
     * the provided shader type. The shader type must be one of the valid 
     * OpenGL shader types, such as GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
     * @param shaderType The type of shader to generate. 
     * Must be a valid GLenum value representing a shader type.
     * @return void This function does not return a value.
     */
    void generateID(GLenum shaderType);

    /**
     * @fn void Shader::checkShaderCompilation(const std::string &shaderType);
     * @brief Checks if any errors happened and if a shader was compiled.
     * @throws std::logic_error if shader compilation failed.
     * @return void This function does not return a value.
    */
    void checkShaderCompilation(const std::string &shaderType);

    /**
     * @fn void Shader::compileShader();
     * @brief Compiles the shader from the provided source code that also
     * determines the type of the shader.
     * @note Requires that shaderID_ is set properly to a nonzero value.
     * @return void This function does not return a value.
     */
    void compileShader();

    void generateProgramID();
    /**
     * @fn void Shader::checkProgramCompilation();
     * @brief Checks if any errors happened and if a program was compiled.
     * @throws std::logic_error if program compilation failed.
     * @return void This function does not return a value.
    */
    void checkProgramCompilation();


    /**
     * @var shaderSource_
     * @brief Contains the GLSL source code for the shader.
     */
    const char* shaderSource_;

    /** 
     * @var shaderID_
     * @brief An unsigned integer representing a compiled shader from a 
     * derived class object.
    */
    unsigned int shaderID_;

    /** 
     * @var shaders_
     * @brief Container for all compiled shaders from deriving classes.
    */
    std::vector<unsigned int> shaders_;

    /**
     * @var programID_
     * @brief Holds the ID of the linked program.
     */
    unsigned int programID_;
};


/**
 * @class VertexShader
 * @brief A class representing a vertex shader.
 * 
 * This class is derived from the Shader class and is used to handle vertex shaders.
 * It provides functionality to construct a vertex shader with given source code
 * and to generate an ID for the shader.
**/
class VertexShader : public Shader
{
public:
    /**
     * @fn VertexShader::VertexShader(const char* source)
     * @brief Constructs a VertexShader object with the given source code.
     * @param source The source code for the vertex shader.
     * @return void This function does not return a value.
     */
    VertexShader(const char* source);

    /**
     * @fn VertexShader::~VertexShader()
     * @brief Default destructor for the VertexShader class.
     * @return void This function does not return a value.
    */
    ~VertexShader() = default;

    // Delete copy constructor and copy assignment operator
    VertexShader(const VertexShader&) = delete;  
    VertexShader& operator=(const VertexShader&) = delete;  

};

class FragmentShader : public Shader
{
public:
    /**
     * @fn FragmentShader::FragmentShader(const char* source);
     * @brief Constructs a FragmentShader object with the given source code.
     * @param source The source code for the vertex shader.
     * @return void This function does not return a value.
     */
    FragmentShader(const char* source);

    /**
     * @fn FragmentShader::~FragmentShader()
     * @brief Default destructor for the FragmentShader class.
     * @return void This function does not return a value.
    */
    ~FragmentShader() = default;

    // Delete copy constructor and copy assignment operator
    FragmentShader(const FragmentShader&) = delete;  
    FragmentShader& operator=(const FragmentShader&) = delete;  

};