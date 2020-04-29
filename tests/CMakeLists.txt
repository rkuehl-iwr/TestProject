cmake_minimum_required(VERSION 3.10)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_executable(testProjectTests testsMain.cpp)

target_compile_features(testProjectTests PUBLIC cxx_std_17)

target_link_libraries(testProjectTests PRIVATE Catch)

add_test(NAME TestProject_Tests COMMAND testProjectTests WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..)
