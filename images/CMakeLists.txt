cmake_minimum_required(VERSION 3.0)

message("CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}")

find_package(OpenCV REQUIRED)

include_directories(${OPENCV_DIRS})

add_executable(image main.cpp)

target_link_libraries(image ${OPENCV_LIBS})
