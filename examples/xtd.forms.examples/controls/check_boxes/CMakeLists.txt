cmake_minimum_required(VERSION 3.20)

project(check_boxes)
find_package(xtd REQUIRED)
add_sources(README.md src/check_boxes.cpp)
target_type(GUI_APPLICATION)
