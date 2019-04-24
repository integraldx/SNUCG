#include "SplineParser.hpp"

std::shared_ptr<Model> SplineParser::getModelFromTxt(std::string filePath)
{
    std::ifstream stream(filePath.data());

    if(stream.is_open())
    {
        std::string s;
        while(std::getline(stream, s))
        {
            std::cout << s << std::endl;
        }
        stream.close();
    }
    else
    {
        std::cout << "File not found." << std::endl;
        exit(1);
    }

    return NULL;
}