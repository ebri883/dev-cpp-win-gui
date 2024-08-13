#include "WindowsApp/WindowsApp.hpp"

int main()
{
	WindowsApp instanceOfWindowsApp;
	if (instanceOfWindowsApp.init())
	{
		while (instanceOfWindowsApp.isRun())
		{
			instanceOfWindowsApp.broadcast();
		}
	}
	return 0;
}
