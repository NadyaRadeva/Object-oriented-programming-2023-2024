#include<iostream>
#include<cmath>

const double PI = 3.14159265;

struct polar {
	double mag;
	double ang;
};

struct rect {
	double x;
	double y;
};

polar rectToPolar(const rect& r) {
	polar p;
	p.mag = sqrt(r.x * r.x + r.y * r.y);
	p.ang = atan2(r.y, r.x);
	return p;
}

rect polarToRect(const polar& p) {
	const double DEG_TO_RAD = PI / 180;
	rect r;
	r.x = p.mag * cos(p.ang * DEG_TO_RAD);
	r.y = p.mag * sin(p.ang * DEG_TO_RAD);
	return r;
}

void showPolar(const polar& p) {
	const double RAD_TO_DEG = 180 / PI;
	std::cout << "Radius = " << p.mag << ", angle = " << p.ang * RAD_TO_DEG << " degrees." << std::endl;
}

void showRect(const rect& r) {
	std::cout << "Abscissa  = " << r.x << ", ordinate = " << r.y << std::endl;
}

int main() {
	rect r;
	polar p;

	std::cout << "Choose how to enter your coordinates: " << std::endl;
	std::cout << "r - for rectangular  and p - for polar" << std::endl;
	char ch;
	std::cin >> ch;

	switch (ch) {
	case 'r': std::cout << "Enter rectangular coordinates x and y: ";
		while (std::cin >> r.x >> r.y) {
			p = rectToPolar(r);
			showPolar(p);
			std::cout << "Next rectangular coordinates, for end enter word \'end\'." << std::endl;
		}
		break;
	case 'p':std::cout << "Enter polar coordinates mag and ang: ";
		while (std::cin >> p.mag >> p.ang) {
			r = polarToRect(p);
			showRect(r);
			std::cout << "Next polar coordinates, for end enter word \'end\'." << std::endl;
		}
		break;
	}

	return 0;
}
