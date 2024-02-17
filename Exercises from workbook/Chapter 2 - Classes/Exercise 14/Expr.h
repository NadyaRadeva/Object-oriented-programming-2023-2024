#ifndef _EXPR_H

class Expr {
private:
	int n;
	double x;

public:
	Expr(int _n, double _x);
	double Ex1() const;
	double Ex2() const;
	double Ex3() const;
};

#endif // !_EXPR_H
