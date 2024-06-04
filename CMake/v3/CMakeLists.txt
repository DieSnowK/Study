cmake_minimum_required(VERSION 3.15)
project(CALC)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 指定库搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(app_shared ${SRC})

# 链接动态库
target_link_libraries(app_shared calc2)