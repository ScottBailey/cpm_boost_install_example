# third_party/CMakeLists.txt

# Use CMake's FetchContent/MakeAvailable to download and compile dependencies via the CPM tool.

# This page will shelp you determine where source code archives live at github:
#   https://docs.github.com/en/repositories/working-with-files/using-files/downloading-source-code-archives
#

# Default FetchContent to Verbose. But don't override a user's explicit setting.
if(NOT FETCHCONTENT_QUIET)
  set(FETCHCONTENT_QUIET Off)
endif()

# Make sure to cache third party downloads, but don't override a user's explicit setting.
if(MSVC AND NOT CPM_SOURCE_CACHE)
  set(CPM_SOURCE_CACHE "C:/cpm_cache/")
endif()

set(BASE_FOLDER "3rdparty")

# Download CPM.cmake
file(
  DOWNLOAD      https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.7/CPM.cmake ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=83e5eb71b2bbb8b1f2ad38f1950287a057624e385c238f6087f94cdfc44af9c5
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

#find_package(Patch REQUIRED)

# Boost libraries
#  This speaks for itself.
set(CMAKE_FOLDER "${BASE_FOLDER}/Boost") # Isolate dependencies into their own folders. Doesn't work for all IDEs.
CPMAddPackage(
  NAME     Boost
  URL      https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
  URL_HASH SHA256=2e64e5d79a738d0fa6fb546c6e5c2bd28f88d268a2a080546f74e5ff98f29d0e
  SYSTEM   True
  OPTIONS
    "BOOST_ENABLE_CMAKE On"
    "BUILD_SHARED_LIBS On"
    "BOOST_INCLUDE_LIBRARIES filesystem"
)
