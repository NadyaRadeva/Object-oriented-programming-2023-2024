#include<iostream>
#include<cstring>

const unsigned int MAX_ORIGINAL_LEN = 1000000;
const unsigned int MAX_LEN = 11;

int main() {
	char* originalStr = new char[MAX_ORIGINAL_LEN];
	std::cin.getline(originalStr, MAX_ORIGINAL_LEN);

	char delimiter;
	std::cin >> delimiter;
	if (!std::cin) {
		throw std::runtime_error("Error! Wrong input!");
		return -1;
	}

	char copyStr[MAX_LEN];

	size_t i = 0;
	for (; i < MAX_ORIGINAL_LEN; ++i) {
		if (originalStr[i] != delimiter && i < MAX_LEN - 1) {
			copyStr[i] = originalStr[i];
		}
		else {
			copyStr[i] = '\0';
			break;
		}
	}

	char fragment1[MAX_LEN], fragment2[MAX_LEN], fragment3[MAX_LEN];

	size_t index1 = 0;
	for (size_t j = 0; j < MAX_ORIGINAL_LEN; ++j) {
		if (originalStr[j] != delimiter && index1 < MAX_LEN - 1) {
			fragment1[index1++] = originalStr[j];
		}
		else {
			fragment1[index1] = '\0';
			break;
		}
	}

	size_t index2 = 0;
	for (size_t j = i + 1; j < MAX_ORIGINAL_LEN; ++j) {
		if (originalStr[j] != delimiter && index2 < MAX_LEN - 1) {
			fragment2[index2++] = originalStr[j];
		}
		else {
			fragment2[index2] = '\0';
			break;
		}
	}

	size_t index3 = 0;
	for (size_t j = i + index2 + 2; j < MAX_ORIGINAL_LEN; ++j) {
		if (originalStr[j] != delimiter && index3 < MAX_LEN - 1) {
			fragment3[index3++] = originalStr[j];
		}
		else {
			fragment3[index3] = '\0';
			break;
		}
	}

	std::cout << "Original string: " << originalStr << std::endl;
	std::cout << "Copy string: " << copyStr << std::endl;
	std::cout << "Fragment 1: " << fragment1 << std::endl;
	std::cout << "Fragment 2: " << fragment2 << std::endl;
	std::cout << "Fragment 3: " << fragment3 << std::endl;

	delete[] originalStr;

	return 0;
}
