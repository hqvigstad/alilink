project(alicmake)
cmake_minimum_required(VERSION 2.6)

# Build options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -Woverloaded-virtual -Weffc++ -Wctor-dtor-privacy -std=c++0x")

# cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# ROOT 
find_package(ROOT REQUIRED)
include_directories(SYSTEM ${ROOT_INCLUDES})
set(LIBS ${LIBS} ${ROOT_LIBS})

add_executable(testRoot execTestRoot.cxx)
target_link_libraries(testRoot ${LIBS})



#AliROOT
find_package(ALIROOT REQUIRED)
include_directories(SYSTEM ${ALIROOT_INCLUDES})
set(LIBS ${LIBS} ${ALIROOT_LIBS})

subdirs(task)
include_directories(task)

add_executable(testAliRoot execAliTask.cxx)
target_link_libraries(testAliRoot ${LIBS} PtTask)
