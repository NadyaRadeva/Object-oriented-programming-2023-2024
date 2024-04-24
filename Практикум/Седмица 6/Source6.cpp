#include<iostream>
#include<fstream>

int main() {
 	std::fstream iFile1;
    	std::ifstream iFile2;

	iFile1.open("File.txt");
	if (!iFile1) {
		std::cerr << "File couldn't open!" << std::endl;
		return -1;
	}

	iFile2.open("File2.txt");
	if (!iFile2) {
		std::cerr << "File couldn't open!" << std::endl;
		return -1;
	}

	iFile1.seekp(0, std::ios::beg);
    	iFile1.seekp(0, std::ios::end);
    
	char c;
	while (iFile2.get(c)) {
               iFile1.put(c);
	}

   	 iFile1.seekg(0);

    	char c1;
   	while (iFile1.get(c1)) {
              std::cout << c1;
    	}

	iFile1.close();
	iFile2.close();

	return 0;
}
