cmake_minimum_required(VERSION 3.20)

project(v_scroll_bar)
find_package(xtd REQUIRED)
add_sources(README.md src/v_scroll_bar.cpp)
target_type(GUI_APPLICATION)
