#include <memory>
#include <glad/glad.h> 
#include <vector>

/**
 * @class Buffers.
 * @brief Base class for datastructures in GPU's memory enabling data to be sent 
 *        from cpu to gpu in batches. Specific buffers inherit from this class.
 */
class Buffers{
public:
    /**
    * @subsection Constructors
    */
    /**
    * @subsection Destructors
    */
    /**
    * @subsection Public Member Functions
    */        
    /**
    * @subsection Getters
    */
    /**
    * @subsection Setters
    */



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
    std::unique_ptr<unsigned int> buffer_id{ nullptr };


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
    VBO(const std::vector<float>& vertices, const GLenum& DRAW_TYPE=GL_STATIC_DRAW);

    /**
    * @subsection Destructors
    */
    /**
    * @subsection Public Member Functions
    */

    /**
    * @subsection Getters
    */
    /**
    * @subsection Setters
    */

protected:
    /**
     * @subsection Protected Member Functions
     */
    /**
     * @name VBO::bindBuffer 
     * @brief @remark Calls to GL_ARRAY_BUFFER will use the buffer_id of the 
     *                VBO class object.
     */
    void bindBuffer(const GLenum GL_ARRAY_BUFFER);


private:

    std::vector<float> two_dimensional_triangle[] =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
};
    