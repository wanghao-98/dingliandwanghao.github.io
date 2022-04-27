//中值滤波对椒盐噪声有很好的的抑制作用
//原理：卷积核所圈定范围取中位数
//均值滤波无法克服边缘像素信息丢失的缺陷。原因是均值滤波是基于平局权重。高斯模糊部分克服了该缺陷，但是无法完全避免，因为没有考虑像素值的不同。
//高斯双边模糊是边缘保留的滤波方法，避免了边缘信息丢失，保留了像素轮廓不变。

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
  //加载图形
  Mat src = imread("girl.jpg");
  if(!src.data){
    cout<< "can't load image ..."<< endl;
    return -1;
  }

  imshow("src",src);

  //中值模糊
  // Mat mediaBlurMat;
  // medianBlur(src,mediaBlurMat,3);
  // imshow("mediaBlurMat",mediaBlurMat);

  //高斯双边滤波
  Mat bilateralMat;
  /**
   * 双边滤波参数说明：
   * 15--->计算半径，半径之内的都会被纳入计算，如果提供-1则根据sigma space参数进行计算
   * 100--->sigma color 决定多少差值之内的像素会被计算
   * 5----->sigma space 如果d的值大于0则申明无效，否则根据他来计算d的值
   **/
  bilateralFilter(src,bilateralMat,15,50,5);
  imshow("bilateralMat",bilateralMat);

  //对双边滤波后的图像执行锐化操作，提升图片的棱角以及清晰度
  Mat resultImage;
  Mat kernel = (Mat_<int>(3,3)<< 0, -1, 0, -1, 5, -1, 0, -1, 0);
  filter2D(bilateralMat,resultImage,-1,kernel,Point(-1,-1),0);
  imshow("resultImage",resultImage);

  waitKey(0);
  return 0;
}