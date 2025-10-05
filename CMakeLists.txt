cmake_minimum_required(VERSION 4.0)
project(dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories(C01-data-structures)

# Find all cpp files in C01-data-structures and its subdirectories
file(GLOB_RECURSE CPP_FILES "C01-data-structures/**/*.cpp")

# Create a separate executable for each cpp file
foreach(cpp_file ${CPP_FILES})
    # Get the file name without extension
    get_filename_component(exec_name ${cpp_file} NAME_WE)

    # Create executable with the file name
    add_executable(${exec_name} ${cpp_file})
endforeach()
