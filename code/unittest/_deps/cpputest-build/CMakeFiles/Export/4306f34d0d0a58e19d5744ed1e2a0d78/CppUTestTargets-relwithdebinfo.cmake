#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CppUTest" for configuration "RelWithDebInfo"
set_property(TARGET CppUTest APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CppUTest PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libCppUTest.a"
  )

list(APPEND _cmake_import_check_targets CppUTest )
list(APPEND _cmake_import_check_files_for_CppUTest "${_IMPORT_PREFIX}/lib/libCppUTest.a" )

# Import target "CppUTestExt" for configuration "RelWithDebInfo"
set_property(TARGET CppUTestExt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(CppUTestExt PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libCppUTestExt.a"
  )

list(APPEND _cmake_import_check_targets CppUTestExt )
list(APPEND _cmake_import_check_files_for_CppUTestExt "${_IMPORT_PREFIX}/lib/libCppUTestExt.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
