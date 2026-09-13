cmake_minimum_required(VERSION 3.16)

project(gl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLAD_DIR ${CMAKE_SOURCE_DIR}/external/glad)
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)

file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${GLAD_DIR}/src/*.c
    ${IMGUI_DIR}/src/*.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${GLAD_DIR}/include
    ${IMGUI_DIR}/include
    ${IMGUI_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glm::glm
)