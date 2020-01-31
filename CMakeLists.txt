cmake_minimum_required(VERSION 3.15)
project(DnaSequence)

set(CMAKE_CXX_STANDARD 98)
add_executable(DnaSequence main.cpp DnaSequence.cpp DnaSequence.h Nucleotide.cpp Nucleotide.h File.cpp File.h main.cpp)
add_executable(DnaSequence-test test.cpp DnaSequence.cpp DnaSequence.h Nucleotide.cpp Nucleotide.h File.cpp File.h)
target_link_libraries(DnaSequence-test gtest gtest_main pthread)
