#include <iostream>
#include <fstream>

int main() {
    std::ifstream iFile;

    iFile.open("File.txt");

    if (!iFile) {
        std::cerr << "File couldn't open!" << std::endl;
        return -1;
    }

    int lineCount = 0;
    char buffer[1000];
    while (iFile.getline(buffer, 1000)) {
        lineCount++;
    }

    std::cout << "Number of lines in the file: " << lineCount << std::endl;

    iFile.close();

    return 0;
}
