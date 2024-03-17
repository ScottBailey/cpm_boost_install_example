# This project demonstrates a
cmake_minimum_required(VERSION 3.25)

set(project_name "Boost Target Example")
project("${project_name}")

# Set the default C++ standard.
set(CMAKE_CXX_STANDARD 17)

# If compiling with Clang in Linux, make sure to use libc++.
if( CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND LINUX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
endif()

# Attempt to folderize things - this is purely aesthetic for IDEs.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add third party stuff here
add_subdirectory(third_party)


# Add the executable here.
#  Notice how we add the executable's friendly alias (Boost::filesystem).
set(target_name silly_executable)
add_executable(${target_name} src/main.cpp)
target_link_libraries(${target_name} PRIVATE
  Boost::filesystem
)

# Add a super basic install command.
# Exercise as so:
#   cmake --install <build directory> --prefix <location to put install files>
# Notice how we skip the alias (Boost::filesystem) and use the actual target (boost_filesystem).
install(
  TARGETS
    ${target_name}
    boost_filesystem
  RUNTIME DESTINATION .  # Destination for executables
  LIBRARY DESTINATION .  # Destination for shared libraries
  ARCHIVE DESTINATION .  # Destination for static libraries (if any)
)
