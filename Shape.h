#pragma once
#include"MyString.h"
class Shape {
	double x;
	double y;
	MyString fill;
protected:
	enum class Type {
		RECTANGLE,
		CIRCLE,
		LINE,
		UNKNOWN
	}type;
public:
	Shape();
	Shape(double, double, const MyString&);
	virtual void print() const;
	virtual double calculateArea() = 0;
	virtual double calculateParameter() = 0;
	virtual Shape* clone() const = 0;
	virtual void translate(double, double)=0;
	double getX() const;
	double getY() const;
	const MyString& getFill() const;
	void setX(double);
	void setY(double);
	void setFill(const MyString&);
	virtual bool PointIn(double, double) = 0;
	virtual const MyString& saveShape()  = 0;
	virtual bool WithinCircle(double, double, double)=0;
	virtual bool WithinRectangle(double, double, double, double)=0;


};