cmake_minimum_required(VERSION 3.10)
project(dsa_cpp CXX)

set(CMAKE_CXX_STANDARD 17)

# Find all cpp files in the current directory and its subdirectories
file(GLOB_RECURSE CPP_FILES "*.cpp")

# Create a separate executable for each cpp file
foreach(cpp_file ${CPP_FILES})
    # Get the file name without extension
    get_filename_component(exec_name ${cpp_file} NAME_WE)

    # Create executable with the file name
    add_executable(${exec_name} ${cpp_file})
endforeach()
