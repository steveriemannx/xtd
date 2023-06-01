#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(file_assert_are_equal_istream_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      // As the xtd::tunit::file_assert::are_equal method uses std::istream and not std::ifstream, the test can be performed with std::istringstream.
      xtd::tunit::file_assert::are_equal(std::istringstream("Test xtd::tunit::file_assert::are_equal."), std::istringstream("Test xtd::tunit::file_assert::are_equal."));
    }
  };
}

void test_(file_assert_are_equal_istream_succeed_tests, test_output) {
  auto [result, output] = run_test_("file_assert_are_equal_istream_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED file_assert_are_equal_istream_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(file_assert_are_equal_istream_succeed_tests, test_result) {
  auto [result, output] = run_test_("file_assert_are_equal_istream_succeed_tests.*");
  assert_value_(0, result);
}