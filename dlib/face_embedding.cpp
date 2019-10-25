#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <dlib/dnn.h>
#include <dlib/opencv.h> //dlib::cv_image
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/string.h> //dlib::move?
#include <dlib/clustering.h>
#include <dlib/image_io.h>

//compile with:
//g++ face_embedding.cpp -I /usr/local/include/opencv4 -L /usr/local/lib -lopencv_imgcodecs -lopencv_core -ldlib -lcblas -llapack -std=c++11

template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
using residual = dlib::add_prev1<block<N,BN,1,dlib::tag1<SUBNET>>>;

template <template <int,template<typename>class,int,typename> class block, int N, template<typename>class BN, typename SUBNET>
using residual_down = dlib::add_prev2<dlib::avg_pool<2,2,2,2,dlib::skip1<dlib::tag2<block<N,BN,2,dlib::tag1<SUBNET>>>>>>;

template <int N, template <typename> class BN, int stride, typename SUBNET>
using block  = BN<dlib::con<N,3,3,1,1,dlib::relu<BN<dlib::con<N,3,3,stride,stride,SUBNET>>>>>;

template <int N, typename SUBNET> using ares      = dlib::relu<residual<block,N,dlib::affine,SUBNET>>;
template <int N, typename SUBNET> using ares_down = dlib::relu<residual_down<block,N,dlib::affine,SUBNET>>;

template <typename SUBNET> using alevel0 = ares_down<256,SUBNET>;
template <typename SUBNET> using alevel1 = ares<256,ares<256,ares_down<256,SUBNET>>>;
template <typename SUBNET> using alevel2 = ares<128,ares<128,ares_down<128,SUBNET>>>;
template <typename SUBNET> using alevel3 = ares<64,ares<64,ares<64,ares_down<64,SUBNET>>>>;
template <typename SUBNET> using alevel4 = ares<32,ares<32,ares<32,SUBNET>>>;

using anet_type = dlib::loss_metric<dlib::fc_no_bias<128,dlib::avg_pool_everything<
                            alevel0<
                            alevel1<
                            alevel2<
                            alevel3<
                            alevel4<
                            dlib::max_pool<3,3,2,2,dlib::relu<dlib::affine<dlib::con<32,7,7,2,2,
                            dlib::input_rgb_image_sized<150>
                            >>>>>>>>>>>>;

int main(){
    std::string face_encoder_model = "dlib_face_recognition_resnet_model_v1.dat";
    std::string landmark_model = "shape_predictor_68_face_landmarks.dat";
    anet_type face_encoder;
    dlib::shape_predictor sp;
    dlib::deserialize(face_encoder_model) >> face_encoder;
    dlib::deserialize(landmark_model) >> sp;

    cv::Mat img = cv::imread("face.jpeg");
    dlib::matrix<dlib::rgb_pixel> dlib_img;
    dlib::assign_image(dlib_img, dlib::cv_image<dlib::rgb_pixel>(img));

    std::vector<dlib::matrix<dlib::rgb_pixel>> faces;
    dlib::frontal_face_detector ffdetector = dlib::get_frontal_face_detector();
    for (auto face : ffdetector(dlib_img))
    {
        //std::cout << face << std::endl;
        auto shape = sp(dlib_img, face);
        dlib::matrix<dlib::rgb_pixel> face_chip;
        dlib::extract_image_chip(dlib_img, dlib::get_face_chip_details(shape,150,0.25), face_chip);
        faces.push_back(std::move(face_chip));
    }
    std::cout << "Detect " << faces.size() << " faces." << std::endl;

    std::vector<dlib::matrix<float,0,1>> face_descriptors = face_encoder(faces);

    std::vector<std::vector<float> > face_embeddings;
    for(int i = 0; i < face_descriptors.size(); i++){
        face_embeddings.push_back(std::vector<float> (face_descriptors[0].begin(), face_descriptors[0].end()));
        std::cout << face_embeddings[i].size() << std::endl;
    }

    return 0;
}
