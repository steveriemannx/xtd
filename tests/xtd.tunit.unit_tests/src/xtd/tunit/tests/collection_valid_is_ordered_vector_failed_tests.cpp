#include <xtd/tunit/collection_valid>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(collection_valid_is_ordered_vector_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      std::vector<int> a = {1, 4, 8, 6};
      xtd::tunit::collection_valid::is_ordered(a);
    }
  };
  
  void test_(collection_valid_is_ordered_vector_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::collection_valid_is_ordered_vector_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "   FAILED xtd::tunit::tests::collection_valid_is_ordered_vector_failed_tests.test_case_failed\n"
                  "    Expected: <ordered>\n"
                  "    But was:  < 1, 4, 8, 6 >\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(collection_valid_is_ordered_vector_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::collection_valid_is_ordered_vector_failed_tests.*");
    assert_value_(1, result);
  }
}
