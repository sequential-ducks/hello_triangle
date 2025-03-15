/**
 * @file buffers.hpp
 * @brief Header file for buffer processing
 * @return void This constructor does not return a value.
 */
#pragma once

#include <memory>
#include <glad/glad.h> 
#include <vector>

/**
 * @class Buffers.
 * @brief Base class for datastructures in GPU's memory enabling data to be sent 
 *        from cpu to gpu in batches. Specific buffers inherit from this class.
 */
class Buffers
{
protected:
    /**
    * @fn Buffers::generateBufferID
    * @brief Sets buffer_id as a unique OpenGL buffer ID
    * @return void This function does not return a value.
    */
    void generateBufferID();

    /**
     * @var Buffers::bufferID
     * @brief A smart pointer to IDs created for buffers. 
     * Default null. Creation of buffers is limited to 1.
     */
    std::unique_ptr<unsigned int> bufferID;

    /**
     * @var Buffers::buffer_id
     * @brief A smart pointer to IDs created for buffers. 
     * Default null. Creation of buffers is limited to 1.
     */
    std::unique_ptr<unsigned int> buffer_id;


};
    
/**
 * @class VBO 
 * @brief Vertex Buffer Object, public inheritance from Buffers.
 */
class VBO : public Buffers
{
public:
    /**
     * @brief Constructs a Vertex Buffer Object (VBO) and initializes it with 
     *        vertex data.
     * 
     * This constructor generates a buffer, binds it to the GL_ARRAY_BUFFER 
     * target, and uploads the provided vertex data to the GPU using the 
     * specified draw type that affects write speed.
     * 
     * @param vertices A vector containing the vertex data to be uploaded to the GPU.
     * @param DRAW_TYPE The usage pattern of the data store. It can be 
     *                  GL_STATIC_DRAW, GL_DYNAMIC_DRAW, or GL_STREAM_DRAW, 
     *                  which determine the expected 
     *                  usage pattern of the data and needed write speeds.
     */
    VBO(const std::vector<float>& vertices, const GLenum& DRAW_TYPE=GL_STATIC_DRAW);

protected:
    /**
     * @fn void VBO::bindBuffer(const GLenum bufferType = GL_ARRAY_BUFFER);
     * @param bufferType OpenGL buffer enum of buffer to bind.
     * @return void This function does not return a value.
     * @remark Calls to GL_ARRAY_BUFFER will use the buffer_id of the VBO class 
     * object.
     */
    void bindBuffer(const GLenum bufferType = GL_ARRAY_BUFFER);

private:
    std::vector<float> defaultTriangleVertices =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
};
    