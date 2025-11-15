# Install script for directory: /workspaces/CPP-F25/code/unittest/_deps/cpputest-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/cpputest.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTest" TYPE FILE FILES "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/generated/CppUTestGeneratedConfig.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake" TYPE FILE FILES
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/install/CppUTestConfig.cmake"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/install/CppUTestConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake/CppUTestTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake/CppUTestTargets.cmake"
         "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/CMakeFiles/Export/4306f34d0d0a58e19d5744ed1e2a0d78/CppUTestTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake/CppUTestTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake/CppUTestTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake" TYPE FILE FILES "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/CMakeFiles/Export/4306f34d0d0a58e19d5744ed1e2a0d78/CppUTestTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake" TYPE FILE FILES "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/CMakeFiles/Export/4306f34d0d0a58e19d5744ed1e2a0d78/CppUTestTargets-relwithdebinfo.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake/Scripts" TYPE FILE FILES "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/cmake/Scripts/CppUTestBuildTimeDiscoverTests.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/CppUTest/cmake/Modules" TYPE FILE FILES "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/cmake/Modules/CppUTestBuildTimeDiscoverTests.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/src/CppUTest/cmake_install.cmake")
  include("/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/src/CppUTestExt/cmake_install.cmake")
  include("/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/tests/CppUTest/cmake_install.cmake")
  include("/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/tests/CppUTestExt/cmake_install.cmake")

endif()

