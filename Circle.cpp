#include "Circle.h"
#include <iostream>
#include<cmath>
#pragma warning(disable : 4996)


Circle::Circle():Shape()
{
	r = 0;
	type = Type::CIRCLE;
}

Circle::Circle(double x, double y, const MyString& fill, double r):Shape(x,y,fill)
{
	type = Type::CIRCLE;
	if (r >=0)this->r = r;
	else throw "No such value.";
}

Circle::Circle(const Circle& other)
{
	this->r = other.r;
	this->setX(other.getX());
	this->setY(other.getY());
	this->setFill(other.getFill());
}

void Circle::print() const
{
	std::cout << "circle ";
	Shape::print();
	std::cout <<  Shape::getFill().c_str() << std::endl;
}

double Circle::calculateArea()
{
	return 3.14159265359*r*r;
}

double Circle::calculateParameter()
{
	return 2* 3.14159265359*r;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

bool Circle::PointIn(double x, double y) 
{
	if ((x - Shape::getX()) * (x - Shape::getX()) + (y - Shape::getY()) * (y - Shape::getY()) <= r * r)
		return true;
	else
		return false;
}

void Circle::translate(double vertical, double horizontal)
{
	Shape::setX(Shape::getX() + horizontal);
	Shape::setY(Shape::getY() + vertical);
}

bool Circle::WithinCircle(double x, double y, double r)
{
	double distSq= sqrt(((x - Shape::getX())* (x - Shape::getX()))+ ((y - Shape::getY())* (y - Shape::getY())));
	if (distSq + this->r <= r) return true;
	else return false;
}

bool Circle::WithinRectangle(double x, double y, double width, double height)
{
	double bottom_right_x = x + width;
	double bottom_right_y = y - height;
	if (Shape::getX() + r > bottom_right_x) return false;
	if (Shape::getX() - r < x) return false;
	if (Shape::getY() + r > bottom_right_y) return false;
	if (Shape::getY() - r < y) return false;
	else return true;
}

const MyString& Circle::saveShape() 
{
	
	char dbl[20];
	MyString tag;
	tag = "<circle cx=";
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", Shape::getX());
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" cy=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", Shape::getY());
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" r=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", r);
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" fill=");
	tag.concatOneChar(34);
	tag.concat(Shape::getFill().c_str());
	tag.concatOneChar(34);
	tag.concat(" />");
	std::cout << tag.c_str();
	backTag = tag;
	return backTag;
	
}



