cmake_minimum_required(VERSION 3.26)
project(TokenFetcher VERSION 1.0.0)

include_directories(include)

file(GLOB SOURCES "source/*.cpp")

add_subdirectory(example)
