cmake_minimum_required(VERSION 3.20)

project(input_dialog_password)
find_package(xtd REQUIRED)
add_sources(README.md src/input_dialog_password.cpp)
target_type(GUI_APPLICATION)
