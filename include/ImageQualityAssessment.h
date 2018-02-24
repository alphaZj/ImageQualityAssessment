#ifndef IMAGE_QUALITY_ASSESSMENT_
#define IMAGE_QUALITY_ASSESSMENT_

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

/********************************************************************************
*函数描述： ColorfulNess 计算并返回一幅图像的颜色丰富度
*函数参数： frame  彩色帧图
*函数返回值：double 颜色丰富度表示值（0-100）
*********************************************************************************/
double ColorfulNess(cv::Mat frame);

/********************************************************************************
*函数描述： DefRto 计算并返回一幅图像的清晰度
*函数参数： frame  彩色帧图
*函数返回值：double 清晰度表示值，针对该视频，当清晰度小于10为模糊，大于14为清楚
*********************************************************************************/
double DefRto(cv::Mat frame);

/********************************************************************************************
*函数描述： calcCast    计算并返回一幅图像的色偏度以及，色偏方向
*函数参数： InputImg    需要计算的图片，BGR存放格式，彩色（3通道），灰度图无效
*           cast        计算出的偏差值，小于1表示比较正常，大于1表示存在色偏
*           da          红/绿色偏估计值，da大于0，表示偏红；da小于0表示偏绿
*           db          黄/蓝色偏估计值，db大于0，表示偏黄；db小于0表示偏蓝
*函数返回值：   返回值通过cast、da、db三个应用返回，无显式返回值
*********************************************************************************************/
void colorException(cv::Mat InputImg,float& cast,float& da,float& db);

/*********************************************************************************************************************************************************
*函数描述： brightnessException     计算并返回一幅图像的色偏度以及，色偏方向
*函数参数： InputImg    需要计算的图片，BGR存放格式，彩色（3通道），灰度图无效
*           cast        计算出的偏差值，小于1表示比较正常，大于1表示存在亮度异常；当cast异常时，da大于0表示过亮，da小于0表示过暗
*函数返回值：   返回值通过cast、da两个引用返回，无显式返回值
**********************************************************************************************************************************************************/
void brightnessException (cv::Mat InputImg,float& cast,float& da);

#endif
