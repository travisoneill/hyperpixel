// #include <iostream>
// #include "libhyperpixel/utils.h"
#include "libhyperpixel/server.h"
// #include "cpp-httplib-0.7.14/httplib.h"

int main() {
  // std::cout << utils::get_frame_index_label(43, 8200) << std::endl;
  server::runserver("localhost", 8000);
  // bool out = utils::create_project("example");
  // std::cout << out << std::endl;
  // test2
  return 0;
}
