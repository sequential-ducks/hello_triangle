#include "window.hpp"

/**
* @var My_GLFW_Window_Manager::initialization_success
* @brief Flag indicating whether GLFW and window initialization was 
* successful (default true).
*/
bool My_GLFW_Window_Manager::initialization_success_{ true };
/**
 * @var My_GLFW_Window_Manager::window
 * @brief Pointer to the GLFW window.
 */
std::shared_ptr<GLFWwindow> My_GLFW_Window_Manager::window_{ nullptr, 
                                                            glfwDestroyWindow };

/**
 * @var My_GLFW_Window_Manager::windowWidth
 * @brief Width of the window (default 640).
 */
int My_GLFW_Window_Manager::windowWidth_{ 640 };

/**
 * @var My_GLFW_Window_Manager::windowHeigth
 * @brief Height of the window (default 480).
 */
int My_GLFW_Window_Manager::windowHeight_{ 480 };

/**
 * @var My_GLFW_Window_Manager::title
 * @brief Title of the window.
 */
const std::string My_GLFW_Window_Manager::title_{ "Triangle" };

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
            glfw_init_errors = nullptr;
            delete glfw_init_errors;
            return false;
        }
    delete glfw_init_errors;
    }else
    {
        // Set the openGL version as 3.3 
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
    window_.reset(glfwCreateWindow(windowWidth_,
                             windowHeight_, title_.c_str(), nullptr, nullptr), 
                             glfwDestroyWindow);
    if (!window_)
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
            glfwMakeContextCurrent( window_.get());
        }

        return success;                                     
}

/**
 * @section Rendering Member functions 
 */

void My_GLFW_Window_Manager::processInput()
{
    // Check if the escape key is pressed
    if ( glfwGetKey( window_.get() , GLFW_KEY_ESCAPE ) == GLFW_PRESS )
    {
        glfwSetWindowShouldClose( window_.get(), true );
    }
}

void My_GLFW_Window_Manager::display()
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

    const char *fragmentShaderSource = 
    "#version 330 core\n"
    // Define out variable as FragColor.
    "out vec4 FragColor;\n"
    "void main()\n"
    // Define value of FragColor as orange with 100% opacity.
    "{\n"
    "   FragColor = vec4(0.5f, 1.0f, 0.2f, 1.0f);\n"
    "}\n\0";

    std::vector<float> defaultTriangleVertices_ =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    std::unique_ptr<Program> shaderProgram;
    std::unique_ptr<BufferSetup> buffer;
    try
    {
        // Create shader objects, if fail throws logic error
        auto vertexShader = VertexShader(vertexShaderSource);
        auto fragShader = FragmentShader(fragmentShaderSource);

        // Use the compiled shaders to get a linked shader program
        shaderProgram = std::make_unique<Program>
        (Program(vertexShader.getShaderID(), fragShader.getShaderID()));

        // Move triangle data to the GPU buffer
        buffer = std::make_unique<BufferSetup>
                            (BufferSetup(defaultTriangleVertices_));
    }
    catch( const std::logic_error& except)
    {
        std::cout << except.what();
        return;
    }
    // Check for OpenGL errors
    GLenum err;
    if ((err = glGetError()) != GL_NO_ERROR) 
    {
        std::cout << "OpenGL error: " << err << std::endl;
    }
    // Main loop until the window should close
    while( !glfwWindowShouldClose( window_.get() ) )
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

        // Drawing logic for a triangle
        glUseProgram(shaderProgram->getProgramID());
        glBindVertexArray(buffer->getVAOId()); 
        glDrawArrays(GL_TRIANGLES, 0, 3);
        /**
        * @subsection Buffers swap & event handling
        */
        // Swap front and back buffers
        glfwSwapBuffers( window_.get() );
        // Poll for and process events
        glfwPollEvents();
    }
}
