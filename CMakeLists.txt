cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(drogon_test VERSION 0.0.1 LANGUAGES CXX)

option(BUILD_TESTS "Build unit tests" ON)
configure_file(${CMAKE_SOURCE_DIR}/config/config.json.in
  ${CMAKE_BINARY_DIR}/drogon_config.json)

set(PROJECT_LIB_NAME "${PROJECT_NAME}_lib")
add_library(${PROJECT_LIB_NAME})
target_compile_features(${PROJECT_LIB_NAME}
  PRIVATE
    cxx_std_17
)
target_include_directories(${PROJECT_LIB_NAME}
  PUBLIC
    include
    vendor/drogon
)
target_link_libraries(${PROJECT_LIB_NAME}
  PUBLIC
    drogon
)
target_sources(${PROJECT_LIB_NAME}
  PRIVATE
    src/drogon_helper.cpp
)

add_executable(${PROJECT_NAME} "")
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${PROJECT_LIB_NAME}
)
target_sources(${PROJECT_NAME}
  PRIVATE
    src/main.cpp
    src/controllers/HomeController.cpp
)
include(${CMAKE_SOURCE_DIR}/vendor/drogon/cmake/DrogonUtilities.cmake)
drogon_create_views(${PROJECT_NAME}
  ${CMAKE_SOURCE_DIR}/src/views
  ${CMAKE_BINARY_DIR}/views
)
install(TARGETS ${PROJECT_NAME} ${PROJECT_LIB_NAME} ${PROJECT_LIB_NAME}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(BUILD_TESTS)
  set(PROJECT_TEST_NAME "${PROJECT_NAME}_test")
  find_package(GTest REQUIRED)
  add_executable(${PROJECT_TEST_NAME} "")
  target_link_libraries(${PROJECT_TEST_NAME}
    PRIVATE
      ${PROJECT_LIB_NAME}
      ${GTEST_BOTH_LIBRARIES}
  )
  target_sources(${PROJECT_TEST_NAME}
    PRIVATE
      test/main.cpp
      test/test_drogon_helper.cpp
  )
  include(CTest)
  enable_testing()
  add_test(
    NAME ${PROJECT_TEST_NAME}
    COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>
  )
  install(TARGETS ${PROJECT_TEST_NAME}
    DESTINATION ${CMAKE_INSTALL_BINDIR}/test
  )
endif()

add_subdirectory(vendor/drogon)
