#ifndef _VECTOR_H

class Vector {
private:
	int* vec;
	unsigned int sizeVec;

	void copy(Vector const& other);
	void erase();
	void resizeVec();

public:
	Vector();
	Vector(int* _vec, unsigned int _sizeVec);
	Vector(Vector const& other);
	Vector operator=(Vector const& other);
	Vector(Vector&& other);
	Vector& operator=(Vector&& other);
	~Vector();

	unsigned int getSize() const;
	void setSize(unsigned int _size);

	void pushBack(int value);
	void popBack();
	int at(unsigned int index);
	void insertAt(unsigned int index, int value);
	void deleteAt(unsigned int index);
	void sort();
	void concat(Vector const& other);
	Vector* slice(unsigned int start, unsigned int end);
	void reverse();
};

#endif // !_VECTOR_H
