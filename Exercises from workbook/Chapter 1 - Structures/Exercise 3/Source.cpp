#include<iostream>

struct Triangle {
	double a, b, c;


};

void createTriangle(Triangle& t);

void createTriangle(Triangle& t) {
	bool isTriangle;

	do {
		std::cout << "Side A: ";
		std::cin >> t.a;
		std::cout << "Side B: ";
		std::cin >> t.b;
		std::cout << "Side C: ";
		std::cin >> t.c;

		isTriangle = t.a > 0 && t.b > 0 && t.c > 0 && (t.a + t.b > t.c) && (t.a + t.c > t.b) && (t.b + t.c > t.a);
	} while (!isTriangle);
}

void printTriangle(const Triangle& t) {
	std::cout << "Triangle( " << t.a << ", " << t.b << ", " << t.c << ")" << std::endl;
}

double perimeter(const Triangle& t) {
	return t.a + t.b + t.c;
}

double surface(const Triangle& t) {
	double p = perimeter(t) / 2;
	return p * (p - t.a) * (p - t.b) * (p - t.c);
}

int main() {
	Triangle t;
	createTriangle(t);
	printTriangle(t);
	std::cout << std::endl;

	std::cout << "Perimeter of the traingle: " << perimeter(t) << std::endl;
	std::cout << "Surface of the triangle: " << surface(t) << std::endl;

	return 0;
}
