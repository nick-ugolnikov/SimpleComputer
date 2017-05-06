cmake_minimum_required(VERSION 3.6)
project(Architec)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c mySimpleComputer.c mySimpleComputer.h myTerm.c myTerm.h myBigChars.c myBigChars.h myGUI.c myGUI.h myReadKey.c myReadKey.h)
add_executable(Architec ${SOURCE_FILES})