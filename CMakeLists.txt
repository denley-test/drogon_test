cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(argusai_backend VERSION 0.0.1 LANGUAGES CXX)

add_executable(${PROJECT_NAME} "")
target_include_directories(${PROJECT_NAME}
  PRIVATE
)
target_sources(${PROJECT_NAME}
  PRIVATE
    src/main.cpp
)
