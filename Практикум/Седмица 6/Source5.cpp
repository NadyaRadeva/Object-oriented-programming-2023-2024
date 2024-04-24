#include<iostream>
#include<fstream>

int main() {
	std::ifstream iFile;
	std::fstream oFile;

	iFile.open("File.txt");
	if (!iFile) {
		std::cerr << "File couldn't open!" << std::endl;
		return -1;
	}

	oFile.open("File1.txt");
	if (!oFile) {
		std::cerr << "File couldn't open!" << std::endl;
		return -1;
	}

	char c;
	while (iFile.get(c)) {
		oFile << c;
	}

	oFile.seekg(0);
	char c1;
	while (oFile.get(c1)) {
		std::cout << c1;
	}

	iFile.close();
	oFile.close();

	return 0;
}
