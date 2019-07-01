cmake_minimum_required(VERSION 2.4)

# include GoogleTest
include(GoogleTest)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

# Set libraries to link
set(CPP_HEADERS
    ../src/apm.cpp
    ../src/endgame.cpp
    ../src/request.cpp
    ../src/welcome.cpp
    ../src/window.cpp)

set(LIBRARIES
    ${LIBRARIES}
    Qt5::Widgets
    Qt5::Gui
    Qt5::Core
    Qt5::Network
    gtest
    gtest_main
    rt
    pthread)

# Make executable
add_executable(test_welcome test_welcome.cpp ${CPP_HEADERS})

# Link libraries to executable
target_link_libraries(test_welcome ${LIBRARIES})
