#############################
# CMake Standard Library root/
#############################

cmake_minimum_required (VERSION 3.5.1)

project ("AMM_Standard_Library")
set(VERSION_TYPE "beta" CACHE STRING "version type" FORCE)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 2)
set(PROJECT_VERSION_PATCH 0)

include(CMakePrintHelpers)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake )

option(GENERATE_DOC "Run Doxygen to generate docs" OFF)

# Enable helpfull warnings and C++14 for all files
if (MSVC)
    add_compile_options(/std:c++14 /W3)
    add_definitions( -DNOMINMAX )
    add_definitions( -DWIN32_LEAN_AND_MEAN )
    if(CMAKE_SIZEOF_VOID_P MATCHES "8")
        set(CMAKE_INSTALL_PREFIX "C:/Program Files/${CMAKE_PROJECT_NAME}")
    else()
        set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/${CMAKE_PROJECT_NAME}")
    endif()
else ()
    add_compile_options(-std=c++14)
    add_compile_options(-O0)
endif ()

find_package(Boost REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

if (DEFINED ENV{FASTRTPS_HOME})
    list(APPEND CMAKE_PREFIX_PATH $ENV{FASTRTPS_HOME})
endif ()

if (DEFINED ENV{FASTRTPSHOME})
    list(APPEND CMAKE_PREFIX_PATH $ENV{FASTRTPSHOME})
endif ()

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

include(osmacros)

include_directories(src)

add_subdirectory(IDL)
add_subdirectory(src)

if(GENERATE_DOC)
    add_subdirectory(doc)
endif(GENERATE_DOC)

include(Packing)
