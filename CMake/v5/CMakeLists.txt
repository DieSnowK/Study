cmake_minimum_required(VERSION 3.15)
project(mult_test)

# 设置静态库生成路径
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
# 测试程序生成的路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 头文件目录
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 静态库名字
set(CALC_LIB calc)
set(SORT_LIB sort)

# 可执行程序的名字
set(APP_NAME_1 calc_test)
set(APP_NAME_2 sort_test)

# 给当前结点添加子目录目录
add_subdirectory(calc)
add_subdirectory(sort)
add_subdirectory(sort_test)
add_subdirectory(calc_test)