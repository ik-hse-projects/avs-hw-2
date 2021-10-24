cmake_minimum_required(VERSION 3.10)

project(AVS2)

set(SOURCE_FILES src/main.cpp
                 src/buffer.cpp
                 src/circle.cpp
                 src/color.cpp
                 src/point.cpp
                 src/rectangle.cpp
                 src/shape.cpp
                 src/triangle.cpp)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -fsanitize=address,undefined")
add_executable(AVS2 ${SOURCE_FILES})
target_link_libraries(AVS2 m)
