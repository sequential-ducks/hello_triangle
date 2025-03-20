/**
 * @file buffer.hpp
 * @brief Header file for buffer processing and array objects
 */
#pragma once
#include <glad/glad.h> 
#include <vector>

/**
 * @class BufferSetup
 * @brief A class encapsulating Vertex Buffer Objects and Vertex Array Objects
 * in OpenGL.
 * 
 * The BufferSetup class is responsible for managing buffer objects in 
 * OpenGL. It provides functionality to create, bind, and upload vertex data 
 * to the GPU. 
 * 
 * @note The BufferSetup class assumes that the OpenGL context has been properly 
 * initialized before any of its methods are called.
 * 
 * @section Usage
 * To use the BufferSetup class, create an instance by passing a vector of 
 * vertex data and an optional draw type. The draw type determines the expected 
 * usage pattern of the data store and can be GL_STATIC_DRAW, GL_DYNAMIC_DRAW, 
 * or GL_STREAM_DRAW.
 * 
 * Example:
 * @code
 * std::vector<float> vertices = {
 *     -0.5f, -0.5f, 0.0f,
 *      0.5f, -0.5f, 0.0f,
 *      0.0f,  0.5f, 0.0f
 * };
 * BufferSetup(vertices, GL_STATIC_DRAW);
 * @endcode
 * 
 * @section Dependencies
 * This class requires the following dependencies:
 * - OpenGL headers (e.g., GL/glew.h, GL/gl.h)
 * - A valid OpenGL context
 * - Vector header for vertice data
 * */
class BufferSetup
{
public:

    /**
     * @fn BufferSetup::BufferSetup(const std::vector<float>& vertices, 
            const GLenum& DRAW_TYPE=GL_STATIC_DRAW);
     * @brief Default BufferSetup constructor. 
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
    BufferSetup(const std::vector<float>& vertices, 
            const GLenum& DRAW_TYPE=GL_STATIC_DRAW);
    
    /**
     * @brief Default destructor for the BufferSetup class.
     * 
     * This destructor is defined as the default, meaning it will automatically
     * clean up any resources managed by the BufferSetup class when an instance of the
     * class is destroyed.
     */
    ~BufferSetup() = default;

    // Delete copy constructor and copy assignment operator.
    BufferSetup& operator=(const BufferSetup&) = delete;

    /**
     * @brief Getter for VBO_
     * 
     * This function returns the unique ID of the Vertex Buffer Object (VBO).
     * 
     * @return unsigned int The unique ID of the VBO.
     */
    unsigned int getVBOId() const { return VBO_; }

    /**
     * @brief Getter for VAO
     * 
     * This function returns the unique ID of the Vertex Array Object (VAO).
     * 
     * @return unsigned int The unique ID of the VAO.
     */
    unsigned int getVAOId() const { return VAO_; }

private:
   /**
    * @brief ID created for Vertex Buffer. 
    **/
   unsigned int VBO_;

    /**
    * @brief ID created for Vertex Array Object. 
    **/
   unsigned int VAO_;
};
