#include "../../../include/xtd/forms/fourteen_segment_display.h"

using namespace xtd;
using namespace xtd::forms;

int32_t fourteen_segment_display::thickness() const noexcept {
  return data_->thickness.value_or(size().height() < 20 ? 1 : (size().height() / 20 + ((size().height() / 20) % 2 ? 0 : 1)));
}

seven_segment_display& fourteen_segment_display::thickness(int32_t value) {
  if (!data_->thickness.has_value() || data_->thickness.value() != value) {
    data_->thickness = value;
    invalidate();
  }
  return *this;
}

void fourteen_segment_display::draw_back_digit(drawing::graphics& graphics) {
  seven_segment_display::draw_back_digit(graphics);
  draw_segment_g1(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_g2(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_h(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_i(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_j(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_k(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_l(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
  draw_segment_m(graphics, drawing::color::average(back_segment_color(), back_color(), back_segment_opacity()));
}

void fourteen_segment_display::draw_segment_g(drawing::graphics& graphics, const drawing::color& color) {
}

void fourteen_segment_display::draw_segment_g1(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::modern) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + abs(2 * offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::mixed) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::expanded) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::design) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness() / 2 + abs(offset), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::stick) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), 2 + thickness(), size().height() / 2 + offset, size().width() / 2 - 1 - abs(offset), size().height() / 2 + offset);
  }
}

void fourteen_segment_display::draw_segment_g2(drawing::graphics& graphics, const drawing::color& color) {
  if (segment_style() == segment_style::standard) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::modern) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - abs(2 * offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::mixed) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::expanded) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::design) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness() / 2 - abs(offset), size().height() / 2 + offset);
  } else if (segment_style() == segment_style::stick) {
    for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
      graphics.draw_line(drawing::pen(color), size().width() / 2 + 1 + abs(offset), size().height() / 2 + offset, size().width() - 3 - thickness(), size().height() / 2 + offset);
  }
}

void fourteen_segment_display::draw_segment_h(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), 2 + thickness() + abs(offset), 2 + thickness(), size().width() / 2 - thickness() / 2 - 2, size().height() / 2 - 2 - thickness() / 2 - abs(offset));
    graphics.draw_line(drawing::pen(color), 2 + thickness(), 2 + thickness() + abs(offset), size().width() / 2 - 2 - thickness() / 2 - abs(offset), size().height() / 2 - 2 - thickness() / 2);
  }
}

void fourteen_segment_display::draw_segment_i(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
    graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, 2 + thickness(), size().width() / 2 - offset, size().height() / 2 - 1 - abs(offset));
}

void fourteen_segment_display::draw_segment_j(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness() - abs(offset), 2 + thickness(), size().width()  / 2 + 2 + thickness() / 2, size().height() / 2 - 2 - thickness() / 2 - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() - 3 - thickness(), 2 + thickness() + abs(offset), size().width() / 2 + 2 + thickness() / 2 + abs(offset), size().height() / 2 - 2 - thickness() / 2);
  }
}

void fourteen_segment_display::draw_segment_k(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width() / 2 - 2 - thickness() / 2 - abs(offset), size().height() / 2 + 2 + thickness() / 2, 2 + thickness(), size().height() - 3 - thickness() - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width() / 2 - 2 - thickness() / 2, size().height() / 2 + 2 + thickness() / 2 + abs(offset), 2 + thickness() + abs(offset), size().height() - 3 - thickness());
  }
}

void fourteen_segment_display::draw_segment_l(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++)
    graphics.draw_line(drawing::pen(color), size().width() / 2 - offset, size().height() / 2 + 1 - thickness() / 2 + thickness() / 2 + abs(offset), size().width() / 2 - offset, size().height() - 3 - thickness());
}

void fourteen_segment_display::draw_segment_m(drawing::graphics& graphics, const drawing::color& color) {
  for (int32_t offset = -thickness() / 2; offset < thickness() - thickness() / 2; offset++) {
    graphics.draw_line(drawing::pen(color), size().width()  / 2 + 2 + thickness() / 2 + abs(offset), size().height() / 2 + 2 + thickness() / 2, size().width() - 3 - thickness(), size().height() - 3 - thickness() - abs(offset));
    graphics.draw_line(drawing::pen(color), size().width()  / 2 + 2 + thickness() / 2, size().height() / 2 + 2 + thickness() / 2 + abs(offset), size().width() - 3 - thickness() - abs(offset), size().height() - 3 - thickness());
  }
}

void fourteen_segment_display::on_paint(paint_event_args& e) {
  seven_segment_display::on_paint(e);
  if ((value() & forms::segments::g1) == forms::segments::g1) draw_segment_g1(e.graphics(), fore_color());
  if ((value() & forms::segments::g2) == forms::segments::g2) draw_segment_g2(e.graphics(), fore_color());
  if ((value() & forms::segments::h) == forms::segments::h) draw_segment_h(e.graphics(), fore_color());
  if ((value() & forms::segments::i) == forms::segments::i) draw_segment_i(e.graphics(), fore_color());
  if ((value() & forms::segments::j) == forms::segments::j) draw_segment_j(e.graphics(), fore_color());
  if ((value() & forms::segments::k) == forms::segments::k) draw_segment_k(e.graphics(), fore_color());
  if ((value() & forms::segments::l) == forms::segments::l) draw_segment_l(e.graphics(), fore_color());
  if ((value() & forms::segments::m) == forms::segments::m) draw_segment_m(e.graphics(), fore_color());
}