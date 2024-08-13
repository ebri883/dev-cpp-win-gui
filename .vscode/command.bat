@echo off
setlocal enabledelayedexpansion

REM Set paths
set SRC_DIR=%~dp0..\src
set COMPILED_DIR=%~dp0..\compiled
set EXE_NAME=windows-gui.exe
set EXE_PATH=%COMPILED_DIR%\%EXE_NAME%

REM Create compiled directory if it doesn't exist
if not exist "%COMPILED_DIR%" mkdir "%COMPILED_DIR%"

REM Find all .m.cpp files in src directory and subdirectories
set FILE_LIST=
for /r "%SRC_DIR%" %%f in (*.m.cpp) do (
    set FILE_LIST=!FILE_LIST! "%%f"
)

REM Print the files to be compiled (for debugging purposes)
echo Compiling the following files:
echo %SRC_DIR%\main.cpp !FILE_LIST!
echo.

REM Compile the project
g++ -std=c++23 "%SRC_DIR%\app\main.cpp" -o "%EXE_PATH%" !FILE_LIST! -mwindows

REM Check if the compilation was successful
if %ERRORLEVEL% neq 0 (
    echo Compilation failed.
    exit /b %ERRORLEVEL%
)

REM Check if the executable was created
if not exist "%EXE_PATH%" (
    echo Failed to create executable.
    exit /b 1
)

REM Run the compiled program
echo Running the compiled program...
"%EXE_PATH%"

REM Check if the program ran successfully
if %ERRORLEVEL% neq 0 (
    echo Program execution failed.
    exit /b %ERRORLEVEL%
)

endlocal
