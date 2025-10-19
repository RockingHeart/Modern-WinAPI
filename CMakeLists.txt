cmake_minimum_required(VERSION 3.31)

project(ModernWinAPI)

set(CMAKE_CXX_STANDARD 23)

if (MSVC)
    add_compile_options(/std:c++latest)
    add_compile_options(/std:clatest)
    add_compile_options(/experimental:module)
else()
    add_compile_options(-fmodules)
endif()

file(GLOB WinPath "ModernWinAPI/Src/WinAPI/*.ixx")

add_executable(ModernWinAPI
    ${WinPath}
    ModernWinAPI/Execute/main.cpp
)

source_group("WinAPI" FILES ${WinPath})

source_group("Execute" ModernWinAPI/Execute/main.cpp)