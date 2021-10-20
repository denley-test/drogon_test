cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(argusai_backend VERSION 0.0.1 LANGUAGES CXX)

add_executable(${PROJECT_NAME} "")
target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_17
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    vendor/drogon
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    drogon
)
target_sources(${PROJECT_NAME}
  PRIVATE
    src/main.cpp
)

add_subdirectory(vendor/drogon)
