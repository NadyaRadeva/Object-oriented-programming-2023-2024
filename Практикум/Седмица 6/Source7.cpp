#include <iostream>
#include <fstream>

const int MAX_LINE_LENGTH = 20;

int main() {
    unsigned int fileNameLen;
    std::cout << "Enter the length of the file name: ";
    std::cin >> fileNameLen;
    if(!std::cin) {
      throw std::runtime_error("Error! Incorrect value!");
      return -1;
    }
  
    char* fileName = new char[fileNameLen + 1];
    std::cout << "Enter the name of your file: ";
    std::cin.getline(fileName, fileNameLen + 1);

    std::ofstream iFile(fileName);

    if (!iFile.open()) {
        std::cerr << "Couldn't open file!" << filename << std::endl;
        return -1;
    }

    std::cout << "Enter lines (max length 20), then type 'stop' to end:" << std::endl;

    while (true) {
        std::cin >> input;

        if (strcmp(input, "stop") == 0) {
            break;
        }

        if (strlen(input) > MAX_LINE_LENGTH) {
            std::cerr << "Error! Your line exceeds maximum length of 20 characters." << std::endl;
            continue;
        }

        file << input << std::endl;
    }

    delete[] fileName;
        
    iFile.close();

    return 0;
}
