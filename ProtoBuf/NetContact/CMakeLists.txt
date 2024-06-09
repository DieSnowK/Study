CMAKE_MINIMUM_REQUIRED_VERSION(VERSION 3.15)
project(NetContact)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(${PROJECT_SOURCE_DIR}/Common/ProtoBuf COM_SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/Client CLIENT_SRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/Server SERVER_SRC)

include_directories(${PROJECT_SOURCE_DIR}/Common/ProtoBuf ${PROJECT_SOURCE_DIR}/Common)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(client ${COM_SRC} ${CLIENT_SRC})
add_executable(server ${COM_SRC} ${SERVER_SRC})

target_link_libraries(client protobuf pthread)
target_link_libraries(server protobuf pthread)

