cmake_minimum_required(VERSION 2.8)
project( primitive )

find_package( OpenCV REQUIRED )

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(primitive  ${DIR_SRCS})

target_link_libraries( primitive ${OpenCV_LIBS} )
