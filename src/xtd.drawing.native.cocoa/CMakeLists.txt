cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.drawing.native.cocoa)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_link_options("-framework Cocoa")
add_include_directories("include")
add_references(xtd.core xtd.drawing.native)
add_sources(
  "include/xtd/xtd.drawing.native.cocoa.h"
  "include/xtd/xtd.drawing.native.cocoa"
)
add_sources(
  "src/xtd/drawing/native/cocoa/drawing.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
