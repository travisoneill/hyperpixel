#include <iostream>
// #include "libhyperpixel/utils.h"
#include "libhyperpixel/server.h"
// #include "cpp-httplib-0.7.14/httplib.h"

int main() {
  int port = 8080;
  std::cout << "Listening on port " <<  port << std::endl;
  server::runserver("0.0.0.0", port);
  std::cout << "Error server stopped" << std::endl;
  return 0;
}
