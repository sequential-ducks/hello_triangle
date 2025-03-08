/**
* @include Headers
*/

#include "window.hpp"
#include "primitives.hpp"
#include "buffers.hpp"
#include <stdlib.h> // For exit()
#include <iostream>
#include <cstdlib>


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
    
    // Enter the display loop
    windowManager.display();
    // Print success message
    std::cout << "Success!" << std::endl;
    // Program executed successfully
    return 0;
}