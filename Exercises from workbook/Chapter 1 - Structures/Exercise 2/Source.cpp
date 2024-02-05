#include<iostream>

struct Rectangle {
	int length;
	int width;

	void printRectangle(Rectangle r) const {
		std::cout << "Length: " << r.length << ", " << "Width: " << r.width << std::endl;
	}

	void initRectangle(Rectangle& r) {
		do {
			std::cout << "Length: ";
			std::cin >> r.length;
			std::cout << "Width: ";
			std::cin >> r.width;
		} while (r.length <= 0 || r.width <= 0);
	}

	Rectangle initRectangle() {
		Rectangle r;
		do {
			std::cout << "Length: ";
			std::cin >> r.length;
			std::cout << "Width: ";
			std::cin >> r.width;
		} while (r.length <= 0 || r.width <= 0);
	}
};
