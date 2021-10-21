cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(argusai_backend VERSION 0.0.1 LANGUAGES CXX)

configure_file(${CMAKE_SOURCE_DIR}/config/config.json.in
  ${CMAKE_BINARY_DIR}/argusai_backend_config.json)

set(PROJECT_LIB_NAME "${PROJECT_NAME}_lib")
add_library(${PROJECT_LIB_NAME})
target_compile_features(${PROJECT_LIB_NAME}
  PRIVATE
    cxx_std_17
)
target_include_directories(${PROJECT_LIB_NAME}
  PUBLIC
    vendor/drogon
)
target_link_libraries(${PROJECT_LIB_NAME}
  PUBLIC
    drogon
)
target_sources(${PROJECT_LIB_NAME}
  PRIVATE
    src/controller/HomeController.cpp
)

add_executable(${PROJECT_NAME} "")
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_LIB_NAME}
)
target_sources(${PROJECT_NAME}
  PRIVATE
    src/main.cpp
)

add_subdirectory(vendor/drogon)
