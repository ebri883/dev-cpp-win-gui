#pragma once
#include "../../engine/WindowsEngine/WindowsEngine.hpp"

/**
 * @class WindowsApp
 * @brief Application-specific implementation of the `WindowsEngine` class.
 *
 * This class extends `WindowsEngine` to provide application-specific functionality
 * and handle custom window events.
 */
class WindowsApp : public WindowsEngine
{
public:
	/**
	 * @brief Constructs a `WindowsApp` object.
	 *
	 * Initializes the application by calling the base class constructor.
	 */
	WindowsApp();

	/**
	 * @brief Destructs a `WindowsApp` object.
	 *
	 * Cleans up any resources used by the application.
	 */
	~WindowsApp();

	/**
	 * @brief Called when the window is created.
	 *
	 * Provides application-specific initialization logic after the window has been created.
	 * Overrides the pure virtual `onCreate` method from `WindowsEngine`.
	 */
	virtual void onCreate() override;

	/**
	 * @brief Called to update the window.
	 *
	 * Provides application-specific update logic, such as handling user input or redrawing the window.
	 * Overrides the pure virtual `onUpdate` method from `WindowsEngine`.
	 */
	virtual void onUpdate() override;

	/**
	 * @brief Called when the window is destroyed.
	 *
	 * Provides application-specific cleanup logic when the window is about to be destroyed.
	 * Overrides the virtual `onDestroy` method from `WindowsEngine`.
	 */
	virtual void onDestroy() override;
};
