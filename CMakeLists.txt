cmake_minimum_required(VERSION 3.15)
project(casse-brique)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(casse-brique main.cpp balle.h balle.cpp)
target_link_libraries(casse-brique ${CONAN_LIBS})