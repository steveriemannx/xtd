cmake_minimum_required(VERSION 3.20)

project(checked_list_box)
find_package(xtd REQUIRED)
add_sources(README.md src/checked_list_box.cpp)
target_type(GUI_APPLICATION)
