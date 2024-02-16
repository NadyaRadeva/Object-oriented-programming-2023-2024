#ifndef _ANGLE_H
#define _ANGLE_H

class Angle {
private:
	double degree;

public:
	void setValue(double deg);
	double getSin() const;
	double getCos() const;
	double getTan() const;
};

#endif // !_ANGLE_H
