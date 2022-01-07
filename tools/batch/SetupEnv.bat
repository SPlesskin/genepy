@echo off

:init
    cls

    set _QT_DIR=C:\Qt\5.15.0
    set _QT_TOOL_DIR=%_QT_DIR%\Tools

    if /I [%1] == [MSVC] goto msvc
    if /I [%1] == [MinGW] goto mingw

    echo Error: Invalid environment: %1
    echo Usage: %0 { MSVC ^| MinGW }
    goto end

:msvc
    title MSVC 2019 64-bit Build Environment

    set _QT_HOME=%_QT_DIR%\5.15.0\msvc2019_64
    set _MSVC_HOME="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC"
    set _CMAKE_HOME=%_QT_TOOL_DIR%\CMake_64

    call %_MSVC_HOME%\Auxiliary\Build\vcvars64.bat

    goto main

:mingw
    title MinGW 8.1 64-bit Build Environment

    set _QT_HOME=%_QT_DIR%\5.15.0\mingw81_64
    set _MINGW_HOME=%_QT_TOOL_DIR%\mingw810_64
    set _CMAKE_HOME=%_QT_TOOL_DIR%\CMake_64

    set PATH=%_MINGW_HOME%\bin;%PATH%

:main
    set PATH=%_QT_HOME%\bin;%_CMAKE_HOME%\bin;%_QT_TOOL_DIR%\QtCreator\bin;%PATH%

    start qtcreator

    cmd /K
    title %comspec%

:end