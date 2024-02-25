cmake_minimum_required(VERSION 3.0)
project(ExampleProject)

# 设置输出路径
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 添加可执行文件(根据具体的项目来生成对应的可执行文件)
add_executable(BinaryFind_704 ${CMAKE_CURRENT_SOURCE_DIR}/BinaryFind_704/BinaryFind_704.cpp)