cmake_minimum_required(VERSION 3.15)
project(calc_test)

# 搜索源文件
aux_source_directory(./ SRC)
include_directories(${HEAD_PATH})

link_directories(${LIB_PATH})
link_libraries(${CALC_LIB})

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
add_executable(${APP_NAME_1} ${SRC})