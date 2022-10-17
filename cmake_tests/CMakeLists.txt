cmake_minimum_required(VERSION 3.16)

project(TESTS)

add_executable(${PROJECCT_NAME} main.c)

add_subdirectory(./lib_test)

target_include_directories(${PROJECT_NAME} lib_test)

target_link_directories(${PROJECT_NAME} PRIVATE lib_test)

target_link_libraries(${PROJECT_NAME} safe_math)