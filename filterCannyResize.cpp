#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/core/utility.hpp"
#include "opencv2/opencv.hpp"
#include <opencv2/cudaimgproc.hpp>
using namespace std;
using namespace cv;
int main()
{
Mat src=imread("image.jpg",0);
cuda::GpuMat d_src(src);
cuda::GpuMat d_dst;
cuda::bilateralFilter(d_src, d_dst, -1,50,50);
Mat dst;
d_dst.download(dst);
Canny(dst, dst, 35, 200, 3);
resize(dst, dst, Size(dst.cols/3, dst.rows/3));
imwrite("out.jpg", dst);
if(!dst.data){
cout<<"ayyo";
}
else
{
namedWindow( "Display window", WINDOW_AUTOSIZE );
imshow( "Display window", dst);
waitKey(0);
}                     
return 0;
}
