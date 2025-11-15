# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/CPP-F25/code/unittest/_deps/cpputest-src"
  "/workspaces/CPP-F25/code/unittest/_deps/cpputest-build"
  "/workspaces/CPP-F25/code/unittest/_deps/cpputest-subbuild/cpputest-populate-prefix"
  "/workspaces/CPP-F25/code/unittest/_deps/cpputest-subbuild/cpputest-populate-prefix/tmp"
  "/workspaces/CPP-F25/code/unittest/_deps/cpputest-subbuild/cpputest-populate-prefix/src/cpputest-populate-stamp"
  "/workspaces/CPP-F25/code/unittest/_deps/cpputest-subbuild/cpputest-populate-prefix/src"
  "/workspaces/CPP-F25/code/unittest/_deps/cpputest-subbuild/cpputest-populate-prefix/src/cpputest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/CPP-F25/code/unittest/_deps/cpputest-subbuild/cpputest-populate-prefix/src/cpputest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/CPP-F25/code/unittest/_deps/cpputest-subbuild/cpputest-populate-prefix/src/cpputest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
