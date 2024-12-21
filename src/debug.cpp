#include <gnu/libc-version.h>
#include <iostream>

void print_debug_info() {
  std::cout << std::string(55, '=') << std::endl;
  std::cout << "GNU libc version: " << gnu_get_libc_version() << std::endl;
  std::cout << "GNU libc release: " << gnu_get_libc_release() << std::endl;
  std::cout << std::string(55, '=') << std::endl;
}
