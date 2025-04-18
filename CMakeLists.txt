cmake_minimum_required(VERSION 3.20)

################################################################################
# Solution

project(xtd)

################################################################################
# Options

option(XTD_BUILD_SHARED_LIBRARIES "Build shared libraries" OFF)
option(XTD_BUILD_TESTS "Build tests" OFF)
option(XTD_BUILD_TOOLS "Build tools" ON)
option(XTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM "Build with the continuous integration (CI) system. This flag should always be set to OFF. It is only needed for continuous integration." OFF)
option(XTD_DOWNLOAD_ASTYLE "Download and build astyle from Github" OFF)
option(XTD_DOWNLOAD_CPPCHECK "Download and build cppcheck from Github" OFF)
option(XTD_DOWNLOAD_DOXYGEN "Download and build doxygen from Github" OFF)
option(XTD_ENABLE_COVERAGE "Enable code coverage" OFF)
option(XTD_ENABLE_EXTRA_PROJECTS "Enable exptra projects (docs, local and scripts" OFF)
option(XTD_ENABLE_RUN_ASTYLE "Enable run astyle (format) command" ON)
option(XTD_ENABLE_RUN_CPPCHECK "Enable run cppcheck command" ON)
option(XTD_ENABLE_RUN_DEVELOPER_REFERENCE_GUIDE "Add run Developer Reference Guide generator command" OFF)
option(XTD_ENABLE_RUN_REFERENCE_GUIDE "Add run Reference Guide generator command" ON)
option(XTD_INSTALL_EXAMPLES "Install examples" ON)
option(XTD_INSTALL_RESOURCES "Install resources" ON)
option(XTD_KEEP_CLONED_CONTROLS "Keep cloned controls by default (Only for debugging)" OFF)
option(XTD_SET_COMPILER_OPTION_WARNINGS_TO_ALL "Enable compiler option warnings to all" ON)
option(XTD_SET_COMPILER_OPTION_WARNINGS_AS_ERRORS "Enable compiler option warnings as errors" OFF)
option(XTD_USE_SYSTEM_CONTROLS "Use by default system controls instead standard controls (Only for debugging)" OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)

set(ASTYLE_SOURCE_FILES 
  "${CMAKE_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_SOURCE_DIR}/src/*.hpp"
  "${CMAKE_SOURCE_DIR}/src/*.mm"
  "${CMAKE_SOURCE_DIR}/tests/*.cpp"
  "${CMAKE_SOURCE_DIR}/tests/*.hpp"
  "${CMAKE_SOURCE_DIR}/tools/*.cpp"
  "${CMAKE_SOURCE_DIR}/tools/*.hpp"
)

set(CPPCHECK_SOURCE_ROOTS ${CMAKE_SOURCE_DIR}/src)

if (XTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM)
  add_definitions(-D__XTD_BUILD_WITH_CONTINUOUS_INTEGRATION_SYSTEM__)
endif ()

if (XTD_KEEP_CLONED_CONTROLS)
  message(WARNING "The XTD_KEEP_CLONED_CONTROLS option can only be used for debugging.\nUse xtd::application::keep_cloned_controls() instead.\nSee https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a28ad4db693e3bf228e5f0902fdf5882a for more information")
  add_definitions(-D__ XTD_KEEP_CLONED_CONTROLS__)
endif ()

if (XTD_USE_SYSTEM_CONTROLS)
  message(WARNING "The XTD_USE_SYSTEM_CONTROLS option can only be used for debugging.\nUse xtd::application::enable_system_controls() instead.\nSee https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1application.html#a28ad4db693e3bf228e5f0902fdf5882a for more information")
  add_definitions(-D__XTD_USE_SYSTEM_CONTROLS__)
endif ()

################################################################################
# incldue xtd cmake scripts

include("scripts/cmake/xtd_commands.cmake")
include("scripts/cmake/xtd_version.cmake")
include("scripts/cmake/update_export.cmake")
include("scripts/cmake/update_version_number.cmake")
include("scripts/cmake/package.cmake")

################################################################################
# Graphic toolkits definitions

get_operating_system_name(XTD_OPERATING_SYSTEM_NAME)
if (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Darwin" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "macOS")
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" "macOS" "iOS" "Android")
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" "wxwidgets" "cocoa" "qt5" "fltk")
elseif (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "FreeBSD")
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" "Unix" "Android")
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" "wxwidgets" "gtk4" "gtk3" "qt5" "fltk")
elseif (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Linux")
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" "Linux" "Android")
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" "wxwidgets" "gtk4" "gtk3" "qt5" "fltk")
elseif (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "MSYS")
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" "MSYS")
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" "wxwidgets" "gtk4" "gtk3" "qt5" "fltk")
elseif (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Windows")
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" "Windows" "Android")
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" "wxwidgets" "msw" "qt5" "fltk")
else ()
  message(FATAL_ERROR "The Operating system \"${XTD_OPERATING_SYSTEM_NAME}\" is unknown!")
endif ()

################################################################################
# set core native library

#add_definitions(-D__XTD_NATIVE_OPERATING_SYSTEM__="${XTD_NATIVE_OPERATING_SYSTEM}")

if (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "Android")
  #set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.android)
  message(FATAL_ERROR "Not yet implemented!")
elseif (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "iOS")
  #set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.ios)
  message(FATAL_ERROR "Not yet implemented!")
elseif (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "Linux")
  set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.linux)
elseif (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "macOS")
  set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.macos)
elseif (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "MSYS")
  set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.win32)
  set(XTD_CORE_NATIVE_3RDPARTY_LIBRARIES xtd.3rdparty.StackWalker)
  add_compile_options(-Wno-implicit-const-int-float-conversion -Wno-c++20-extensions -Wno-unqualified-std-cast-call -Wno-deprecated-declarations -Wno-missing-braces -Wno-tautological-constant-out-of-range-compare)
