cmake_minimum_required(VERSION 3.10)
project(hw_03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -pedantic")

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(hw_03
        src/main.cpp
        src/CLI.cpp
        src/Huffman.cpp
        src/HuffmanArchiver.cpp
        include/CLI.h
        include/Huffman.h
        include/HuffmanArchiver.h)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(test_hw_03
        test/doctest.h
        test/TestMain.cpp
        test/TestCLI.cpp
        src/CLI.cpp
        src/Huffman.cpp
        src/HuffmanArchiver.cpp
        include/CLI.h
        include/Huffman.h
        include/HuffmanArchiver.h
        test/TestHuffmanArchiver.cpp)