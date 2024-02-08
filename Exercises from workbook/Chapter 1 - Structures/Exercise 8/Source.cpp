#include<iostream>

struct Point {
	double x;
	double y;
};

void createPoint(Point& p) {
	std::cout << "Enter x-coordinate: ";
	std::cin >> p.x;
	std::cout << "Enter y-coordinate: ";
	std::cin >> p.y;
}

void showPoint(const Point& p) {
	std::cout << "Point(" << p.x << ", " << p.y << ")" << std::endl;
}

double findDistBetweenPoints(const Point& p1, const Point& p2) {
	return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

void readPoints(unsigned int n, Point* p) {
	for (size_t i = 0; i < n; ++i) {
		createPoint(p[i]);
	}
}

void showPoints(unsigned int n, Point* p) {
	for (size_t i = 0; i < n; ++i) {
		showPoint(p[i]);
	}
}

double maxDistance(unsigned int n, Point* p) {
	double maxDist = 0;

	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = i + 1; j < n; ++j) {
			double tempDist = findDistBetweenPoints(p[i], p[j]);
			if (maxDist < tempDist) {
				maxDist = tempDist;
			}
		}
	}

	return maxDist;
}

void sortPoints(int n, Point* p) {
	for (size_t i = 0; i < n - 1; ++i) {
		int k = i;
		Point min = p[i];
		for (size_t j = i + 1; j < n; ++j) {
			if (p[i].x < min.x || p[j].x == min.x && p[j].y < min.y) {
				min = p[j];
				k = j;
			}
			p[k] = p[i];
			p[i] = min;
		}
	}
}

int main() {
	std::cout << "Enter the number of your points: ";
	unsigned int n;
	std::cin >> n;
	if (!std::cin || n < 2 || n>100) {
		throw std::runtime_error("Error! Invalid input!");
		return 1;
	}

	Point* p = new Point[n];

	readPoints(n, p);

	std::cout << std::endl;

	showPoints(n, p);

	sortPoints(n, p);

	std::cout << std::endl;

	std::cout << "The max distance between your points is: " << maxDistance(n, p) << std::endl;

	delete[] p;

	return 0;
}
