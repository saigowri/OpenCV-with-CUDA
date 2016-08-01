//In an image processing context, the histogram of an image normally refers to a histogram of the pixel intensity values. This histogram is a graph showing the number of pixels in an image at each different intensity value found in that image.

void processUsingOpenCvGpu(std::string input_file, std::string output_file) {
	//Read input image from the disk
	Mat inputCpu = imread(input_file,CV_LOAD_IMAGE_COLOR);
	if(inputCpu.empty())
	{
		std::cout<<"Image Not Found: "<< input_file << std::endl;
		return;
	}
 
	//Hold the histogram
	Mat hist, histImg;
 
	// create colors channels
	vector<Mat> colors;
	split(inputCpu, colors);
 
	cuda::GpuMat colorGpu (colors[2]); // select the third color channel
	cuda::GpuMat histGpu;
 
	// compute histogram
	cv::cuda::calcHist(colorGpu, histGpu);
	
	histGpu.download(hist);
	colorGpu.release();
	histGpu.release();
 
	// change the form from one row (n columns) to a vector (n rows)
	hist = hist.reshape(1, 256);
	
	// create an image out of the hist to be displayed
	histImg = imHist<unsigned int>(hist, 3, 3);
 
	imwrite(output_file, histImg);
}
