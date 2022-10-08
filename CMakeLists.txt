cmake_minimum_required(VERSION 3.7)

## Use the variable PROJECT_NAME for changing the target name
set(PROJECT_NAME "findword" LANGUAGES CXX)

## Set our project name
project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "Algorithm To Find Word")

## Set version of C++ compiler
if(NOT CMAKE_CXX_STANDARD)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif(NOT CMAKE_CXX_STANDARD)

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "./src/*.cpp")

## Define the executable
add_library(${PROJECT_NAME} STATIC ${SRCS})