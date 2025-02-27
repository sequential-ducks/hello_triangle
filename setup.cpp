/**
* @include Headers
*/
#include "setup.hpp"
#include <cstdio>

/**
* @section Static members
*/

/**
* @var My_GLFW_Window_Manager::initialization_success
* @brief Flag indicating whether GLFW and window initialization was 
* successful (default true).
*/
bool My_GLFW_Window_Manager::initialization_success{ true };
/**
 * @var My_GLFW_Window_Manager::window
 * @brief Pointer to the GLFW window.
 */
GLFWwindow* My_GLFW_Window_Manager::window{ nullptr };

/**
 * @var My_GLFW_Window_Manager::windowWidth
 * @brief Width of the window (default 640).
 */
int My_GLFW_Window_Manager::windowWidth{ 640 };

/**
 * @var My_GLFW_Window_Manager::windowHeigth
 * @brief Height of the window (default 480).
 */
int My_GLFW_Window_Manager::windowHeight{ 480 };

/**
 * @var My_GLFW_Window_Manager::title
 * @brief Title of the window.
 */
const char* My_GLFW_Window_Manager::title{ "LearnOpenGL" };

/**
* @section Constructor & Initialization
*/

My_GLFW_Window_Manager::My_GLFW_Window_Manager()
{
    My_GLFW_Window_Manager::initialize();
}

void My_GLFW_Window_Manager::initialize()
{
    // Try to initialize GLFW
    if ( !openGLFW() )
    {
        // If initialization fails, exit with failure status
        setInitializationSuccess(false);
        return;
    }

    // Try to create GLFW window
    if ( !createWindow() )
    {
        // If window creation fails, exit with failure status
        setInitializationSuccess(false);
        return;
    }
    // Try to load OpenGL functions
    if ( !gladLoadGLLoader( ( GLADloadproc ) glfwGetProcAddress ) )
    {
        setInitializationSuccess(false);
        return;
    }
    // Set the size of the initial OpenGL rendering context
    glViewport( 0, 0, getWindowWidth(), getWindowHeight() );
    // Attach a function to adjust the size of the viewport to resizing event
    glfwSetFramebufferSizeCallback( getWindow(), window_resize );

    return;
    
}

/**
* @section Destructor
*/

My_GLFW_Window_Manager::~My_GLFW_Window_Manager() 
{
    terminate_GLFW_Window_Manager();
}

void My_GLFW_Window_Manager::terminate_GLFW_Window_Manager() 
{
    // Destroy the window if it exists
    if ( window ) {
        glfwDestroyWindow( window );
        window = nullptr;
    }
    // Terminate GLFW
    glfwTerminate();
}

/**
* @section Setup Member functions
*/

bool My_GLFW_Window_Manager::openGLFW()
{
    // Initialization flag
    bool success{ true };

    // Attempt to initialize GLFW
    if ( !glfwInit() )
    {
        success = false;
        // Variable to store error message
        const char* glfw_init_errors = nullptr;
        // Get the error code
        int error_code = glfwGetError( &glfw_init_errors );
        // If there is an error message, print it
        if ( glfw_init_errors )
        {
            std::printf( "GLFW initialization failed with error code %d: %s\n", 
                          error_code, glfw_init_errors );
        }
    }else
    {
        // Set the openGL version as 3.3 per tutorial at learnopengl.com
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
        // Request core OpenGL profile
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    }
    
    return success;
}


bool My_GLFW_Window_Manager::createWindow()
{
    bool success{ true };

    // Try to generate a window
    if( ( window = glfwCreateWindow( windowWidth, windowHeight, title, nullptr, 
                                     nullptr ) ) == nullptr )
        {
            // Window generating failed
            success = false;
            // Variable to store error message
            const char* glfw_window_errors = nullptr;
            // Get the error code
            int error_code = glfwGetError( &glfw_window_errors );
            // If there is an error message, print it
            if ( glfw_window_errors )
            {
                std::printf( "GLFW window generating failed with error code %d: %s\n", 
                             error_code, glfw_window_errors );
            }
            // Clean up the initialized GLFW library
            glfwTerminate();
        }else
        {
            // Set created window as main context
            glfwMakeContextCurrent( window );
        }

        return success;                                     
}

/**
 * @section Rendering Member functions 
 */

void My_GLFW_Window_Manager::processInput()
{
    // Check if the escape key is pressed
    if ( glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
    {
        glfwSetWindowShouldClose( window, true );
    }
}

void My_GLFW_Window_Manager::display()
{
    // Main loop until the window should close
    while( !glfwWindowShouldClose( window ) )
    {
        /**
        * @subsection Input handling
        */
        processInput();
        /**
        * @subsection Frame rendering logic
        */
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        /**
        * @subsection Buffers swap & event handling
        */
        // Swap front and back buffers
        glfwSwapBuffers( window );
        // Poll for and process events
        glfwPollEvents();
    }
}
