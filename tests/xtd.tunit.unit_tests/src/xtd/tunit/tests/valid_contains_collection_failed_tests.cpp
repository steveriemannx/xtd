#include "../../../assert_unit_tests/assert_unit_tests.h"
#include <xtd/xtd.tunit>
#include <vector>

namespace xtd::tunit::tests {
  class test_class_(valid_contains_collection_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector v = {0, 1, 2, 3};
      xtd::tunit::valid::contains(4, v);
    }
  };
}

void test_(valid_contains_collection_failed_tests, test_output) {
  auto [result, output] = run_test_("valid_contains_collection_failed_tests.*");
  assert_value_("Start 1 test from 1 test case\n"
    "  FAILED  valid_contains_collection_failed_tests.test_case_failed\n"
    "    Expected: collection containing 4\n"
    "    But was:  < 0, 1, 2, 3 >\n"
    "End 1 test from 1 test case ran.\n", output);
}

void test_(valid_contains_collection_failed_tests, test_result) {
  auto [result, output] = run_test_("valid_contains_collection_failed_tests.*");
  assert_value_(1, result);
}