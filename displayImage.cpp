#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/core/utility.hpp"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main()
{
Mat src=imread("image.jpg",0); //load image from file
cuda::GpuMat d_src(src);  // cpu -> gpu
cuda::GpuMat d_dst;
Mat dst;
d_dst.download(dst); //gpu -> cpu
imwrite("out.jpg", dst); //save image to file
if(!dst.data){
cout<<"Image cannot be displayed";
}
else
{
namedWindow( "Display window", WINDOW_AUTOSIZE ); //open display window
imshow( "Display window", dst); 
waitKey(0);                   // Wait for a keystroke in the window 
                              // since param is 0, wait forever.
}
return 0;
}
