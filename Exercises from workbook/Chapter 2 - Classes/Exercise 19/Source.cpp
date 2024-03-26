#include<iostream>
#include"Point3.h"

int main() {
	Point3 p1, p2(1, 2, 3);

	std::cout << "P1 = (" << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")" << std::endl;
	std::cout << "P2 = (" << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << ")" << std::endl;

	Point3 p3 = p2;

	std::cout << "P3 = (" << p3.getX() << ", " << p3.getY() << ", " << p3.getZ() << ")" << std::endl;

	p3.setX(5);
	p3.setY(6);
	p3.setZ(7);

	std::cout << "P3 = (" << p3.getX() << ", " << p3.getY() << ", " << p3.getZ() << ")" << std::endl;

	return 0;
}
