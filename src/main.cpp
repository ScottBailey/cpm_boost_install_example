#include <iostream>
#include <boost/filesystem.hpp>

int main(int,char**) {
  boost::filesystem::path path = ".";
  boost::system::error_code bec;
  for(const boost::filesystem::path p : boost::filesystem::recursive_directory_iterator(path,bec)) {
    std::cout << p << std::endl;
  }

  return 0;
}
