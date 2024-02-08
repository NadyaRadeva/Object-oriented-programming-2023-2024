#include<iostream>
#include<iomanip>

int k;

const unsigned int MAX_SURNAME_SIZE = 12;
const unsigned int MAX_SUBJECTS = 10;
const unsigned int MAX_SIZE2 = 25;


struct Student {
	int facultyNumber;
	char surname[MAX_SURNAME_SIZE];
	double* subjects = new double[k];
};

void createStudent(Student& st){
	do {
		std::cout << "Enter the faculty number of the student: ";
		std::cin >> st.facultyNumber;

	} while (st.facultyNumber <= 0 || st.facultyNumber > 99999);

	std::cout << "Enter surname: ";
	std::cin >> st.surname;

	for (size_t i = 0; i < k; ++i) {
		std::cout << "Grade for subject " << i + 1 << ": ";
		std::cin >> st.subjects[i];
	}
}

void showStudent(const Student& st) {
	std::cout << std::setw(5) << st.facultyNumber << std::setw(MAX_SURNAME_SIZE + 2) << st.surname;

	for (size_t i = 0; i < k; ++i) {
		std::cout << std::setw(5) << st.subjects[i];
	}
}

double result(const Student& st) {
	double u = 0;
	for (size_t i = 0; i < k; ++i) {
		u += st.subjects[i];
	}
	u /= k;
	return u;
}

void createGroup(unsigned int n, Student* st) {
	for (size_t i = 0; i < n; ++i) {
		std::cout << "Data for student " << i + 1 << ": " << std::endl;
		createStudent(st[i]);
	}
}

void printTable() {
	std::cout << std::setiosflags(std::ios::fixed | std::ios::showpoint) << std::setprecision(2);
	int i;

	for (size_t i = 0; i < 5 + MAX_SURNAME_SIZE + 2 + 5 * (k + 1) + 1; ++i) {
		std::cout << "=";
	}

	std::cout << std::endl;
	
	std::cout << std::setw(5) << "Faculty number" << std::setw(MAX_SURNAME_SIZE + 2) << "Surname";
	for (size_t i = 0; i < k; ++i) {
		std::cout << std::setw(4) << "D-" << i + 1;
	}

	std::cout << std::setw(6) << "Average grade" << std::endl;
	for (size_t i = 0; i < 5 + MAX_SURNAME_SIZE + 2 + 5 * ( k + 1) + 1; ++i) {
		std::cout << "=";
	}

	std::cout << std::endl;
}

void printGroup(int n, Student* st) {
	printTable();

	int i, j;

	double temp[MAX_SUBJECTS] = { 0, };
	for (j = 0; j < k; ++j) {
		for (i = 0; i < n; ++i) {
			temp[j] = temp[j] + st[i].subjects[j];
		}
		temp[j] = temp[j] / n;
	}

	double sum = 0;
	for (i = 0; i < n; ++i) {
		showStudent(st[i]);
		double res = result(st[i]);
		sum += res;
		std::cout << std::setw(6) << res << std::endl;
	}

	for (i = 0; i < 5 + MAX_SURNAME_SIZE + 2 + 5 * (k + 1) + 1; ++i) {
		std::cout << "=";
	}

	std::cout << std::endl << std::setw(5 + MAX_SURNAME_SIZE + 2 + 5) << temp[0];

	for (j = 0; j < k; ++j) {
		std::cout << std::setw(5) << temp[j];
	}

	std::cout << std::setw(6) << sum / n << std::endl;
}

void sortGroup(int n, Student** st) {
	for (int i = 0; i < n - 1; ++i) {
		int k = i;
		double max = result(*st[k]);
		for (size_t j = i + 1; j < n; ++j) {
			double d = result(*st[j]);
			if (d > max) {
				max = d;
				k = j;
			}
		}

		Student* x;
		x = st[i];
		st[i] = st[k];
		st[k] = x;
	}
}

void printSort(int n, Student** st) {
	printTable();

	for (size_t i = 0; i < n; ++i) {
		showStudent(*st[i]);
		double res = result(*st[i]);
		std::cout << std::setw(6) << res << std::endl;
	}
}

int main() {
	do {
		std::cout << "Enter a value between 1 and " << MAX_SUBJECTS << ": ";
		std::cin >> k;
	} while (k<1 || k>MAX_SUBJECTS);

	int n;
	do {
		std::cout << "Enter value for n between 1 and " << MAX_SIZE2 << ": ";
		std::cin >> n;
	} while (n<1 || n>MAX_SIZE2);

	Student st[MAX_SIZE2];
	Student* ps[MAX_SIZE2];

	createGroup(n, st);

	printGroup(n, st);

	for (size_t i = 0; i < n; ++i) {
		ps[i] = &st[i];
	}

	sortGroup(n, ps);

	std::cout << std::endl;

	printSort(n, ps);

	return 0;
}
