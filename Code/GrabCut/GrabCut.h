#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
class GrabCut
{
private:
	//������
	cv::Mat result;
	cv::Mat bgmodle, fgmodel;
public:
	//����grabCut����
	void getGrabCut(const cv::Mat& image, cv::Rect& rect)
	{
		//������������Ϊ10�����Ը��ݷָ������������
		cv::grabCut(image, result, rect, bgmodle, fgmodel, 10, cv::GC_INIT_WITH_RECT);
	}
	//��ʾǰ��
	void showFg(const cv::Mat& image)
	{
		cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
		cv::Mat foreground(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
		//���룬ȥ����ǰ������������
		image.copyTo(foreground, result);
		cv::imshow("result", result);
		cv::imshow("���", foreground);
		cv::waitKey(0);
	}
}; 
#pragma once
