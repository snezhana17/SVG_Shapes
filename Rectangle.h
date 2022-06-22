#pragma once
#include "Container.h"
class Rectangle: public Shape {
	double width=0;
	double height=0;
	MyString backTag;
public:
	Rectangle();
	Rectangle(double, double, const MyString&, double, double);
	virtual void print() const override;
	virtual double calculateArea() override;
	virtual double calculateParameter() override;
	virtual Shape* clone() const override;
	virtual bool PointIn(double, double) override;
	virtual void translate(double, double) override;
	virtual bool WithinCircle(double, double, double) override;
	virtual bool WithinRectangle(double, double, double, double) override;
	virtual const MyString& saveShape()  override;
	

};