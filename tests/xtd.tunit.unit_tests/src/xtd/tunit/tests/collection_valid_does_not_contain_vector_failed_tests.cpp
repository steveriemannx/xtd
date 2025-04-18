#include <xtd/tunit/collection_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(collection_valid_does_not_contain_vector_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector<int> a = {1, 2, 3, 4};
      xtd::tunit::collection_valid::does_not_contain({1, 2}, a);
    }
  };
  
  void test_(collection_valid_does_not_contain_vector_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::collection_valid_does_not_contain_vector_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "   FAILED xtd::tunit::tests::collection_valid_does_not_contain_vector_failed_tests.test_case_failed\n"
                  "    Expected: not contains < 1, 2 >\n"
                  "    But was:  < 1, 2, 3, 4 >\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(collection_valid_does_not_contain_vector_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::collection_valid_does_not_contain_vector_failed_tests.*");
    assert_value_(1, result);
  }
}
