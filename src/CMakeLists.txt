cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(pencile_producer_project)

# Populate a CMake variable with the sources
set(window_srcs
    window.cpp
    main.cpp
    request.cpp
    welcome.cpp
    welcome.ui
    endgame.ui
    endgame.cpp
    apm.cpp
    )

set(LIBRAIRES 
Qt5::Widgets 
Qt5::Gui 
Qt5::Core 
Qt5::Network)

# Tell CMake to create the pencile_producer executable
add_executable(pencile_producer ${window_srcs})

# Use the reduired modules found above
target_link_libraries(pencile_producer
    Qt5::Widgets
    Qt5::Gui
    Qt5::Core
    Qt5::Network
    )
