#include<iostream>

struct Points {
	double x;
	double y;
};

void createPoint(Points& p) {
	std::cout << "Enter the x-coordinate: ";
	std::cin >> p.x;
	std::cout << "Enter the y-coordinate: ";
	std::cin >> p.y;
}

void printPoints(const Points& p) {
	std::cout << "Point(" << p.x << ", " << p.y << ")" << std::endl;
}

double calcSegment(const Points& p1, const Points& p2) {
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

struct Triangle {
	Points A, B, C;
};

void createTriangle(Triangle& t) {
	std::cout << "Enter the coordiantes of point A: " << std::endl;
	createPoint(t.A);
	std::cout << "Enter coordiantes of point B: " << std::endl;
	createPoint(t.B);
	std::cout << "Enter coordinates of point C: " << std::endl;
	createPoint(t.C);
}

void printTriangle(const Triangle& t) {
	std::cout << "Triangle(";
	printPoints(t.A);
	std::cout << ", ";
	printPoints(t.B);
	std::cout << ", ";
	printPoints(t.C);
	std::cout << ")" << std::endl;
}

double findPerimeter(const Triangle& t) {
	double c = calcSegment(t.A, t.B), a = calcSegment(t.B, t.C), b = calcSegment(t.C, t.A);
	return a + b + c;
}

double findSurface(const Triangle& t) {
	double c = calcSegment(t.A, t.B), a = calcSegment(t.B, t.C), b = calcSegment(t.C, t.A);
	double p = (a + b + c) / 2;
	return p * (p - a) * (p - b) * (p - c);
}

int main() {
	Triangle t;
	createTriangle(t);
	printTriangle(t);

	std::cout << "Perimeter of the triangle: " << findPerimeter(t) << std::endl;
	std::cout << "Surface of the triangle: " << findSurface(t) << std::endl;

	return 0;
}
