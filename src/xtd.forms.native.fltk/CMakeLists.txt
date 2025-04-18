cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.native.fltk)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
add_include_directories("include")
add_references(xtd.drawing xtd.forms.native ${FLTK_LIBRARIES})
add_sources(
  "include/xtd/xtd.forms.native.fltk.hpp"
  "include/xtd/xtd.forms.native.fltk"
)
add_sources(
  "src/xtd/forms/native/fltk/application.cpp"
  "src/xtd/forms/native/fltk/button.cpp"
  "src/xtd/forms/native/fltk/check_box.cpp"
  "src/xtd/forms/native/fltk/checked_list_box.cpp"
  "src/xtd/forms/native/fltk/control.cpp"
  "src/xtd/forms/native/fltk/color_dialog.cpp"
  "src/xtd/forms/native/fltk/combo_box.cpp"
  "src/xtd/forms/native/fltk/control_handler.hpp"
  "src/xtd/forms/native/fltk/cursor.cpp"
  "src/xtd/forms/native/fltk/cursors.cpp"
  "src/xtd/forms/native/fltk/fl_button.hpp"
  "src/xtd/forms/native/fltk/fl_check_box.hpp"
  "src/xtd/forms/native/fltk/fl_checked_list_box.hpp"
  "src/xtd/forms/native/fltk/fl_combo_box.hpp"
  "src/xtd/forms/native/fltk/fl_control.hpp"
  "src/xtd/forms/native/fltk/fl_font_chooser.hpp"
  "src/xtd/forms/native/fltk/fl_form.hpp"
  "src/xtd/forms/native/fltk/fl_group_box.hpp"
  "src/xtd/forms/native/fltk/fl_label.hpp"
  "src/xtd/forms/native/fltk/fl_list_box.hpp"
  "src/xtd/forms/native/fltk/fl_panel.hpp"
  "src/xtd/forms/native/fltk/fl_progress_bar.hpp"
  "src/xtd/forms/native/fltk/fl_radio_button.hpp"
  "src/xtd/forms/native/fltk/fl_tab_control.hpp"
  "src/xtd/forms/native/fltk/fl_tab_page.hpp"
  "src/xtd/forms/native/fltk/fl_text_box.hpp"
  "src/xtd/forms/native/fltk/fl_timer.hpp"
  "src/xtd/forms/native/fltk/fl_track_bar.hpp"
  "src/xtd/forms/native/fltk/fl_user_control.hpp"
  "src/xtd/forms/native/fltk/font_dialog.cpp"
  "src/xtd/forms/native/fltk/form.cpp"
  "src/xtd/forms/native/fltk/group_box.cpp"
  "src/xtd/forms/native/fltk/label.cpp"
  "src/xtd/forms/native/fltk/list_box.cpp"
  "src/xtd/forms/native/fltk/message_box.cpp"
  "src/xtd/forms/native/fltk/panel.cpp"
  "src/xtd/forms/native/fltk/progress_bar.cpp"
  "src/xtd/forms/native/fltk/radio_button.cpp"
  "src/xtd/forms/native/fltk/screen.cpp"
  "src/xtd/forms/native/fltk/tab_control.cpp"
  "src/xtd/forms/native/fltk/tab_page.cpp"
  "src/xtd/forms/native/fltk/text_box.cpp"
  "src/xtd/forms/native/fltk/timer.cpp"
  "src/xtd/forms/native/fltk/track_bar.cpp"
  "src/xtd/forms/native/fltk/user_control.cpp"
)

if (APPLE)
  add_sources(
    "src/xtd/forms/native/fltk/cursor.mm"
  )
endif()

target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
