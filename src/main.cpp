#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;

void readme();

int main( int argc, char** argv )
{
    // 处理参数
    char *input_file, *output_file;
    for (int i = 1; i < argc; i ++) {
      if (i + 1 != argc) {
        if (0 == strcmp(argv[i], "-i")) {
          input_file = argv[++i];
        }
        else if (0 == strcmp(argv[i], "-o")) {
          output_file = argv[++i];
        }
        else {
          readme();
        }
      }
    }

    if (!input_file || !output_file) {
      readme();
    }

    return 0;
}

void readme() {
  std::cout << "usage: primitive -i input_file -o output_file\n" << std::endl;
  exit(0);
}
