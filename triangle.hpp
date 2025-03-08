#pragma once
#include <memory>

/**
* @include Headers
*/


/**
 * @namespace opengl_primitives
 * @brief Holds arrays of float values that represent primitives in 
 * Normalized 3D Device Coordinates (values between -1.0 and 1.0)
 */
namespace opengl_primitives 
{
    float two_dimensional_triangle[] =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

};

/**
 * @class Buffers.
 * @brief Datastructures in GPU's memory enabling data to be sent from cpu to 
 *        gpu in batches.
 * @note VBO = Vertex Buffer Object
 */
class Buffers
{
public:
    /**
     * @brief Initializes an object that holds space for vertices on the 
     *        GPU's memory.
     * @note Assigns an ID for the Vertex Buffer Object.
     */
    void VBO();

private:
    /**
     * @var Buffers::VBO
     * @brief ID of a vertex buffer. Default null.
     * @remark It is presumed that there is only one for now but this is an 
     *         arbitrary limit.
     */
    std::unique_ptr<unsigned int> VBO{ nullptr };


};
