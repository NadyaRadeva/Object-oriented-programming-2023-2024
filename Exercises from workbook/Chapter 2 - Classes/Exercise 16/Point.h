#ifndef _POINT_H

class Point {
private:
	double x;
	double y;

public:
	Point(double _x, double _y);
	double xcoord() const;
	double ycoord() const;
};

#endif // !_POINT_H
