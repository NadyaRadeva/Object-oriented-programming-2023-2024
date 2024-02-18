#include "Differ.h"
#include<iostream>

Differ::Differ(int m) {
	this->n = m;
	for (size_t i = 0; i < m; ++i) {
		std::cin >> a[i];
	}
}

bool Differ::diff() const {
	if (this->n == 1) {
		return true;
	}

	int i = -1;

	bool b;
	int j;

	do {
		i++;
		j = i;
		do {
			j++;
			b = a[i] != a[j];
		} while (b && j < n - 1);
	} while (b && i < n - 2);

	return b;
}
