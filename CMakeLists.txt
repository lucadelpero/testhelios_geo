cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(vsRelocalization)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(USE_BOOST_COMPONENTS system filesystem program_options system REQUIRED)
option(USE_LIBJPEG "Use libjpeg" ON)
option(USE_LIBPNG "Use libpng" ON)
option(USE_ZLIB "Use zlib" ON)
option(USE_BZIP2 "Use bzip2" OFF)
option(USE_GIFLIB "Use GIFLIB" OFF)
option(USE_AGAST "Use Agast" OFF)
option(USE_REDSVD "Use REDSVD" OFF)
option(USE_NANOFLANN "Use naonflann" ON)

option(HAVE_NEON "Enable ARM NEON support" OFF)
option(USE_OPENMP "Compile with OpenMP" OFF)
option(COMPILE_FOR_MSVC2013 "Compile using compatibility setting for MSVC2013" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")
set(HELIOS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/helios CACHE PATH "Path to helios directory")
set(NUCLEUS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/nucleus CACHE PATH "Path to nucleus directory")
set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/external CACHE PATH "Path to external directory")
include(${EXTERNAL_DIR}/common.cmake)
add_subdirectory(${NUCLEUS_DIR}/src/nucleus "nucleus" EXCLUDE_FROM_ALL)
add_subdirectory(${HELIOS_DIR}/src/helios "helios" EXCLUDE_FROM_ALL)

add_subdirectory(src)
