cmake_minimum_required(VERSION 3.0)
project(ProtoBuf)

include_directories(${PROJECT_SOURCE_DIR})
aux_source_directory(./ SRC)

add_executable(app ${SRC})
target_link_libraries(app protobuf)