#ifndef _LINE_H
#include "Point.h"

class Line {
private:
	Point p1, p2;

public:
	Line(const Point& p1, const Point& p2);
	Point point1() const;
	Point point2() const;
	double len() const;
	double slope() const;
	Point intersection(const Line& line1) const;
};

#endif // !_LINE_H