elseif (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "Unix")
  set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.unix)
elseif (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "Windows")
  set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.win32)
  set(XTD_CORE_NATIVE_3RDPARTY_LIBRARIES xtd.3rdparty.StackWalker)
else ()
  message(FATAL_ERROR "Operating system \"${XTD_NATIVE_OPERATING_SYSTEM}\" is unknown!")
endif ()

################################################################################
# set drawing and forms native library

#add_definitions(-D__XTD_NATIVE_GRAPHIC_TOOLKIT__="${XTD_NATIVE_GRAPHIC_TOOLKIT}")
if (${XTD_NATIVE_GRAPHIC_TOOLKIT} STREQUAL "cocoa")
  message(WARNING "Cocoa toolkit is only supported for development, used wxwidgets instead.\nCocoa toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.cocoa)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.cocoa)
endif ()
if (${XTD_NATIVE_GRAPHIC_TOOLKIT} STREQUAL "fltk")
  message(WARNING "FLTK toolkit is only supported for xtd framework development, used wxwidgets instead.\nFLTK toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.fltk)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()
if (${XTD_NATIVE_GRAPHIC_TOOLKIT} STREQUAL "gtk3")
  message(WARNING "Gtk+3 toolkit is only supported for xtd framework development, used wxwidgets instead.\nGtk+3 toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk3)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk3)
endif ()
if (${XTD_NATIVE_GRAPHIC_TOOLKIT} STREQUAL "gtk4")
  message(WARNING "Gttk+4 toolkit is only supported for xtd framework development, used wxwidgets instead.\nGtk+4 toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk4)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk4)
endif ()
if (${XTD_NATIVE_GRAPHIC_TOOLKIT} STREQUAL "qt5")
  message(WARNING "Qt5 toolkit is only supported for xtd framework development, used wxwidgets instead.\nQt5 toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.qt5)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()
if (${XTD_NATIVE_GRAPHIC_TOOLKIT} STREQUAL "msw")
  message(WARNING "Microsoft Windows toolkit is only supported for xtd framework development, used wxwidgets instead.\nMicrosoft Windows toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.win32)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.win32)
endif ()
if (${XTD_NATIVE_GRAPHIC_TOOLKIT} STREQUAL "wxwidgets")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.wxwidgets)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.wxwidgets)
endif ()

################################################################################
# Code coverage

if (XTD_ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

################################################################################
# set xtd library type (shared or static)

if (XTD_BUILD_SHARED_LIBRARIES)
  set(XTD_LIBRARY_TYPE SHARED_LIBRARY)
else()
  set(XTD_LIBRARY_TYPE STATIC_LIBRARY)
endif()

if (XTD_BUILD_TESTS_XTD_CORE OR XTD_BUILD_TESTS_XTD_DRAWING OR XTD_BUILD_TESTS_XTD_FORMS OR  XTD_BUILD_TESTS_XTD_TUNIT)
  enable_testing()
endif ()

################################################################################
# Projects

if (XTD_ENABLE_EXTRA_PROJECTS)
  add_projects(docs locale scripts)
endif ()

add_projects(src)

if (XTD_BUILD_TESTS)
  add_projects(tests)
endif ()

if (XTD_ENABLE_EXTRA_PROJECTS)
  add_projects(themes)
endif ()

if (XTD_BUILD_TOOLS)
  add_projects(tools)
endif ()

################################################################################
# Run Developper Reference Guide generator command

if (XTD_ENABLE_RUN_DEVELOPER_REFERENCE_GUIDE)
  file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/developer_html")
  add_custom_target(RUN_DEVELOPER_REFERENCE_GUIDE ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen/doxygen_developer.txt WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen COMMAND ${XTD_RUN_COMMAND} "${CMAKE_CURRENT_BINARY_DIR}/developer_html/index.html" COMMENT "Run Doxygen Developper Reference Guide generation" DEPENDS ${DOXYGEN_PROJECT} VERBATIM)
  set_target_properties(RUN_DEVELOPER_REFERENCE_GUIDE PROPERTIES FOLDER commands)
endif ()

# Updates export file
string(REPLACE "." "_" XTD_CORE_NATIVE_LIBRARY_UPPER ${XTD_CORE_NATIVE_LIBRARY})
string(TOUPPER ${XTD_CORE_NATIVE_LIBRARY_UPPER} XTD_CORE_NATIVE_LIBRARY_UPPER)
xtd_update_export_file(src/${XTD_CORE_NATIVE_LIBRARY}/include/xtd/core_native_export.hpp ${XTD_CORE_NATIVE_LIBRARY_UPPER}_EXPORT core_native_export_)
xtd_update_export_file(src/xtd.core/include/xtd/core_export.hpp XTD_CORE_EXPORT core_export_)
string(REPLACE "." "_" XTD_DRAWING_NATIVE_LIBRARY_UPPER ${XTD_DRAWING_NATIVE_LIBRARY})
string(TOUPPER ${XTD_DRAWING_NATIVE_LIBRARY_UPPER} XTD_DRAWING_NATIVE_LIBRARY_UPPER)
xtd_update_export_file(src/${XTD_DRAWING_NATIVE_LIBRARY}/include/xtd/drawing_native_export.hpp ${XTD_DRAWING_NATIVE_LIBRARY_UPPER}_EXPORT drawing_native_export_)
xtd_update_export_file(src/xtd.drawing/include/xtd/drawing_export.hpp XTD_DRAWING_EXPORT drawing_export_)
string(REPLACE "." "_" XTD_FORMS_NATIVE_LIBRARY_UPPER ${XTD_FORMS_NATIVE_LIBRARY})
string(TOUPPER ${XTD_FORMS_NATIVE_LIBRARY_UPPER} XTD_FORMS_NATIVE_LIBRARY_UPPER)
xtd_update_export_file(src/${XTD_FORMS_NATIVE_LIBRARY}/include/xtd/forms_native_export.hpp ${XTD_FORMS_NATIVE_LIBRARY_UPPER}_EXPORT forms_native_export_)

xtd_update_export_file("src/xtd.forms/include/xtd/forms_export.hpp" XTD_FORMS_EXPORT forms_export_)
xtd_update_export_file("src/xtd.tunit/include/xtd/tunit_export.hpp" XTD_TUNIT_EXPORT tunit_export_)
xtd_update_export_file("src/xtd/include/xtd/export.hpp" XTD_EXPORT export_)

################################################################################
# Run tests

set(CMAKE_CTEST_ARGUMENTS ${CMAKE_CTEST_ARGUMENTS} --output-on-failure)

################################################################################
# Install

install_package()
# override with specific xtd cmake config file
set(XTD_CONFIG_CMAKE_FILE ${CMAKE_CURRENT_BINARY_DIR}/xtdConfig.cmake)
file(WRITE "${XTD_CONFIG_CMAKE_FILE}"
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_modules/xtd_commands.cmake\")\n"
  "set(CMAKE_MODULE_PATH \${CMAKE_MODULE_PATH} \${CMAKE_CURRENT_LIST_DIR}/xtd_modules)\n"
  "\n"
  "set(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\")\n"
  "set(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\")\n"
  "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME} xtd.core xtd.drawing xtd.forms xtd.tunit xtd)\n"
  "set(${PROJECT_NAME}_FOUND TRUE)\n"
)
install(FILES scripts/cmake/xtd_commands.cmake DESTINATION cmake/xtd_modules)
install(FILES scripts/cmake/MacOSXBundleInfo.plist.in DESTINATION cmake/xtd_modules)
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY resources DESTINATION share/xtd)
  install(DIRECTORY docs/pictures/examples/. DESTINATION share/xtd/resources/pictures/examples)
endif ()
if (XTD_INSTALL_EXAMPLES)
  install(DIRECTORY examples/. DESTINATION share/xtd/examples)
endif ()

if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY themes/default DESTINATION share/xtd/themes)
  install(DIRECTORY themes/gnome_dark DESTINATION share/xtd/themes)
  install(DIRECTORY themes/gnome_light DESTINATION share/xtd/themes)
  install(DIRECTORY themes/kde_dark DESTINATION share/xtd/themes)
  install(DIRECTORY themes/kde_light DESTINATION share/xtd/themes)
  install(DIRECTORY themes/macos_dark DESTINATION share/xtd/themes)
  install(DIRECTORY themes/macos_light DESTINATION share/xtd/themes)
  install(DIRECTORY themes/symbolic_dark DESTINATION share/xtd/themes)
  install(DIRECTORY themes/symbolic_light DESTINATION share/xtd/themes)
  install(DIRECTORY themes/windows_dark DESTINATION share/xtd/themes)
  install(DIRECTORY themes/windows_light DESTINATION share/xtd/themes)
  install(DIRECTORY themes/xtd_dark DESTINATION share/xtd/themes)
  install(DIRECTORY themes/xtd_light DESTINATION share/xtd/themes)
  install(DIRECTORY locale DESTINATION share/xtd)
endif ()
