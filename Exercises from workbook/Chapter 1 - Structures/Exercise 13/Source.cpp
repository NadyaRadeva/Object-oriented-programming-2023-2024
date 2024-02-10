#include<iostream>

const unsigned int MAX_SIZE = 20;

struct Triangle {
private:
	double a;
	double b;
	double c;

public:
	void createTriangle(double x, double y, double z) {
		a = x;
		b = y;
		c = z;
	}

	void printTriangle() const {
		std::cout << "Triangle(" << a << ", " << b << ", " << c << ")";
	}

	double getA() const {
		return a;
	}

	double getB() const {
		return b;
	}

	double getC() const {
		return c;
	}

	double findPerimeter() const {
		return a + b + c;
	}

	double findSurface() const {
		double p = findPerimeter() / 2;
		return p * (p - a) * (p - b) * (p - c);
	}

	Triangle kTriangle(int k) {
		Triangle t;
		createTriangle(k * a, k * b, k * c);
		return t;
	}

	Triangle minSurface(int n, Triangle t[]) {
		int k = 0;
		double min = t[0].findSurface();
		for (size_t i = 0; i < n; ++i) {
			if (t[i].findSurface() < min) {
				min = t[i].findSurface();
				k = i;
			}
		}

		return t[k];
	}

	void newSequence(int n, Triangle* t, Triangle* newT) {
		for (size_t i = 0; i < n; ++i) {
			newT[i] = t[i].kTriangle(i + 1);
		}
	}
};
