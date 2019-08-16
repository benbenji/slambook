cmake_minimum_required( VERSION 2.8 )
project( geometry )

set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-O3" )
# 添加Eigen头文件
# include_directories( "/usr/include/eigen3" )
find_package(EIGEN3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
message(STATUS ${EIGEN3_INCLUDE_DIR})
# 添加Eigen头文件

add_executable( eigenGeometry eigenGeometry.cpp )
add_executable(vioqandrtes vioqandrtes.cpp )