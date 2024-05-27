############################################################
#          Cmake Build of Linear Algebra Library           #
############################################################

# Project Setup
cmake_minimum_required(VERSION 3.22.0)
project(linear_algebra)
set(CMAKE_CXX_STANDARD 17)

# External Dependencies
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Add Header List
set(HEADER_LIST ${PROJECT_SOURCE_DIR}/include/Matrix.h)

# Add Library
add_library(linear_algebra INTERFACE)

# Target Include Directories
target_include_directories(linear_algebra INTERFACE ${PROJECT_SOURCE_DIR}/include)

# Unit Testing Build
enable_testing()
add_executable( testMain ${PROJECT_SOURCE_DIR}/test/testMain.cpp 
	                 ${PROJECT_SOURCE_DIR}/test/MatrixTest.cpp ${HEADER_LIST})
target_link_libraries(
  testMain
  GTest::gtest_main
  linear_algebra
)

# Target Include Directories
target_include_directories(testMain PUBLIC ${PROJECT_SOURCE_DIR}/include)
include(GoogleTest)
gtest_discover_tests(testMain)
