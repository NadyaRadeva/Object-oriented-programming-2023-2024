#include "Point.h"
#include "Line.h"
#include<iostream>

int main() {
	Point p1(0, 0);
	Point p2(8, 0);
	Point p3(8, 4);
	Point p4(0, 4);

	Line line1(p1, p3);
	Line line2(p2, p4);

	std::cout << "The length of the diagonal of the rectangle is: " << line1.len() << std::endl;
	std::cout << "Angle coefficients: " << line1.slope() << ", " << line2.slope() << std::endl;

	Point intersect = line1.intersection(line2);
	std::cout << "The coordinates of the intersection of the two lines is: " << intersect.xcoord() << ", " << intersect.ycoord() << std::endl;

	return 0;
}
