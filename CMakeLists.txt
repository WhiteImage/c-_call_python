# cmake 所 需 的 最 低 版 本 要 求
cmake_minimum_required (VERSION 2.8)

# 设 置 项 目 名 称
project (main)

# 设置 C++11支持
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "-std=c++11")
# 寻找 OpenCV 库
find_package (OpenCV)    

# 加入 OpenCV 头文 件目 录
include_directories (${OpenCV_INCLUDE_DIRS})
include_directories( "/home/xxk/anaconda3/envs/TF/include/python3.6m")


message(STATUS "OpenCV library: ${OpenCV_INSTALL_PATH}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")


# 添 加 项 目 的 输 出 程 序 和 所 需 源 代 码
add_executable (main main.cc)

# 将OpenCV 库 链 接 到 程 序 中
target_link_libraries (main "/home/xxk/anaconda3/envs/TF/lib/libpython3.6m.so" ${OpenCV_LIBRARIES} )

