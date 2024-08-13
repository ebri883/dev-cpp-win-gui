#include "WindowsEngine.hpp"

WindowsEngine *window = nullptr;

/**
 * @brief Constructs a `WindowsEngine` object.
 *
 * Initializes the window handle to nullptr and the running flag to false.
 */
WindowsEngine::WindowsEngine()
		: m_hwnd(nullptr), m_is_run(false)
{
}

/**
 * @brief Window procedure callback function.
 *
 * Handles messages sent to the window. Processes WM_CREATE and WM_DESTROY messages
 * by calling the corresponding virtual methods and posts a quit message.
 *
 * @param hWnd Handle to the window.
 * @param message Message identifier.
 * @param wParam Additional message information.
 * @param lParam Additional message information.
 * @return Result of message processing.
 */
LRESULT CALLBACK WindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		// Event triggered when the window is created
		window->onCreate();
		break;
	}
	case WM_DESTROY:
	{
		// Event triggered when the window is destroyed
		window->onDestroy();
		PostQuitMessage(0);
		break;
	}
	default:
	{
		return ::DefWindowProc(hWnd, message, wParam, lParam);
	}
	}

	return 0;
}

/**
 * @brief Initializes the window class and creates the window.
 *
 * Registers the window class and creates a window with the specified parameters.
 * Sets the window to visible and updates it. Sets the running flag to true.
 *
 * @return `true` if initialization is successful, `false` otherwise.
 */
bool WindowsEngine::init()
{
	// Initialize window class and register necessary values
	WNDCLASSEX InstanceOFWindowsClass;
	InstanceOFWindowsClass.cbClsExtra = 0;
	InstanceOFWindowsClass.cbSize = sizeof(WNDCLASSEX);
	InstanceOFWindowsClass.cbWndExtra = 0;
	InstanceOFWindowsClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	InstanceOFWindowsClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	InstanceOFWindowsClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	InstanceOFWindowsClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	InstanceOFWindowsClass.hInstance = NULL;
	InstanceOFWindowsClass.lpszClassName = "WindowsEngine";
	InstanceOFWindowsClass.lpszMenuName = "";
	InstanceOFWindowsClass.style = 0;
	InstanceOFWindowsClass.lpfnWndProc = WindowsProcedure;

	// Check if registering class was successful
	if (::RegisterClassExA(&InstanceOFWindowsClass) == 0)
	{
		return false;
	}

	if (!window)
	{
		window = this;
	}

	// Create window
	m_hwnd = ::CreateWindowExA(
			WS_EX_OVERLAPPEDWINDOW,
			"WindowsEngine",
			"WindowsEngine",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			1024,
			768,
			NULL,
			NULL,
			NULL,
			NULL);

	// Check if window creation was successful
	if (!m_hwnd)
	{
		return false;
	}

	// Show the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);

	// Set the flag that the window is running
	m_is_run = true;

	return true;
}

/**
 * @brief Processes messages and updates the window.
 *
 * Processes pending messages in the message queue and calls the onUpdate method.
 *
 * @return `true` if processing was successful, `false` otherwise.
 */
bool WindowsEngine::broadcast()
{
	MSG message;
	while (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	window->onUpdate();

	Sleep(10);

	return true;
}

/**
 * @brief Releases resources associated with the window.
 *
 * Destroys the window and cleans up resources. Returns false if the operation fails.
 *
 * @return `true` if release was successful, `false` otherwise.
 */
bool WindowsEngine::release()
{
	// Destroy the window
	// If the function failed (returns 0), it will return false
	if (!::DestroyWindow(m_hwnd))
	{
		return false;
	}

	return true;
}

/**
 * @brief Checks if the window is currently running.
 *
 * @return `true` if the window is running, `false` otherwise.
 */
bool WindowsEngine::isRun()
{
	return m_is_run;
}

/**
 * @brief Called when the window is destroyed.
 *
 * Sets the flag indicating that the window is no longer running.
 */
void WindowsEngine::onDestroy()
{
	// Set the flag that the window is destroyed
	m_is_run = false;
}

/**
 * @brief Destructor for the `WindowsEngine` class.
 *
 * Cleans up any remaining resources. This destructor is currently empty.
 */
WindowsEngine::~WindowsEngine()
{
}
