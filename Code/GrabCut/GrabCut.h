#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
class GrabCut
{
private:
	//保存结果
	cv::Mat result;
	cv::Mat bgmodle, fgmodel;
public:
	//调用grabCut函数
	void getGrabCut(const cv::Mat& image, cv::Rect& rect)
	{
		//迭代次数设置为10，可以根据分割情况适量增减
		cv::grabCut(image, result, rect, bgmodle, fgmodel, 10, cv::GC_INIT_WITH_RECT);
	}
	//显示前景
	void showFg(const cv::Mat& image)
	{
		cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
		cv::Mat foreground(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
		//掩码，去掉非前景的像素区域
		image.copyTo(foreground, result);
		cv::imshow("result", result);
		cv::imshow("结果", foreground);
		cv::waitKey(0);
	}
}; 
#pragma once
