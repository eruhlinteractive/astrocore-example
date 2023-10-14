cmake_minimum_required(VERSION 3.0.0)
project(AstroCoreTemplate.x86_64 VERSION 0.1.0)

include(CTest)
enable_testing()

link_directories(
    PRIVATE /home/ethan/vcpkg/installed/x64-linux/lib/
)

include_directories(
    PRIVATE /home/ethan/vcpkg/installed/x64-linux/include/
)

find_package(box2d CONFIG REQUIRED)

add_executable(AstroCoreTemplate.x86_64 main.cpp)
add_subdirectory(external/astrocore/AstroCore)

target_link_libraries(${PROJECT_NAME} astrocore raylib box2d tmxlite )