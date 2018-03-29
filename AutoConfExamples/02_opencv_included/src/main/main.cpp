#include <opencv2/opencv.hpp>


int main() {
  cv::Mat img = cv::imread("lena.jpg");
  
  cv::imwrite("lena_red.jpg", img);
  return 0;
}
