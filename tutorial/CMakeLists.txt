cmake_minimum_required(VERSION 3.17)

# set the project name and version
project(main VERSION 1.0)

add_executable(main_helloworld main_helloworld.cc)
add_executable(main_idle main_idle.cc)


SET(CMAKE_EXE_LINKER_FLAGS 
          "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,/usr/local/lib")

target_link_libraries(main_helloworld PUBLIC uv)
target_link_libraries(main_idle PUBLIC uv)


##somehow i have to add the link path to the shared library
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
