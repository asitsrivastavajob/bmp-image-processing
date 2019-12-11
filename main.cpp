#include "stdafx.h"
#include <iostream>
#include "ImageProcessing.h"

using namespace std;

int main()
{
    int imgWidth, imgHeight, imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[IMG_SIZE];
    unsigned char imgOutBuffer[IMG_SIZE];

    const char imgName[] ="images/girlface.bmp";
    const char newImgName[] ="images/girlface_copy.bmp";

    ImageProcessing *myImage  = new ImageProcessing(imgName,
                                                    newImgName,
                                                    &imgHeight,
                                                    &imgWidth,
                                                    &imgBitDepth,
                                                    &imgHeader[0],
                                                    &imgColorTable[0],
                                                    &imgInBuffer[0],
                                                    &imgOutBuffer[0]
                                                    );

     myImage->readImage();
     //myImage->copyImgData(imgInBuffer,imgOutBuffer,IMG_SIZE);
	 //myImage->binarizeImage(imgInBuffer, imgOutBuffer, IMG_SIZE,100);
	 //myImage->brigthnessUp(imgInBuffer, imgOutBuffer, IMG_SIZE, 10);
	 //myImage->brigthnessDown(imgInBuffer, imgOutBuffer, IMG_SIZE, 65);
	 myImage->RandomFilter(imgInBuffer, imgOutBuffer, IMG_SIZE, 65);
     myImage->writeImage();

     cout<<"Success !"<<endl;
     cout<<"Image Height : "<<imgHeight<<endl;
     cout<<"Image Width  : "  <<imgWidth<<endl;

    return 0;
}
