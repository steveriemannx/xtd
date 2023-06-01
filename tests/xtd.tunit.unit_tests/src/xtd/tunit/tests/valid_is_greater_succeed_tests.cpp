#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>

namespace xtd::tunit::tests {
  class test_class_(valid_is_greater_succeed_tests) {
  public:
    void test_method_(test_case_succeed) {
      int i = 42;
      xtd::tunit::valid::is_greater(i, 24);
    }
  };
}

void test_(valid_is_greater_succeed_tests, test_output) {
  auto [result, output] = run_test_("valid_is_greater_succeed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  SUCCEED valid_is_greater_succeed_tests.test_case_succeed\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_is_greater_succeed_tests, test_result) {
  auto [result, output] = run_test_("valid_is_greater_succeed_tests.*");
  assert_value_(0, result);
}