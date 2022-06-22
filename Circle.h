#pragma once
#include "Shape.h"
class Circle : public Shape {
	double r;
	MyString backTag;
public:
	Circle();
	Circle(double, double, const MyString&, double);
	Circle(const Circle&);
	virtual void print() const override;
	virtual double calculateArea() override;
	virtual double calculateParameter() override;
	virtual Shape* clone() const override;
	virtual bool PointIn(double, double)  override;
	virtual void translate(double, double) override;
	virtual bool WithinCircle(double,double,double) override;
	virtual bool WithinRectangle(double, double, double, double) override;
	virtual const MyString& saveShape() override;

};