cmake_minimum_required(VERSION 3.15)
project(contacts2)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/ProtoBuf)
file(GLOB PB_SRC ${PROJECT_SOURCE_DIR}/ProtoBuf/*.cc)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(read ${PB_SRC} read.cc)
add_executable(write ${PB_SRC} write.cc)
target_link_libraries(read protobuf)
target_link_libraries(write protobuf)
