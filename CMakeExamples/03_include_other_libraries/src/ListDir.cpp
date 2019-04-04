#include "ListDir.h"
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

using namespace boost::filesystem;

std::vector<std::string> ListDir(const std::string& input_path) {
  path input_filename(input_path);
  
  auto directory_it = directory_iterator(input_filename);
  std::vector<std::string> output;
  for (auto &file : boost::make_iterator_range(directory_it, {})) {
    output.push_back(file.path().string());
  }
  return output;
}
