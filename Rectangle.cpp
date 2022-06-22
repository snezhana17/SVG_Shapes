
#include "Rectangle.h"
#include "Shape.h"
#include "Container.h"
#include <iostream>
#include <cmath>
#pragma warning(disable : 4996)

Rectangle::Rectangle():Shape()
{
	width = 0;
	height = 0;
	type = Type::RECTANGLE;
}

Rectangle::Rectangle(double x, double y, const MyString& fill, double width, double height):Shape(x,y,fill)
{
	type = Type::RECTANGLE;
	if (width >= 0)this->width = width;
	else throw "No such value.";
	if(height>=0)this->height = height;
	else throw "No such value.";
}

void Rectangle::print() const
{
	std::cout << "rectangle ";
	Shape::print();
	std::cout << width<<" " << height<<" " << Shape::getFill().c_str() << std::endl;
}

double Rectangle::calculateArea()
{
	return width * height;
}

double Rectangle::calculateParameter()
{
	return 2 * (width + height);
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

bool Rectangle::PointIn(double x1, double y1) 
{
	double bottom_right_x = Shape::getX() + width;
	double bottom_right_y = Shape::getY() - height;
	if (x1 >= Shape::getX() && x1 <= bottom_right_x && y1 <= Shape::getY() && y1 >= bottom_right_y)
		return true;
	
	return false;
}

void Rectangle::translate(double vertical, double horizontal)
{
		Shape::setX(Shape::getX()+ horizontal);
		Shape::setY(Shape::getY() + vertical);
}

bool Rectangle::WithinCircle(double x, double y, double r)
{
	double bottom_right_x = Shape::getX() + width;
	double bottom_right_y = Shape::getY() - height;
	 double first=sqrt((x - Shape::getX()) * (x - Shape::getX()) + (y - Shape::getY()) * (y - Shape::getY()));
	 double second= sqrt((x - bottom_right_x) * (x - bottom_right_x) + (y - bottom_right_y) * (y - bottom_right_y));
	 if (first <= r && second <= r) return true;
	else return false;
}

bool Rectangle::WithinRectangle(double x1, double y1, double width1, double height1)
{
	double bottom_right_x = Shape::getX() + width;
	double bottom_right_y = Shape::getY() - height;
	double bottom_right_x1 = x1 + width;
	double bottom_right_y1 = y1 - height;
	if (y1 >= Shape::getY() && x1 <= Shape::getX() && bottom_right_y1 <= bottom_right_y && bottom_right_x1 >= bottom_right_x)
		return true;
	else return false;
}

const MyString& Rectangle::saveShape() 
{
	char dbl[20];
	MyString tag;

	tag = ("<rect x1=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", Shape::getX());
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" y1=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", Shape::getY());
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" width=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", width);
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" height=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", height);
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


