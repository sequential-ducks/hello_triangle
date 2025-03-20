/**
 * @file shaders.hpp
 * @brief Header file for shader-related classes and functions.
 * This file contains the declarations of classes and functions used for 
 * managing and compiling GLSL shaders in an OpenGL context. It includes 
 * the base class `Shader` which provides common functionality for shader 
 * management, as well as derived classes `VertexShader` and `FragmentShader` 
 * for handling specific types of shaders.
 * 
 * The `Shader` class includes methods for generating shader IDs, 
 * compiling shaders,linking shader programs, and checking for compilation 
 * errors. It also manages the source GLSL code and IDs of shaders and shader 
 * programs.
 * 
 * The `VertexShader` and `FragmentShader` classes inherit from `Shader` and 
 * provide specific implementations for vertex and fragment shader generation, 
 * respectively.
 * 
 * This header file is essential for setting up and managing shaders in an OpenGL 
 * application, ensuring that shaders are correctly compiled and linked into 
 * executable programs.
 */

#pragma once
#include <glad/glad.h>
#include <cstddef>
#include <stdexcept>
#include <vector>


 
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
    Shader(const char* source) : shaderSource_(source), shaderID_{0}{};

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
     * @fn unsigned int Shader::getShaderID() const
     * @brief Getter for the shader ID.
     * @return The shader ID.
     */
    unsigned int getShaderID() const { return shaderID_; }

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

class Program
{
public:
    Program(const unsigned int vertexShaderID, const unsigned int fragShaderID);
    ~Program() = default;

    /**
     * @fn unsigned int Program::getProgramID() const
     * @brief Getter for the shader program ID.
     * @return The shader program ID.
     */
    unsigned int getProgramID() const { return shaderProgram_; }

private:
    unsigned int shaderProgram_;
};;