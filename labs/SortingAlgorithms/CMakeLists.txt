cmake_minimum_required(VERSION 3.0.0)
project(new_project VERSION 0.1.0)

file(GLOB TARGET_SRC "./src/*.cpp" )

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(main ${TARGET_SRC}) # Create an executable of set of source files [exe name files to bundle]



