//
// Created by Lower School Music on 3/24/23.
//

#include "ArtFiles.h"
#include <filesystem>

std::string ArtFiles::artFilenames[13][4];


ArtFiles::ArtFiles(std::string& filepath) {
    this->filepath = filepath;
    populateFilenameMatrix(2);
}


void ArtFiles::populateFilenameMatrix(int startingValue) {

    for (const auto& entry: std::filesystem::directory_iterator(filepath)) {

        std::string fullPath = entry.path().string();
        char osSpecificSlash;

        // accounts for slash/backslash path naming differences between windows and mac
        if (fullPath[0] == '/') {
            osSpecificSlash = '/';
        }
        else {
            osSpecificSlash = '\\';
        }

        std::string justFilename = fullPath.substr(fullPath.find_last_of(osSpecificSlash) + 1);

        std::string valueStr = justFilename.substr(0, justFilename.find('_'));

        int value = stod(valueStr);


        std::string suitStr = justFilename.substr(justFilename.find('_') + 1);
        int suit = stod(suitStr.substr(0, suitStr.find('.')));

        artFilenames[value - startingValue][suit] = fullPath;

    }
}

std::string ArtFiles::getFilepath() {
    return filepath;
}

void ArtFiles::setFilepath(std::string filepath) {
    this->filepath = filepath;
}
