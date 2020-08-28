#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkJPEGReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

//https://vtk.org/Wiki/VTK/Examples/Cxx/IO/JPEGReader

int main(int argc, char* argv[]){
    //Read the image
    const char* IMG_FILE = "C:/Users/mimif/Downloads/IMG20200720095621.jpg";
    vtkSmartPointer<vtkJPEGReader> jpegReader =
        vtkSmartPointer<vtkJPEGReader>::New();
    jpegReader->SetFileName(IMG_FILE);

    // Visualize
    vtkSmartPointer<vtkImageViewer2> imageViewer =
        vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer->SetInputConnection(jpegReader->GetOutputPort());

    // An interactor
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();

    imageViewer->SetupInteractor(renderWindowInteractor);
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    imageViewer->Render();

    renderWindowInteractor->Start();
}
