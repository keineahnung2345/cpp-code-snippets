#include "opencv2/opencv.hpp"
#include <iostream>
 
int main(){
 
    // Create a VideoCapture object and use camera to capture the video
    cv::VideoCapture cap(0); 
 
    // Check if camera opened successfully
    if(!cap.isOpened())
    {
        std::cout << "Error opening video stream" << std::endl; 
        return -1; 
    } 
 
    // Default resolution of the frame is obtained.The default resolution is system dependent. 
//    int frame_width = cap.get(cv::CV_CAP_PROP_FRAME_WIDTH); 
//    int frame_height = cap.get(cv::CV_CAP_PROP_FRAME_HEIGHT); 
    //update for OpenCV4
    int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH); 
    int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT); 
     
    // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file. 
    //VideoWriter video("outcpp.avi", cv::CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height)); 
    //update for OpenCV4
    cv::VideoWriter video("outcpp.avi", cv::CAP_OPENCV_MJPEG,10, cv::Size(frame_width,frame_height)); 
    while(1)
    { 
        cv::Mat frame; 
         
        // Capture frame-by-frame 
        cap >> frame;
    
        // If the frame is empty, break immediately
        if (frame.empty())
            break;
         
        // Write the frame into the file 'outcpp.avi'
        video.write(frame);
        
        // Display the resulting frame        
        cv::imshow( "Frame", frame );
    
        // Press    ESC on keyboard to    exit
        char c = (char)cv::waitKey(1);
        if( c == 27 ) 
            break;
    }
 
    // When everything done, release the video capture and write object
    cap.release();
    video.release();
 
    // Closes all the windows
    cv::destroyAllWindows();
    return 0;
}
