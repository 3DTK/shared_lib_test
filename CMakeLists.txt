cmake_minimum_required(VERSION 3.12)

add_library(scanlib_objects OBJECT scan.cc)
set_property(TARGET scanlib_objects PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(scan_static STATIC $<TARGET_OBJECTS:scanlib_objects>)
add_library(scan_shared SHARED $<TARGET_OBJECTS:scanlib_objects>)

set_target_properties(scan_static PROPERTIES OUTPUT_NAME scan CLEAN_DIRECT_OUTPUT 1)
set_target_properties(scan_shared PROPERTIES OUTPUT_NAME scan CLEAN_DIRECT_OUTPUT 1)

target_link_libraries(scan_static)
target_link_libraries(scan_shared)

add_executable(scan_test scan_test.cc)
target_link_libraries(scan_test scan_shared)
