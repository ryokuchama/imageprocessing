cmake_minimum_required(VERSION 3.0.0)
project(imageprocessing VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(imageprocessing main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(imageprocessing ${OpenCV_LIBS})