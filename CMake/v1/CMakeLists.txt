cmake_minimum_required(VERSION 3.0)
project(CALC)

set(CMAKE_CXX_STANDARD 11)
set(SRC add.c div.c main.c mult.c sub.c)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(app ${SRC})