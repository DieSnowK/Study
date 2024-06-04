cmake_minimum_required(VERSION 3.15)
project(calc)

# 搜索源文件
aux_source_directory(./ SRC)
include_directories(${HEAD_PATH})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_PATH})
add_library(${CALC_LIB} STATIC ${SRC})