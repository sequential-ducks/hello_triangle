/**
 * @file buffers.hpp
 * @brief Header file for buffer processing
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
class Buffers{

protected:
    /**
     * @subsection Protected Member Functions
     */
    /**
    * @name Buffers::generateBufferID
    * @brief Sets buffer_id as a unique OpenGL buffer ID
    */
    void generateBufferID();
    /**
     * @name Buffers::bindBuffer
     * @brief After this, any buffer calls to buffers' set by BUFFER_TYPE
     * will reference the buffer type and it's buffer id.  
     */
    void bindBuffer(const GLenum &BUFFER_TYPE);
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
class VBO : public Buffers{
public:
    /**
    * @subsection Constructors
    */
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

    /**
    * @subsection Destructors
    */
    /**

protected:
    /**
     * @subsection Protected Member Functions
     */
    /**
     * @name VBO::bindBuffer 
     * @brief Sets the buffer_id binded to the vertex buffer
     * @remark Calls to GL_ARRAY_BUFFER will use the buffer_id of the 
     *                VBO class object.
     */
    void bindBuffer(const GLenum bufferType = GL_ARRAY_BUFFER);

private:

    std::vector<float> two_dimensional_triangle_ =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
};
    