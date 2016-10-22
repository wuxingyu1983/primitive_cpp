#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;

void readme();
Scalar getAverageImageColor(const Mat& I);

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

    // read input image
    Mat input_img;
    input_img = imread(input_file, IMREAD_COLOR);

    // get average image color
    Scalar avg_color = getAverageImageColor(input_img);
    Mat output_img = Mat(input_img.rows, input_img.cols, CV_8UC3, avg_color);

    // save output image
    imwrite( output_file, output_img );

    return 0;
}

void readme() {
  std::cout << "usage: primitive -i input_file -o output_file\n" << std::endl;
  exit(0);
}

Scalar getAverageImageColor(const Mat& I) {
    int nRows = I.rows;
    int nCols = I.cols * 3;
    int i,j;
    int r,g,b;

    const uchar* p;
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr(i);
        for ( j = 0; j < nCols;)
        {
            b += p[j++];
            g += p[j++];
            r += p[j++];
        }
    }

//    std::cout << "r = " << (r / (I.rows * I.cols)) << ", g = " << (g / (I.rows * I.cols)) << ", b = " << (b / (I.rows * I.cols)) << std::endl;
    return Scalar((b / (I.rows * I.cols)), (g / (I.rows * I.cols)), (r / (I.rows * I.cols)));
}
