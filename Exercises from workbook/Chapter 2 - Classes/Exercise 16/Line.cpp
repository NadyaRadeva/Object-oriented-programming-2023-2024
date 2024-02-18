#include "Line.h"
#include "Point.h"
#include<cmath>
#include<iostream>

Line::Line(const Point& p1, const Point& p2) {
	this->p1 = p1;
	this->p2 = p2;
}

Point Line::point1() const {
	return p1;
}

Point Line::point2() const {
	return p2;
}

double Line::len() const {
	double xdist = p2.xcoord() - p1.xcoord();
	double ydist = p2.ycoord() - p1.ycoord();
	return sqrt(xdist * xdist + ydist * ydist);
}

double Line::slope() const {
	double xdist = p2.xcoord() - p1.xcoord();
	double ydist = p2.ycoord() - p1.ycoord();
	if (fabs(xdist) < 1E-14) {
		std::cout << "The slope coefficient is not defined!" << std::endl;
		return 0;
	}
	else {
		return ydist / xdist;
	}
}

Point Line::intersection(const Line& line1) const {
	double a1 = p1.ycoord() - p2.ycoord();
	double b1 = p2.xcoord() - p1.xcoord();
	double c1 = p1.xcoord() * p2.ycoord() - p2.xcoord() * p1.ycoord();
	double a2 = line1.p1.ycoord() - line1.p2.ycoord();
	double b2 = line1.p2.xcoord() - line1.p1.xcoord();
	double c2 = line1.p1.xcoord() * line1.p2.ycoord() - line1.p2.xcoord() * line1.p1.ycoord();
	if (fabs(b1 * c2 - a2 * b1) < 1E-14) {
		if (fabs(b1 * c2 - b2 * c1) < 1E - 14) {
			std::cout << "The lines align!" << std::endl;
			return p1;
		}
		else {
			std::cout << "The lines are parallel!" << std::endl;
			return p1;
		}
	}
	else {
		double x1 = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
		double y1 = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
		return Point(x1, y1);
	}
}
