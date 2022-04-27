//��ֵ�˲��Խ��������кܺõĵ���������
//ԭ���������Ȧ����Χȡ��λ��
//��ֵ�˲��޷��˷���Ե������Ϣ��ʧ��ȱ�ݡ�ԭ���Ǿ�ֵ�˲��ǻ���ƽ��Ȩ�ء���˹ģ�����ֿ˷��˸�ȱ�ݣ������޷���ȫ���⣬��Ϊû�п�������ֵ�Ĳ�ͬ��
//��˹˫��ģ���Ǳ�Ե�������˲������������˱�Ե��Ϣ��ʧ�������������������䡣

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
  //����ͼ��
  Mat src = imread("girl.jpg");
  if(!src.data){
    cout<< "can't load image ..."<< endl;
    return -1;
  }

  imshow("src",src);

  //��ֵģ��
  // Mat mediaBlurMat;
  // medianBlur(src,mediaBlurMat,3);
  // imshow("mediaBlurMat",mediaBlurMat);

  //��˹˫���˲�
  Mat bilateralMat;
  /**
   * ˫���˲�����˵����
   * 15--->����뾶���뾶֮�ڵĶ��ᱻ������㣬����ṩ-1�����sigma space�������м���
   * 100--->sigma color �������ٲ�ֵ֮�ڵ����ػᱻ����
   * 5----->sigma space ���d��ֵ����0��������Ч�����������������d��ֵ
   **/
  bilateralFilter(src,bilateralMat,15,50,5);
  imshow("bilateralMat",bilateralMat);

  //��˫���˲����ͼ��ִ���񻯲���������ͼƬ������Լ�������
  Mat resultImage;
  Mat kernel = (Mat_<int>(3,3)<< 0, -1, 0, -1, 5, -1, 0, -1, 0);
  filter2D(bilateralMat,resultImage,-1,kernel,Point(-1,-1),0);
  imshow("resultImage",resultImage);

  waitKey(0);
  return 0;
}