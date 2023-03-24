//
// Created by Lower School Music on 3/24/23.
//

#ifndef CARDENGINE_ARTFILES_H
#define CARDENGINE_ARTFILES_H
#include <iostream>

class ArtFiles {
public:
    ArtFiles(std::string& filepath);
    static std::string artFilenames[13][4];
    void populateFilenameMatrix(int startingValue);



    std::string getFilepath();
    void setFilepath(std::string filepath);


private:
    std::string filepath;


};


#endif //CARDENGINE_ARTFILES_H
