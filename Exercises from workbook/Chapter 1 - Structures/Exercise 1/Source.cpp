#include<iostream>
#include<cstring>

struct Product {
	char description[32];
	int partNum;
	double cost;
};

int main() {
	Product pr1 = { "screw-driver",456,5.50 };
	Product pr2 = { "hammer",324,8.20 };

	std::cout << "Product 1: " << pr1.description << ", " << pr1.partNum << ", " << pr1.cost << std::endl;
	std::cout << "Product 2: " << pr2.description << ", " << pr2.partNum << ", " << pr2.cost << std::endl;

	Product prs[10];

	for (size_t i = 0; i < 10; ++i) {
		strcpy_s(prs[i].description, "");
		prs[i].partNum = 0;
		prs[i].cost = 0;
	}

	std::cout << std::endl;

	Product prs2[5] = { {"screw-driver",456,5.50},
					 {"hammer",324,8.20},
					 {"socket",458,5.75},
					 {"piler",929,10.50},
					 {"hand-saw",536,7.45} };

	for (size_t i = 0; i < 5; ++i) {
		std::cout << "Product[" << i + 1 << "]: " << prs2[i].description << ", " << prs2[i].partNum << ", " << prs2[i].cost << std::endl;
	}

	return 0;
}
