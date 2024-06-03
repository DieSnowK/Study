cmake_minimum_required(VERSION 3.0)
project(CALC)

set(CMAKE_CXX_STANDARD 11)

# 搜索src目录下的源文件
# set(SRC add.c div.c main.c mult.c sub.c)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

# 包含头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(app ${SRC})