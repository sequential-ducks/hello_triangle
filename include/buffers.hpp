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
    * @name generateBuffer
    * @brief Sets buffer_id as an unique id of a generated buffer
    */
    void generateBuffer();
    /**
     * @name bindBuffer
     * @brief After this, any buffer calls to buffers' set by BUFFER_TYPE
     * will reference the buffer type and it's buffer id. 
     * @remark For example GL_ARRAY_BUFFER sets the vertex buffer, and such
     * calls to GL_ARRAY_BUFFER will use the buffer_id of the VBO class object. 
     */
    void bindBuffer(const auto &BUFFER_TYPE);
    /**
     * @var Buffers::buffer_ids
     * @brief A smart pointer to a vector of ID's creacted for buffers. 
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
    VBO(const auto vertexArray, const auto& DRAW_TYPE);

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
    


};
    