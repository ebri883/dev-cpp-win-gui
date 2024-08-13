#pragma once
#include <Windows.h>

/**
 * @class WindowsEngine
 * @brief Manages the creation, display, and destruction of a window in a Windows application.
 *
 * This class provides the basic functionality needed to create a window, handle its events, and manage its lifecycle.
 */
class WindowsEngine
{
protected:
	HWND m_hwnd;	 ///< Handle to the window.
	bool m_is_run; ///< Flag indicating whether the window is running.

public:
	/**
	 * @brief Constructs a `WindowsEngine` object.
	 *
	 * Initializes internal state but does not create the window.
	 */
	WindowsEngine();

	/**
	 * @brief Initializes the window class and creates the window.
	 *
	 * Registers the window class and creates a window with default settings.
	 *
	 * @return `true` if initialization is successful, `false` otherwise.
	 */
	bool init();

	/**
	 * @brief Processes messages and updates the window.
	 *
	 * Retrieves messages from the message queue, translates them, and dispatches them.
	 * Calls the `onUpdate` method to handle any custom update logic.
	 *
	 * @return `true` if the window should continue running, `false` otherwise.
	 */
	bool broadcast();

	/**
	 * @brief Releases resources and destroys the window.
	 *
	 * Destroys the window and performs cleanup.
	 *
	 * @return `true` if release is successful, `false` otherwise.
	 */
	bool release();

	/**
	 * @brief Checks if the window is currently running.
	 *
	 * @return `true` if the window is running, `false` otherwise.
	 */
	bool isRun();

	/**
	 * @brief Virtual method called when the window is created.
	 *
	 * This method is intended to be overridden by derived classes to handle custom initialization logic.
	 */
	virtual void onCreate() = 0;

	/**
	 * @brief Virtual method called to update the window.
	 *
	 * This method is intended to be overridden by derived classes to handle custom update logic.
	 */
	virtual void onUpdate() = 0;

	/**
	 * @brief Virtual method called when the window is destroyed.
	 *
	 * This method is intended to be overridden by derived classes to handle custom cleanup logic.
	 */
	virtual void onDestroy();

	/**
	 * @brief Virtual destructor.
	 *
	 * Ensures proper cleanup of derived classes when a `WindowsEngine` object is destroyed.
	 */
	virtual ~WindowsEngine();
};
