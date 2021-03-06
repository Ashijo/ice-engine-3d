#pragma once

#include "utils/Singleton.h"

#include "glad/glad.h" // To place before <GLFW/glfw3.h>
#include <GLFW/glfw3.h>

namespace ice {


/**
 * The main window where to draw.
 * There is only one Window (Accessible from singleton).
 *
 * \date    May 2018
 * \author  Constantin
 */
class WindowGLFW : private Singleton<WindowGLFW> {
    // For singleton use
    private:
        WindowGLFW() = default;
        friend Singleton<WindowGLFW>;
    public:
        using Singleton<WindowGLFW>::getInstance;

    public: // It's not the best way, but other (ex:InputManager) access window)
        GLFWwindow* _window;


    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------

    public:

        /**
         * Startup Window.
         * Must be the first to be called in the engine (Since also initialize GLFW).
         *
         * \return True if successfully started up, otherwise, false.
         */
        bool startup();

        /**
         * End Window.
         * Last to call (Since also stop GLFW).
         */
        void shutdown();

        /**
         * Update the window buffers.
         * Usually to call at the end.
         */
        void update();


    // -------------------------------------------------------------------------
    // Initialization
    // -------------------------------------------------------------------------

    public:

        /**
         * Close the window.
         */
        void close();

        /**
         * Check whether window is closed.
         *
         * \return True if closed, otherwise, return false.
         */
        bool isClosed() const;

        /**
         * Clear the window content
         */
        void clear();


    // -------------------------------------------------------------------------
    // Internal use functions
    // -------------------------------------------------------------------------

    private:
        static void resizeWindowCallback(GLFWwindow* window, int width, int height);
};


} // end namespace


