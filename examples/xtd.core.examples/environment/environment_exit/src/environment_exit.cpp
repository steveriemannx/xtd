#include <xtd/xtd>

using namespace xtd;

namespace environment_exit_code_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main(auto args) {
      auto exit_status = args.size() ? xtd::exit_status::failure : exit_status::success;
      console::write_line("Before environment::exit(exit_status::{})", exit_status);
      environment::exit(exit_status);
      console::write_line("After environment::exit(exit_status::{})", exit_status);
    }
  };
}

startup_(environment_exit_code_example::program);

// This code can be produce the following output :
//
// Before environment::exit(exit_status::success)