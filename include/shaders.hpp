/**
 * @file shaders.hpp
 * @brief Header file for shader-related classes and functions.
 */

#pragma once

#include <glad/glad.h>
#include <cstddef>
#include <stdexcept>
#include <memory> // !!NOT USED YET!! Possibly turn char naked ptr to smart?

class ShaderBase

{
public:

}
/**
 * @class VertexShader
 * @brief A class that encapsulates a simple vertex shader in OpenGL.
 * 
 * This class provides a basic implementation of a vertex shader using GLSL.
 * The vertex shader simply forwards its input position to the output.
 * 
 * @remark The GLSL version used is 330 core.
 * @remark The input variable location is set to 0.
 * 
 */
class VertexShader
{
public:
    /**
     * @fn VertexShader::VertexShader()
     * @brief Creates a new vertex shader object and assigns its' ID to 
     * the member vertexShader_
     * @remark Default constructor for the VertexShader class. 
     */
    VertexShader();

    /**
     * @fn VertexShader::VertexShader(const char* source)
     * @brief Creates a new vertex shader object from the provided source code.
     * @param source A constant character pointer to the GLSL source code for 
     *               the vertex shader.
     */
    VertexShader(const char* source);
    /*
    * @fn VertexShader::~VertexShader()
    * @brief Default virtual destructor for the VertexShader class.
    */
    virtual ~VertexShader();

private:
    /**
     * @fn checkShaderCompilation
     * @brief Checks if any errors happened and if a shader
     * was compiled. 
     * @throws Logic error if shader compilation failed
     */
    void checkShaderCompilation();

    /**
     * @var VertexShader::vertexShaderSource
     * @brief A constant character pointer containing the GLSL source code for 
     * the vertex shader.
     */
    const char *vertexShaderSource = "#version 330 core\n"
    // Defining variables 
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    // Setting drawing position on the viewport, same as input.
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" 
    "}\0";

    /** 
     * @var VertexShader::vertexShader_
     * @brief An unsigned integer representing the compiled vertex shader.
    */
    unsigned int vertexShaderID_;
};
