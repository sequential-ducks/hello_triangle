
/**
* @include Headers
*/
#include "window.hpp"
#include "buffers.hpp"
#include "shaders.hpp"
#include <iostream>

/**
 * @section main
 */
int main()
{
    // Create an instance of My_GLFW_Window_Manager
    My_GLFW_Window_Manager windowManager;

    // Check if initialization was successful
    if( !windowManager.getInitialization() )
    {
        // If initialization fails, exit the program
        exit(EXIT_FAILURE);
    }
    // Compile a Vertex Shader
    try
    {
        auto vertexShader = VertexShader();
    }catch( const std::logic_error& except)
    {
        std::cout << except.what();
        return 1;
    }
    // Enter the display loop
    windowManager.display();
    // Program executed successfully
    return 0;
}