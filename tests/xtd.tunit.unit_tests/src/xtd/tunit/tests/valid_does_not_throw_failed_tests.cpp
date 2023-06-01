#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(valid_does_not_throw_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector v = {1, 2, 3, 4};
      xtd::tunit::valid::does_not_throw([&] {v.at(5);});
    }
  };
}

void test_(valid_does_not_throw_failed_tests, test_output) {
  auto [result, output] = run_test_("valid_does_not_throw_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_does_not_throw_failed_tests.test_case_failed\n"
    "    Expected: No Exception to be thrown\n"
    "    But was:  <std::out_of_range>\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_does_not_throw_failed_tests, test_result) {
  auto [result, output] = run_test_("valid_does_not_throw_failed_tests.*");
  assert_value_(1, result);
}