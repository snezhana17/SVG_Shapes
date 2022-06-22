#pragma once
#include "WorkWithFile.h"
#include "Shape.h"
class Container {
	Shape** shapes;
	size_t capacity;
	size_t size;
	MyString buffer;
	MyString fileName;
	void free();
	void copy(const Container&);
	void resize();
	

public:
	Container();
	Container(const Container&);
	Container& operator=(const Container&);
	~Container();
	void addShapeR(const Shape&);
	void addShapeL(const Shape&);
	void addShapeC(const Shape&);
	bool deleteShape(size_t);
	void printAll() const;
	void printAreas() const;
	void printParameters() const;
	void PointInn(double, double) const;
	void addAllShapes();
	void setBuffer(const MyString&);
	double CharToDouble(const MyString&);
	void setFileName(const MyString&);
	void saveALL();
	void WithinR(double, double, double, double) const;
	void WithinC(double, double, double) const;
	void translateALL(double, double) const;
	void translateParticular(double, double, size_t) const;
};