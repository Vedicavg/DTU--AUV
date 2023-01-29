#include<iostream>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

//////////////color detection/////////////
Mat imgHSV , mask;
int hmin =73, smin=170,vmin=92,hmax=105,smax=255,vmax=255;

int main()

{
    string path = "/home/vedica/opencv lecture/test.jpeg";
    Mat img = imread(path);

    cvtColor(img,imgHSV, COLOR_BGR2HSV);

    //Declaring trackbar

    namedWindow("Trackbars",(640,200));
    createTrackbar("Hue min","Trackbars",&hmin,179);
    createTrackbar("Hue max","Trackbars",&hmax,179);
    createTrackbar("sat min","Trackbars",&smin,255);
    createTrackbar("sat max","Trackbars",&smax,255);
    createTrackbar("Val min","Trackbars",&vmin,255);
    createTrackbar("Val max","Trackbars",&vmax,255);

    while(true)
    {
    Scalar lower(hmin,smin,vmin);
    Scalar upper(hmax,smax,vmax);

    inRange(imgHSV,lower,upper,mask);

    imshow("image",img);
    imshow("Image HSV",imgHSV);
    imshow("Image Mask",mask);
    waitKey(1); //1 
    }
    

}
