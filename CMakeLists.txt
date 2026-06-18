cmake_minimum_required(VERSION 3.20)
project(template_name)

# Cplusplus standard.
set(CMAKE_CXX_STANDARD 23)

# Create the compile_commands.json.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fix for clangd working on nix.
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
  ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

# Source files.
set(SOURCE_FILES
  src/main.cpp
)

# Executable options.
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_options(${PROJECT_NAME} PRIVATE )
