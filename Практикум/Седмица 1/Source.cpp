#include<iostream>
#include<cmath>
#include<iomanip>

struct Point {
	double xcoordinate;
	double ycoordinate;

	void inputPoint() {
		std::cout << "Enter the x-coordinate of the point: ";
		std::cin >> xcoordinate;
		if (!std::cin) {
			throw std::runtime_error("Error! Invalid input!");
		}

		std::cout << "Enter the y-coorndate of the point: ";
		std::cin >> ycoordinate;
		if (!std::cin) {
			throw std::runtime_error("Error! Invalid input!");
		}
	}
};

double distanceFromCenter(Point p) {
	return sqrt((0 - p.xcoordinate) * (0 - p.xcoordinate) + (0 - p.ycoordinate) * (0 - p.ycoordinate));
}

double distanceBetweenTwoPoints(Point p1, Point p2) {
	return sqrt((p2.xcoordinate - p1.xcoordinate) * (p2.xcoordinate - p1.xcoordinate) + (p2.ycoordinate - p1.ycoordinate) * (p2.ycoordinate - p1.ycoordinate));
}

struct Rectangle {
	Point p1;
	Point p2;

	void inputRectangle() {
		std::cout << "Enter the coordinates of point 1:" << std::endl;
		p1.inputPoint();

		std::cout << "Enter the coordinates of point 2:" << std::endl;
		p2.inputPoint();
	}
};

bool isPointInRectangle(Point* p, Rectangle r) {
	double minX, maxX, minY, maxY;

	if (r.p1.xcoordinate < r.p2.xcoordinate) {
    		minX = r.p1.xcoordinate;
   		maxX = r.p2.xcoordinate;
	} 
	else {
    		minX = r.p2.xcoordinate;
    		maxX = r.p1.xcoordinate;
	}

	if (r.p1.ycoordinate < r.p2.ycoordinate) {
    		minY = r.p1.ycoordinate;
    		maxY = r.p2.ycoordinate;
	} 
	
	else {
    		minY = r.p2.ycoordinate;
    		maxY = r.p1.ycoordinate;
	}

	return (p->xcoordinate >= minX && p->xcoordinate <= maxX && p->ycoordinate >= minY && p->ycoordinate <= maxY);
}

bool doTwoRectanglesOverlap(Rectangle r1, Rectangle r2) {
 	return !(r1.p1.xcoordinate > r2.p2.xcoordinate || r1.p2.xcoordinate < r2.p1.xcoordinate || r1.p1.ycoordinate > r2.p2.ycoordinate || r1.p2.ycoordinate < r2.p1.ycoordinate);
}

void printRectangle() {
	double side1;
	double side2;

	side1 = abs(sqrt((p1.xcoordinate - p1.xcoordinate) * (p1.xcoordinate - p1.xcoordinate) + (0 - p1.ycoordinate) * (0 - p1.ycoordinate)) - sqrt((p2.xcoordinate - p2.xcoordinate) * (p2.xcoordinate - p2.xcoordinate) + (0 - p2.ycoordinate) * (0 - p2.ycoordinate)));
	side2 = abs(sqrt((0 - p1.xcoordinate) * (0 - p1.xcoordinate) + (p1.ycoordinate - p1.ycoordinate) * (p1.ycoordinate - p1.ycoordinate)) + sqrt((0 - p2.xcoordinate) * (0 - p2.xcoordinate) + (p2.ycoordinate - p2.ycoordinate) * (p2.ycoordinate - p2.ycoordinate)));

	for (size_t i = 0; i<int(side1); ++i) {
		for (size_t j = 0; j<int(side2); ++j) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	Point p1;
	Point p2;

	p1.inputPoint();
	p2.inputPoint();

	std::cout << "The distance between (0,0) and p1 is: " << distanceFromCenter(p1) << std::endl;
	std::cout << "The distance between p1 and p2 is: " << distanceBetweenTwoPoints(p1, p2) << std::endl;

	Rectangle rec1;
	Rectangle rec2;

	rec1.inputRectangle();
	rec1.printRectangle();

	rec2.inputRectangle();

	std::cout << "Rectangle 1 contains p1? - " << std::boolalpha << isPointInRectangle(&p1, rec1) << std::endl;
	std::cout << "Rectangle 1 and rectangle 2 intersect? - " << std::boolalpha << doTwoRectanglesOverlap(rec1, rec2) << std::endl;

	return 0;
}
