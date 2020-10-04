cmake_minimum_required(VERSION 3.10)
project(Final_Interface)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/tensorflow/contrib/makefile/downloads/flatbuffers/include
                    )

link_directories(${OpenCV_LIBRARIES_DIRS}
                ${CMAKE_CURRENT_SOURCE_DIR}/lib)


#add_library(Extract SHARED src/Extract.cpp include/Extract.h)
#target_link_libraries(Extract ${OpenCV_LIBS} ${CMAKE_CURRENT_SOURCE_DIR}/lib/libtensorflowlite.so)
add_executable(Final_Interface main.cpp wrapper/svip_action.cpp wrapper/svip_action.h)
target_link_libraries(Final_Interface ${OpenCV_LIBS} ${CMAKE_CURRENT_SOURCE_DIR}/lib/libtensorflowlite.so ${CMAKE_CURRENT_SOURCE_DIR}/lib/libExtract.so ${CMAKE_CURRENT_SOURCE_DIR}/lib/libLR.so)

