// basicCamera.cpp : Defines the entry point for the console application.
//
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include "stdafx.h"
using namespace cv;
using namespace std;

int processFrame(VideoCapture& Camera, VideoCapture& Camera2);


int main(int argc, char** argv)
{
	VideoCapture cap, cap2;
	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	
	
	// to open the default web camera
	if (!cap.open(0)){
		cout << "Camera Is not able to be Opened, is it connected?" << endl;
		return 0;
		cin.ignore();
		}

	
	/*

	// to open video file
	if (!cap.open("Video_1.mp4")){
		cout << "video file Is not able to be Opened, does it exist?" << endl;
		cin.ignore();
		return 0;
	}
	*/
	//process the camera input
	processFrame(cap, cap2);
	// the camera will be closed automatically upon exit
	// cap.close();
	return 0;
}

//process input
int processFrame(VideoCapture& camera, VideoCapture& camera2){
	for (;;)
	{
		Mat frame, frame2; // matrix container for image frame
		camera >> frame; //grab the next frame of video in sequence
		camera >> frame2; //grab the next frame of video in sequence
		if (frame.empty()) break; // end of video stream
		
		/*
		//do stuff with the image,
		Mat element = getStructuringElement(MORPH_RECT,
			Size(3, 3),
			Point(2, 2));
		Mat edges;
		Scalar bluMin(92, 60, 40);
		Scalar bluMax(124, 256, 256);

		inRange(frame, bluMin, bluMax, edges);

		//cvtColor(frame, edges, COLOR_BGR2GRAY);
		cv::erode(edges, edges, element, Point(-1, -1), 2);
		cv::dilate(edges, edges, element, Point(-1, -1), 1);
		//GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		//Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges); // display the frame for the user to view
		*/
		imshow("frame1 ", frame); // display the frame for the user to view
		imshow("frame2", frame2); // display the frame for the user to view

		if (waitKey(1) == 27) break; // stop capturing by pressing ESC 
	}
	return 0;
}