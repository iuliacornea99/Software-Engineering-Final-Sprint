cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(pencile_producer_project)
configure_file(background.jpg ${PROJECT_BINARY_DIR}/background.jpg COPYONLY)

if(EXISTS $ENV{HOME}/Qt/5.13.0/gcc_64)
  set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.13.0/gcc_64)
elseif(EXISTS $ENV{HOME}/Qt/5.12.0/gcc_64)
  set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.12.2/gcc_64)
endif()

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the needed Qt library
find_package(Qt5 COMPONENTS REQUIRED Core Gui Widgets Network)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(doc)
