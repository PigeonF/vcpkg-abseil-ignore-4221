cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()

project(VcpkgAbseilIgnore4221 LANGUAGES CXX)

find_package(absl REQUIRED)

add_executable(main main.cc)
target_link_libraries(main PRIVATE absl::status)
