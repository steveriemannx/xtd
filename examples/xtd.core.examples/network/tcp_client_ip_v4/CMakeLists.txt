cmake_minimum_required(VERSION 3.20)

project(tcp_client_ip_v4)
find_package(xtd REQUIRED)
add_sources(README.md src/tcp_client_ip_v4.cpp)
target_type(CONSOLE_APPLICATION)
