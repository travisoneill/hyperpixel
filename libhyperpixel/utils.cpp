#include <iostream>
#include <string>
#include <math.h>
#include <filesystem>
namespace fs = std::filesystem;


namespace utils {

  int create_project(std::string project_name) {
    const std::string project_data_root = "../project_data/";
    const std::string project_dir = project_data_root + project_name;

    bool directory_created = fs::create_directory(project_dir);
    if (!directory_created) {
      return false;
    }

    // create project subdirectories
    fs::create_directory(project_dir + "/" + "input_images");
    fs::create_directory(project_dir + "/" + "output_segment_maps");
    fs::create_directory(project_dir + "/" + "output_annotation_maps");
    fs::create_directory(project_dir + "/" + "output_segmeted_images");

    // std::cout << out << std::endl;
    return true;
  }

  // returns padded label of correct length for number based on count
  // e.g. frame idx = 25 frame count = 1500 => "0025"
  std::string get_frame_index_label(int frame_idx, int frame_count) {
    size_t num_digits = int(log10(frame_count)) + 1;
    std::string out = std::to_string(frame_idx);

    while (out.length() < num_digits) {
      out = "0" + out;
    }

    return out;
  }

}
