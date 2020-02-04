cmake_minimum_required(VERSION 3.15)
project(DnaSequence)

set(CMAKE_CXX_STANDARD 98)
add_executable(DnaSequence main.cpp Model/DnaSequence.cpp Model/DnaSequence.h File.cpp File.h main.cpp CLI.cpp CLI.h CommandParser.cpp CommandParser.h Commands/CommandExecuter.cpp Commands/CommandExecuter.h Commands/Command.h Commands/New.cpp Commands/New.h Commands/Load.cpp Commands/Load.h Commands/Save.cpp Commands/Save.h Commands/ErrorCommand.cpp Commands/ErrorCommand.h DnaContainer.cpp DnaContainer.h Commands/List.cpp Commands/List.h Model/IDna.h Model/DecoratorDnaSequence.cpp Model/DecoratorDnaSequence.h Model/RealDnaSequence.cpp Model/RealDnaSequence.h)
add_executable(DnaSequence-test test.cpp Model/DnaSequence.cpp Model/DnaSequence.h File.cpp File.h CLI.cpp CLI.h Commands/CommandExecuter.cpp Commands/CommandExecuter.h Commands/Command.h Commands/New.cpp Commands/New.h Commands/Save.cpp Commands/Save.h Commands/ErrorCommand.cpp Commands/ErrorCommand.h DnaContainer.cpp DnaContainer.h Commands/List.cpp Commands/List.h Model/IDna.h Model/DecoratorDnaSequence.cpp Model/DecoratorDnaSequence.h Model/RealDnaSequence.cpp Model/RealDnaSequence.h)
target_link_libraries(DnaSequence-test gtest gtest_main pthread)
