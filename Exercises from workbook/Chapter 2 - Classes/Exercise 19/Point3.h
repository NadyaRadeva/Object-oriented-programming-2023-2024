#ifndef _POINT3_

class Point3 {
private:
	int x;
	int y;
	int z;

public:
	Point3();
	Point3(int _x, int _y, int _z);
	Point3(Point3 const& other);
	Point3 operator=(Point3 const& other);

	int getX() const;
	int getY() const;
	int getZ() const;

	void setX(int _x);
	void setY(int _y);
	void setZ(int _z);
};

#endif // !_POINT3_
