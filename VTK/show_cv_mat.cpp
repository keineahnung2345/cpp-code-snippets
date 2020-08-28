#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkJPEGReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

vtkSmartPointer<vtkImageData> convertCVMatToVtkImageData(const cv::Mat &sourceCVImage, bool flipOverXAxis) {
    //https://stackoverflow.com/questions/51931411/how-to-convert-cvmat-to-vtkimagedata
    vtkSmartPointer<vtkImageData> outputVtkImage = vtkSmartPointer<vtkImageData>::New();

    int numOfChannels = sourceCVImage.channels();

    // dimension set to 1 for z since it's 2D
    outputVtkImage->SetDimensions(sourceCVImage.cols, sourceCVImage.rows, 1);

    // NOTE: if your image isn't uchar for some reason you'll need to change this type
    outputVtkImage->AllocateScalars(VTK_UNSIGNED_CHAR, numOfChannels);

    // the flipped image data gets put into tempCVImage
    cv::Mat tempCVImage;
    if (flipOverXAxis) { // Normally you should flip the image!
        cv::flip(sourceCVImage, tempCVImage, 0);
    }
    else {
        tempCVImage = sourceCVImage;
    }

    // the number of byes in the cv::Mat, assuming the data type is uchar
    size_t byte_count = sourceCVImage.cols * sourceCVImage.rows * numOfChannels * sizeof(unsigned char);

    // copy the internal cv::Mat data into the vtkImageData pointer
    memcpy(outputVtkImage->GetScalarPointer(), tempCVImage.data, byte_count);

    outputVtkImage->Modified();

    return outputVtkImage;
};

int main(int argc, char* argv[]){
    cv::Mat img = cv::imread("abc.jpg", 0);
    vtkSmartPointer<vtkImageViewer2> imageViewer =
        vtkSmartPointer<vtkImageViewer2>::New();
    
    imageViewer->SetInputData(convertCVMatToVtkImageData(img, true));

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();

    imageViewer->SetupInteractor(renderWindowInteractor);
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    imageViewer->Render();

    renderWindowInteractor->Start();
}
