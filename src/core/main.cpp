
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
    // Compile shaders
    try
    {
        // Defining GLSL code for the vertex shader
        const char *vertexShaderSource = 
        "#version 330 core\n"
        // Start location is 0, out variable aPos is triangle position
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        // Setting drawing position on the viewport, same as input.
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" 
        "}\0";
        // Create a vertex shader object, if fail throws logic error
        auto vertexShader = VertexShader(vertexShaderSource);

        const char *fragmentShaderSource = 
        "#version 330 core\n"
        // Define out variable as FragColor.
        "out vec4 FragColor;\n"
        "void main()\n"
        // Define value of FragColor as orange with 100% opacity.
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";
        auto fragShader = FragmentShader(fragmentShaderSource);
    }
    catch( const std::logic_error& except)
    {
        std::cout << except.what();
        return 1;
    }
    // Enter the display loop
    windowManager.display();
    // Program executed successfully
    return 0;
}