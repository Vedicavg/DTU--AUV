#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

void getContours(Mat imgDia, Mat img)
{
    vector<vector<Point>> contours;
    vector<Vec4i>hierarchy;

    findContours(imgDia,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    drawContours(img,contours,-1,Scalar (0,0,0),10);
}

/////////////////Image////////////////

int main ()
{
    string path = "/home/vedica/opencv lecture/chapter7/task2.jpeg";
    Mat img = imread(path);

    Mat imgGray,imgBlur,imgCanny,imgDia;

    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(img,imgBlur,Size(7,7),5,0);//Before using canny edge detector we commonly use GaussianBlur
    Canny(imgBlur,imgCanny,50,150);

    Mat kernal = getStructuringElement(MORPH_RECT,Size(5,5));//use only odd numbers in size

    dilate(imgCanny,imgDia,kernal);
    // erode(imgDia,imgErode,kernal);

     getContours( imgDia,img);// on img we want to draw and on imgdil we want to find the contours on

     imshow("Image",img);
    // imshow("Image Gray",imgGray);
    // imshow("Image Blur",imgBlur);
    // imshow("Image Canny",imgCanny);
    // imshow("Image Dilation",imgDia);
    // imshow("Image Erode",imgErode);


    waitKey(0);
    return(0);
}