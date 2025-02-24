#pragma once

/**
* @include Headers
*/

#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <cstdio>

/**
* @section Classes 
*/

/**
 * @class My_GLFW_Window_Manager
 * @brief Manages the creation and lifecycle of a GLFW window with OpenGL context.
 * 
 * This class handles the initialization of GLFW, creation of a window, and setting up
 * the OpenGL context. It also provides utility functions to get window properties and
 * resize the OpenGL viewport when the window is resized.
 * 
 * @note This class is designed to have only one instance in the program.
 */
class My_GLFW_Window_Manager {
public:

    /**
    * @subsection Constructors
    */

    /**
    * @brief Initializes the GLFW library, creates a window, and sets up the 
    * OpenGL context.
    * 
    * @note Default Destructor
    */
    My_GLFW_Window_Manager();

    /**
    * @subsection Destructors
    */

    /**
    * @note Default Constructor
     * 
     * @brief Cleans up and terminates the GLFW library and window.
     */
    ~My_GLFW_Window_Manager();

    /**
    * @subsection Public Member Functions
    */
    
    /**
     * @brief Function to handle the display logic for the application.
     * Manages display buffers and processes input, loops until a closing 
     * signal is given.
     */
    void display();

    /**
     * @brief Processes the input from the user.
     * 
     * This function handles user input, such as keyboard or mouse events,
     * and updates the application state accordingly.
     */
    void processInput();

    /**
    * @subsection Getters
    */

    /**
     * @brief Gets the GLFW window pointer.
     * 
     * @return GLFWwindow* Pointer to the GLFW window.
     */
    inline GLFWwindow* getWindow() const
    {
        return window;
    }
    /**
     * @brief Gets the width of the window.
     * 
     * @return int Width of the window.
    */
    inline int getWindowWidth() const
    {
        return windowWidth;
    }
    /**
     * @brief Gets the height of the window.
     * 
     * @return int Height of the window.
     */
    inline int getWindowHeight() const
    {
        return windowHeight;
    }
    /**
     * @brief Gets the title of the window.
     * 
     * @return const char* Title of the window.
    */
    inline const char* getTitle() const
    {
        return title;
    }
    /**
     * @brief Gets the value of the initialization flag
     * 
     * @return True if initialization of the class was successful.
    */
    inline bool getInitialization() const
    {
        return initialization_success;
    }

    /**
    * @subsection Setters
    */

    /**
     * @brief Sets the value of the initialization flag.
     * 
     * @param success The new value for the initialization flag.
     */
    inline void setInitializationSuccess(bool success)
    {
        initialization_success = success;
    }

private:

    /**
    * @subsection Private member functions
    */

    /**
     * @brief Initializes the GLFW library, creates a window, and sets up the 
     * OpenGL context.
     * 
     * @remark This function performs the following steps:
     * @remark Initializes the GLFW library.
     * @remark Creates a window and attaches it to the window pointer.
     * @remark Sets the window as the main OpenGL context.
     * @remark Loads OpenGL 3.3 functions.
     * @note This function adjusts the initialization_success flag member
     */
    void initialize();

    /**
     * @brief Creates a GLFW window.
     * 
     * @return bool true if the window is successfully created, false otherwise.
     * 
     * @remark This function performs the following steps:
     * @remark Checks if GLFW is initialized.
     * @remark Creates a window and attaches it to the window pointer.
     * @remark Sets the windows' pointer as the main OpenGL rendering context.
     * @remark Terminates GLFW if the window creation fails.
     */
    bool createWindow();

    /**
     * @brief Initializes the GLFW library with an OpenGL context.
     * 
     * @return bool true if GLFW is successfully initialized, false otherwise.
     * 
     * @remark This function performs the following steps:
     * @remark Checks if the GLFW library is included.
     * @remark Ensures OpenGL 3.3 or newer is installed.
     * @remark Initializes the GLFW library.
     * @remark Sets the OpenGL context to version 3.3 with core profile.
     */
    bool openGLFW();

    /**
    * @brief Resizes the OpenGL drawing context (viewport) 
    * 
    * @param window Pointer to the GLFW window.
    * @param new_width New width of the window.
    * @param new_height New height of the window.
    * 
    * @note This function is called when the window is resized by the user.
    */
    static void inline window_resize(GLFWwindow* window, int new_width, 
                                        int new_height) 
    {
        glViewport(0, 0, new_width, new_height);
        
    } 

    /**
    * @brief Terminates the GLFW window manager and cleans up resources.
    */
    void terminate_GLFW_Window_Manager();

    /**
    * @subsection Private member variables
    */

    /**
    * @var My_GLFW_Window_Manager::initialization_success
    * @brief Flag indicating whether GLFW and window initialization was 
    * successful.
    */
    static bool initialization_success;
    /**
    * @var My_GLFW_Window_Manager::window
    * @brief Pointer to the GLFW window.
    */
    static GLFWwindow* window;
    /**
    * @var My_GLFW_Window_Manager::windowWidth
    * @brief Width of the window (default 640).
    */
    static int windowWidth;
    /**
    * @var My_GLFW_Window_Manager::windowHeight
    * @brief Height of the window (default 480).
    */
    static int windowHeight;
    /**
    * @var My_GLFW_Window_Manager::title
    * @brief Title of the window.
    */
    static const char* title;

};