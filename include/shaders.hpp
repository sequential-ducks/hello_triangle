/**
 * @file shaders.hpp
 * @brief Header file for shader-related classes and functions.
 */

#pragma once
#include <glad/glad.h>
#include <cstddef>
#include <stdexcept>


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
    */
    Shader(const char* source) : shaderSource_(source), shaderID_{0}{};

    /**
     * @fn Shader::virtual ~Shader()
     * @brief Default virtual destructor.
     */
    virtual ~Shader() = default;

    // Delete copy constructor and copy assignment operator
    Shader(const Shader&) = delete;  
    Shader& operator=(const Shader&) = delete;  

protected:
    /**
     * @fn void Shader::checkShaderCompilation()
     * @brief Checks if any errors happened and if a shader was compiled.
     * @throws std::logic_error if shader compilation failed.
    */
    void checkShaderCompilation();

    /**
     * @fn void Shader::compileShader();
     * @brief Compiles the shader from the provided source code that also 
     * determines the type of the shader.
     * @note Requires that shaderID_ is set properly to a nonzero value.
    */
    void compileShader();

    /**
     * @var shaderSource_
     * @brief Contains the GLSL source code for the shader.
     */
    const char* shaderSource_;

    /** 
     * @var shaderID_
     * @brief An unsigned integer representing the compiled shader.
    */
    unsigned int shaderID_;
};


/**
 * @class VertexShader
 * @brief A class representing a vertex shader.
 * 
 * This class is derived from the Shader class and is used to handle vertex shaders.
 * It provides functionality to construct a vertex shader with given source code
 * and to generate an ID for the shader.
**/
class VertexShader : protected Shader
{
public:
    /**
     * @fn VertexShader::VertexShader(const char* source)
     * @brief Constructs a VertexShader object with the given source code.
     * @param source The source code for the vertex shader.
     */
    VertexShader(const char* source);

    /**
     * @fn VertexShader::~VertexShader()
     * @brief Default destructor for the VertexShader class.
    */
    ~VertexShader() = default;

    // Delete copy constructor and copy assignment operator
    VertexShader(const VertexShader&) = delete;  
    VertexShader& operator=(const VertexShader&) = delete;  

protected:
    /**
     * @fn void VertexShader::generateID()
     * @brief Generates an ID for the vertex shader.
     */
    void generateID();

};

class FragmentShader : protected Shader
{
public:
    /**
     * @fn FragmentShader::FragmentShader(const char* source);
     * @brief Constructs a FragmentShader object with the given source code.
     * @param source The source code for the vertex shader.
     */
    FragmentShader(const char* source);

    /**
     * @fn FragmentShader::~FragmentShader()
     * @brief Default destructor for the FragmentShader class.
    */
    ~FragmentShader() = default;

    // Delete copy constructor and copy assignment operator
    FragmentShader(const FragmentShader&) = delete;  
    FragmentShader& operator=(const FragmentShader&) = delete;  

protected:
    /**
     * @fn void FragmentShader::generateID()
     * @brief Generates an ID for the frag shader.
     */
    void generateID();

};