#include "Shape.h"
#include <iostream>

Shape::Shape()
{
	x = 0;
	y = 0;
	fill =  MyString();
}

Shape::Shape(double x, double y, const MyString& fill)
{
	this->x = x;
	this->y = y;
	this->fill = fill;
}

void Shape::print() const
{
	std::cout <<" "<< x << " " << y << " ";
}


double Shape::getX() const
{
	return x;
}

double Shape::getY() const
{
	return y;
}

const MyString& Shape::getFill() const
{
	return fill;
}

void Shape::setX(double x)
{
	this->x = x;
}

void Shape::setY(double y)
{
	this->y = y;
}

void Shape::setFill(const MyString& fill)
{
	this->fill = fill;
}


