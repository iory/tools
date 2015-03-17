CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# show compiler
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")

# build type (default is RelWithDebInfo)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo." FORCE)
endif()

if(NOT(CMAKE_BUILD_TYPE STREQUAL Debug OR CMAKE_BUILD_TYPE STREQUAL RelWithDebInfo OR CMAKE_BUILD_TYPE STREQUAL Release))
  message(FATAL_ERROR "Choose the type of build, options are: Debug RelWithDebInfo Release.")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# add cxx flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")       # enable c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")    # enable all warnings


# add definitions
option(ENABLE_TIMER "Enable Timer" ON)
if(ENABLE_TIMER)
  add_definitions(-DENABLE_TIMER)    # enable timer output
endif()

# print cxx flags
string(TOUPPER "CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}" CMAKE_CXX_FLAGS_BUILD_TYPE)
set(CMAKE_CXX_FLAGS_BUILD_TYPE "${${CMAKE_CXX_FLAGS_BUILD_TYPE}}")
message(STATUS "CXX flags:${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_BUILD_TYPE}")

################################################################################
# Check libraries
################################################################################

# boost
find_package(Boost REQUIRED COMPONENTS)
message(STATUS "Boost library dir = ${Boost_LIBRARY_DIR}")
message(STATUS "Boost include dir = ${Boost_INCLUDE_DIR}")

# Set output directories
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin CACHE PATH "Output directory for executables")
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR}/lib CACHE PATH "Output directory for libraries")

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

add_executable(exp src/exp.cpp)
target_link_libraries(exp ${Boost_LIBRARIES})
message(STATUS "   exp")

add_executable(fibo src/fibonacci.cpp)
target_link_libraries(fibo ${Boost_LIBRARIES})
message(STATUS "   fibonacci")

add_executable(factorial src/factorial.cpp)
target_link_libraries(factorial ${Boost_LIBRARIES})
message(STATUS "   factorial")

add_executable(factorization src/factorization.cpp)
target_link_libraries(factorization ${Boost_LIBRARIES})
message(STATUS "   factorization")

add_executable(gcd src/gcd.cpp)
target_link_libraries(gcd ${Boost_LIBRARIES})
message(STATUS "   gcd")

add_executable(logarithm src/logarithm.cpp)
target_link_libraries(logarithm ${Boost_LIBRARIES})
message(STATUS "   logarithm")
