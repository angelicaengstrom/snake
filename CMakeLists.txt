cmake_minimum_required(VERSION 3.20)
project(snake) #namn av projektet

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#Qt installation
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.2\\mingw_64\\lib\\cmake\\")

#inclusion of qt
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
add_executable(snake main.cpp board.cpp board.h snake.cpp snake.h window.h window.cpp window.ui element.h element.cpp food.h food.cpp)

target_link_libraries(snake Qt6::Core)
target_link_libraries(snake Qt6::Widgets)