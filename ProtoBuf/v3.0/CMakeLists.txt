cmake_minimum_required(VERSION 3.15)
project(contacts2)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/Client ${PROJECT_SOURCE_DIR}/Server)
file(GLOB Client_SRC ${PROJECT_SOURCE_DIR}/Client/*.cc)
file(GLOB Server_SRC ${PROJECT_SOURCE_DIR}/Server/*.cc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(read ${Client_SRC})
add_executable(write ${Server_SRC})
target_link_libraries(read protobuf)
target_link_libraries(write protobuf)
