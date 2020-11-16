#include <iostream>
#include <fstream>
#include "../cpp-httplib-0.7.14/httplib.h"

namespace server {

  void runserver(const char* host, int port) {
    httplib::Server server;

    server.set_mount_point("/", "../frontend/static");
    server.set_mount_point("/data", "../project_data");

    server.Get("/hi", [](const httplib::Request&, httplib::Response& res) {
      res.set_content("Hello World!", "text/plain");
    });

    server.Get("/hi_json", [](const httplib::Request&, httplib::Response &res) {
      res.set_content("{\"message\":\"Hello World!\"}", "application/json");
    });

    server.Post("/upload", [](const httplib::Request& req, httplib::Response& res) {
      // int size = req.files.size();
      // std::cout << size << std::endl;
      // auto ret = req.has_file("file");
      // std::cout << ret << std::endl;
      const std::string project = req.get_file_value("project").content;
      const auto& file = req.get_file_value("file");

      std::cout << project << std::endl;
      std::cout << file.filename << std::endl;
      std::cout << file.content.length() << std::endl;
      std::cout << file.content_type << std::endl;
      std::cout << std::endl;

      std::string path = "../project_data/" + project + "/input_images/" + file.filename;
      std::cout << path << std:: endl;
      std::ofstream outfile;
      outfile.open(path);
      outfile << file.content;
      outfile.close();

      res.set_content("{\"message\":\"file recieved\"}", "application/json");
    });

    server.listen(host, port);
  }

}
