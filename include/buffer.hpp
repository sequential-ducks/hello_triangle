/**
 * @file bindings.hpp
 * @brief Header file for bound objects,  buffer processing and array objects
 */
#pragma once

#include <memory>
#include <glad/glad.h> 
#include <vector>

/**
 * @class VBO
 * @brief A class representing a Vertex Buffer Object (VBO) in OpenGL.
 * 
 * The VBO class is responsible for managing vertex buffer objects in OpenGL. 
 * It provides functionality to create, bind, and upload vertex data to the GPU. 
 * This class simplifies the process of handling vertex data and ensures 
 * efficient data transfer to the GPU.
 * 
 * @note The VBO class assumes that the OpenGL context has been properly 
 * initialized before any of its methods are called.
 * 
 * @section Usage
 * To use the VBO class, create an instance by passing a vector of vertex data 
 * and an optional draw type. The draw type determines the expected usage 
 * pattern of the data store and can be GL_STATIC_DRAW, GL_DYNAMIC_DRAW, or 
 * GL_STREAM_DRAW.
 * 
 * Example:
 * @code
 * std::vector<float> vertices = {
 *     -0.5f, -0.5f, 0.0f,
 *      0.5f, -0.5f, 0.0f,
 *      0.0f,  0.5f, 0.0f
 * };
 * VBO vbo(vertices, GL_STATIC_DRAW);
 * @endcode
 * 
 * @section Dependencies
 * This class requires the following dependencies:
 * - OpenGL headers (e.g., GL/glew.h, GL/gl.h)
 * - A valid OpenGL context
 * 
 * @section SeeAlso
 * - VAO (Vertex Array Object) class
 * - EBO (Element Buffer Object) class
 */
class VertexBuffer
{
public:

    /**
     * @fn VBO::VBO(const std::vector<float>& vertices, 
            const GLenum& DRAW_TYPE=GL_STATIC_DRAW);
     * @brief Default VBO constructor. 
     * 
     * This constructor generates a buffer, binds it to the GL_ARRAY_BUFFER 
     * target, and uploads the provided vertex data to the GPU using the 
     * specified draw type that affects write speed.
     * 
     * @param vertices a vector of floats Containing the vertex data to be 
     * uploaded to the GPU Buffer.
     * @param DRAW_TYPE openGl Enum The drawing usage type of the data. 
     * @return void This function does not return a value.
     */
    VBO(const std::vector<float>& vertices, 
            const GLenum& DRAW_TYPE=GL_STATIC_DRAW);
    
    /**
     * @brief Default destructor for the VBO class.
     * 
     * This destructor is defined as the default, meaning it will automatically
     * clean up any resources managed by the VBO class when an instance of the
     * class is destroyed.
     */
    ~VBO() = default;

    // Delete copy constructor and copy assignment operator.
    VBO(const VBO&) = delete;  
    VBO& operator=(const VBO&) = delete;

private:
    std::vector<float> defaultTriangleVertices_ =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    /**
     * @fn void VBO::bindBuffer();
     * @brief Bind generated VBO to OpenGL enum GL_ARRAY_BUFFER
     * @return void This function does not return a value.
     * @remark Further calls to GL_ARRAY_BUFFER will use the buffer_id of this 
     * VBO class object.
     */
    void bindBuffer();

    /**
    * @fn VBO::generateBufferID
    * @brief Sets buffer_id as a unique OpenGL buffer ID
    * @return void This function does not return a value.
    */
   void generateBufferID();

   /**
    * @var VBO::bufferID
    * @brief A smart pointer to IDs created for buffers. 
    * Default null. Creation of buffers is limited to 1.
    */
   std::unique_ptr<unsigned int> bufferID_;
};

class VAO
{

};