cmake_minimum_required(VERSION 3.20)

project(font_changed_event)
find_package(xtd REQUIRED)
add_sources(README.md src/font_changed_event.cpp)
target_type(GUI_APPLICATION)
