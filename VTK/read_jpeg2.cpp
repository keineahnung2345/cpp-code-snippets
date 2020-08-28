#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkJPEGReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkImageActor.h>

//https://gist.github.com/waldyrious/c3be68f0682543ee0ae2
//use render window

int main(int argc, char* argv[]){
    const char* IMG_FILE = "abc.jpg";
    vtkSmartPointer<vtkJPEGReader> reader =
        vtkSmartPointer<vtkJPEGReader>::New();
    reader->SetFileName(IMG_FILE);
    reader->Update();

    vtkSmartPointer<vtkImageActor> imageActor =
        vtkSmartPointer<vtkImageActor>::New();
    imageActor->SetInputData(reader->GetOutput());

    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(imageActor);

    vtkSmartPointer<vtkRenderWindow> window =
        vtkSmartPointer<vtkRenderWindow>::New();
    window->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(window);

    int imageSize[3];
    reader->GetOutput()->GetDimensions(imageSize);
    window->SetSize(imageSize[0] / 4, imageSize[1] / 4);
    interactor->Start();
}
