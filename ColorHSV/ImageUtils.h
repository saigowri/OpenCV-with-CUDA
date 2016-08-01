#ifndef NV_IMAGE_UTILS_H
#define NV_IMAGE_UTILS_H

#if defined (__cplusplus)
extern "C"
{
#endif


// Returns cropped version of the original image.
IplImage* cropRectangle(IplImage *img, CvRect region);

// Draw a rectangle around the given object (use CV_RGB(200,0,0) for red color)
void drawRectangle(IplImage *img, CvRect face, CvScalar col);

// Creates a new image copy that is of a different size.
IplImage* resizeImage(IplImage *origImg, int newWidth, int newHeight);

// Rotate clockwise by a number of radians and enlarged.
IplImage *rotateImage(IplImage *src, IplImage* dst, float angle, float scale);

// Save the given image to a JPG or BMP file, even if its format isn't an 8-bit image, such as a 32bit image.
int saveImage(char *filename, IplImage *image);

// Store a greyscale floating-point CvMat image into a BMP/JPG/GIF/PNG image,
// since cvSaveImage() can only handle 8bit images (not 32bit float images).
void saveFloatMat(const char *filename, const CvMat *src);

// Store a greyscale floating-point CvMat image into a BMP/JPG/GIF/PNG image,
// since cvSaveImage() can only handle 8bit images (not 32bit float images).
void saveFloatImage(const char *filename, const IplImage *srcImg);

// Print some text info about the IplImage properties, to std::cerr.
void printImageInfo(IplImage *image_tile);



#if defined (__cplusplus)
}
#endif

#endif // NV_IMAGE_UTILS_H
