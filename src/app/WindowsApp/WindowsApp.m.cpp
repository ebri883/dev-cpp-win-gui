#include "WindowsApp.hpp"

/**
 * @brief Constructs a `WindowsApp` object.
 *
 * Calls the base class constructor to initialize the application.
 */
WindowsApp::WindowsApp() {}

/**
 * @brief Destructs a `WindowsApp` object.
 *
 * Calls the base class destructor to clean up any resources.
 */
WindowsApp::~WindowsApp() {}

/**
 * @brief Called when the window is created.
 *
 * Override this method to provide application-specific initialization logic
 * after the window has been created. This method is called by the `WindowsEngine`
 * during the window creation process.
 */
void WindowsApp::onCreate() {}

/**
 * @brief Called to update the window.
 *
 * Override this method to provide application-specific update logic,
 * such as handling user input or redrawing the window. This method is
 * called repeatedly by the `WindowsEngine` during the application's
 * main loop.
 */
void WindowsApp::onUpdate() {}

/**
 * @brief Called when the window is destroyed.
 *
 * Override this method to provide application-specific cleanup logic
 * when the window is about to be destroyed. This method calls the base
 * class `onDestroy` method to ensure proper destruction of the window.
 */
void WindowsApp::onDestroy()
{
	WindowsEngine::onDestroy();
}
