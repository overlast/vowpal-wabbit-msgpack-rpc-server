#include <cstdlib>
#include <string>
#include "cmdline.h"

class LibSVM2VW {
 public:
  LibSVM2VW(void) {}

 public:
  void convert (std::string in_file_path, std::string out_file_path) {
    return;
  }
};

int main(int argc, char *argv[]) {
  LibSVM2VW *parser = new LibSVM2VW();
  std::string in_file_path;
  std::string out_file_path;
  cmdline::parser cmdp;
  cmdp.add<std::string>("input", 'i', "Path of libsvm format file (Must define)");
  cmdp.add<std::string>("output", 'o', "Path of vopal_wabbit format file which will made from libsvm format file (Must define)");
  cmdp.add("help", 'h', "Print help");

  if (!cmdp.parse(argc, argv) || cmdp.exist("help") || !cmdp.exist("input") || !cmdp.exist("output")){
    std::cout << cmdp.error_full() << cmdp.usage();
    return 0;
  }
  in_file_path = cmdp.get<std::string>("input");
  out_file_path = cmdp.get<std::string>("output");
  parser->convert(in_file_path, out_file_path);
}
