# Install script for directory: /workspaces/CPP-F25/code/unittest/_deps/cpputest-src/src/CppUTest

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build/src/CppUTest/libCppUTest.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTest" TYPE FILE FILES
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/CommandLineArguments.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/PlatformSpecificFunctions.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestMemoryAllocator.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/CommandLineTestRunner.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/PlatformSpecificFunctions_c.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestOutput.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/CppUTestConfig.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/SimpleString.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/SimpleStringInternalCache.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestPlugin.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/JUnitTestOutput.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TeamCityTestOutput.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/StandardCLibrary.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestRegistry.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/MemoryLeakDetector.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestFailure.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestResult.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/MemoryLeakDetectorMallocMacros.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestFilter.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestTestingFixture.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/MemoryLeakDetectorNewMacros.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestHarness.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/Utest.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/MemoryLeakWarningPlugin.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/TestHarness_c.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/UtestMacros.h"
    "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src/include/CppUTest/SimpleMutex.h"
    )
endif()

