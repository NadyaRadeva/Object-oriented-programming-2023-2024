#include <iostream>
#include <fstream>

const int MAX_LINE_LENGTH = 20;

int main() {
    unsigned int fileNameLen1;
    std::cout << "Enter the length of the first file name: ";
    std::cin >> fileNameLen1;
    if (!std::cin) {
        throw std::runtime_error("Error! Incorrect value!");
        return -1;
    }
  
    char* fileName1 = new char[fileNameLen1 + 1];
    std::cout << "Enter the name of your first file: ";
    std::cin.getline(fileName1, fileNameLen1 + 1);

    unsigned int fileNameLen2;
    std::cout << "Enter the length of the second file name: ";
    std::cin >> fileNameLen2;
    if (!std::cin) {
        throw std::runtime_error("Error! Incorrect value!");
        return -1;
    }
  
    char* fileName2 = new char[fileNameLen2 + 1];
    std::cout << "Enter the name of your second file: ";
    std::cin.getline(fileName2, fileNameLen2 + 1);
  
    char line[MAX_LINE_LENGTH + 1];

    std::ifstream iFile(fileName1);
    std::ofstream oFile(fileName2);

    if (!iFile.is_open()) {
        std::cerr << "Couldn't open first file!" << fileName1 << std::endl;
        return -1;
    }

    if (!oFile.is_open()) {
        std::cerr << "Couldn't open second file!" << fileName2 << std::endl;
        return -1;
    }

    while (iFile.getline(line, MAX_LINE_LENGTH + 1)) {
        char prefix[4];
        for (int i = 0; i < 3 && line[i] != '\0'; ++i) {
            prefix[i] = line[i];
        }
        prefix[3] = '\0';

        oFile << prefix << std::endl;
    }

    iFile.close();
    oFile.close();

    delete[] fileName1;
    delete[] fileName2;

    return 0;
}
