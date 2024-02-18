#ifndef _DIFFER_H

const int MAX = 20;

class Differ {
private:
	int n;
	int a[MAX];

public:
	Differ(int m);
	bool diff() const;
};

#endif // !_DIFFER_H
