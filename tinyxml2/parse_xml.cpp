#include <tinyxml2.h>
#include <string>
#include <vector>

using namespace tinyxml2;

//g++ parse_xml.cpp -ltinyxml2 -std=c++11

std::vector<std::string> string_split(std::string str, std::string delimiter){
    size_t pos = 0;
    std::string token;
    std::vector<std::string> result;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
    return result;
}

int main(){
    /* ------ Example 1: Load and parse an XML file. ---- */ 
    XMLDocument doc;
    doc.LoadFile("yolov3p15.xml");
    XMLElement* element = doc.FirstChildElement("net")->FirstChildElement("layers");
    const char* c = element->FirstChildElement("layer")->FindAttribute("type")->Value();
    std::string anchor_text;
    std::vector<std::vector<int> > anchors;
    for(XMLNode* node = element->FirstChild(); node; node = node->NextSibling()){
        if(std::string(((XMLElement*)node)->FindAttribute("type")->Value()) == "RegionYolo"){
            anchor_text = node->FirstChildElement("data")->FindAttribute("anchors")->Value();
            printf("mask: %s\n", node->FirstChildElement("data")->FindAttribute("mask")->Value());
        }
    }

    printf("anchor_text: %s\n", anchor_text.c_str());

    std::vector<int> tmp;
    for(std::string e : string_split(anchor_text, ",")){
        tmp.push_back(std::stoi(e, nullptr));
        if(tmp.size() == 2){
            anchors.push_back(tmp);
            tmp = std::vector<int>();
        }
    }

    printf("anchors:\n");
    for(std::vector<int> anchor : anchors){
        printf("%d %d\n", anchor[0], anchor[1]);
    }
    return 0;
}
