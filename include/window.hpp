/**
 * @file window.hpp
 * @brief Header file for managing and setting up a GLFW window with an 
 * OpenGL context.
 * 
 * This file contains the declaration of the My_GLFW_Window_Manager class, which 
 * is responsible for initializing the GLFW library, creating a window, and 
 * setting up the OpenGL context. The class provides utility functions to 
 * handle window properties, process user input, and manage the display logic 
 * of the application. It ensures that there is only one instance of the window 
 * manager in the program and handles the lifecycle of the window and the 
 * OpenGL context.
 * 
 * The class includes methods for:
 * - Initializing the GLFW library and OpenGL context.
 * - Creating and managing a GLFW window.
 * - Handling window resizing and updating the OpenGL viewport.
 * - Processing user input and managing display logic.
 * 
 * This file should be included in any application that requires a GLFW window 
 * with an OpenGL context for rendering graphics.
 */

#pragma once
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <cstdio>
#include <memory>
#include <string>
#include <iostream>
#include "buffer.hpp"
#include "shaders.hpp"

/**
 * @class My_GLFW_Window_Manager
 * @brief Manages the creation and lifecycle of a GLFW window with OpenGL context.
 * 
 * This class handles the initialization of GLFW, creation of a window, and 
 * setting up the OpenGL context. It also provides utility functions to get 
 * window properties and resize the OpenGL viewport when the window is resized.
 * 
 * @note This class is designed to have only one instance in the program.
 */
class My_GLFW_Window_Manager 
{
public:

    /**
     * @fn My_GLFW_Window_Manager().
     * @brief Default constructor. 
     * Initializes the GLFW library, creates a window, and sets up the 
     * OpenGL context.
     * 
    */
    My_GLFW_Window_Manager();

    /**
     * @fn ~My_GLFW_Window_Manager().
     * @brief Default destructor. Cleans up and terminates library and window.
    */
    ~My_GLFW_Window_Manager();

    /**
     * @fn display()
     * @brief Function to handle the display logic for the application.
     * @remark Manages display buffers and processes input, 
     * @remark loops until a closing signal is given.
    */
    void display();

    /**
     * @fn void processInput().
     * @brief This function handles user input, such as keyboard or mouse events,
     * and updates the application state accordingly.
    */
    void processInput();

    /**
     * @fn inline GLFWwindow* getWindow() const.
     * @brief Gets the GLFW window pointer.
     * @return Pointer to the GLFW window.
    */
    inline GLFWwindow* getWindow() const
    {
        return window_.get();
    }

    /**
     * @fn inline int getWindowWidth() const.
     * @brief Gets the width of the window.
     * @return int Width of the window.
    */
    inline int getWindowWidth() const
    {
        return windowWidth_;
    }

    /**
     * @fn inline int getWindowHeight() const.
     * @brief Gets the height of the window.
     * @return int Height of the window.
     */
    inline int getWindowHeight() const
    {
        return windowHeight_;
    }

    /**
     * @fn inline const std::string getTitle() const.
     * @brief Gets the title of the window.
     * @return String representing the title of the window.
    */
    inline const std::string getTitle() const
    {
        return title_;
    }

    /**
     * @fn inline bool getInitialization() const.
     * @brief Gets the value of the initialization flag.
     * @return True if window setup was successful.
    */
    inline bool getInitialization() const
    {
        return initialization_success_;
    }

    /**
     * @fn inline void setInitializationSuccess(bool success),
     * @brief Sets the value of the initialization flag.
     * @param success The new value.
     */
    inline void setInitializationSuccess(bool success)
    {
        initialization_success_ = success;
    }

private:
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
    static void inline window_resize(GLFWwindow* window,  int new_width, 
                                     int new_height) 
    {
        glViewport(0, 0, new_width, new_height);
        
    } 

    /**
     * @var My_GLFW_Window_Manager::initialization_success
     * @brief Flag indicating whether GLFW and window initialization was 
     * successful.
    */
    static bool initialization_success_;

    /**
     * @var My_GLFW_Window_Manager::window
     * @brief Pointer to the GLFW window.
    */
    static std::shared_ptr<GLFWwindow> window_;

    /**
     * @var My_GLFW_Window_Manager::windowWidth
     * @brief Width of the window (default 640).
    */
    static int windowWidth_;

    /**
     * @var My_GLFW_Window_Manager::windowHeight
     * @brief Height of the window (default 480).
    */
    static int windowHeight_;

    /**
     * @var My_GLFW_Window_Manager::title
     * @brief Title of the window.
    */
    static const std::string title_;

};