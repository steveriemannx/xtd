#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include "../../../assert_unit_tests/assert_unit_tests.hpp"

namespace xtd::tunit::tests {
  class test_class_(assert_are_not_equal_const_char32_t_pointer_failed_tests) {
  public:
    void test_method_(test_case_failed) {
      const char32* s = U"value";
      xtd::tunit::assert::are_not_equal(U"value", s);
    }
  };
  
  void test_(assert_are_not_equal_const_char32_t_pointer_failed_tests, test_output) {
    auto [output, result] = run_test_("xtd::tunit::tests::assert_are_not_equal_const_char32_t_pointer_failed_tests.*");
    assert_value_("Start 1 test from 1 test case\n"
                  "   FAILED xtd::tunit::tests::assert_are_not_equal_const_char32_t_pointer_failed_tests.test_case_failed\n"
                  "    Expected: not \"value\"\n"
                  "    But was:  \"value\"\n"
                  "End 1 test from 1 test case ran.\n", output);
  }
  
  void test_(assert_are_not_equal_const_char32_t_pointer_failed_tests, test_result) {
    auto [output, result] = run_test_("xtd::tunit::tests::assert_are_not_equal_const_char32_t_pointer_failed_tests.*");
    assert_value_(1, result);
  }
}
