

#pragma once
#include <memory>
#include <glad/glad.h> 

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

