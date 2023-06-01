#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(file_assert_exists_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      xtd::io::file::write_all_text(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), "Test xtd::tunit::file_assert::exists.");
      
      file_assert::exists(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"), csf_);
      
      xtd::io::file::remove(xtd::io::path::combine(xtd::io::path::get_temp_path(), "test_tunit_file.txt"));
    }
  };
}

void test_(file_assert_exists_succeed_tests, test_output) {
  auto [result, output] = run_test_("file_assert_exists_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED file_assert_exists_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(file_assert_exists_succeed_tests, test_result) {
  auto [result, output] = run_test_("file_assert_exists_succeed_tests.*");
  assert_value_(0, result);
}