#include "Line.h"
#include <iostream>
#include <cmath>
#pragma warning(disable : 4996)

Line::Line():Shape()
{
	x2 = 0;
	y2 = 0;
	type = Type::LINE;
}

Line::Line(double x, double y, const MyString& fill, double x2, double y2):Shape(x,y,fill)
{
	type = Type::LINE;
	this->x2 = x2;
	this->y2 = y2;
}

void Line::print() const
{
	std::cout << "line";
	Shape::print();
	std::cout << x2 << " " << y2 << " " << Shape::getFill().c_str() << std::endl;

}

double Line::calculateArea()
{
	return calculateParameter();
}

double Line::calculateParameter()
{
	return sqrt((x2-Shape::getX())*(x2 - Shape::getX())+ (y2 - Shape::getY()) * (y2 - Shape::getY()));
}

Shape* Line::clone() const
{
	return new Line(*this);
}

bool Line::PointIn(double x, double y) 
{
	if (sqrt((x - Shape::getX()) * (x - Shape::getX()) + (y - Shape::getY()) * (y - Shape::getY())) + sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)) == calculateParameter()) {
		return true;
	}

	else {
		return false;
	}
}

void Line::translate(double vertical , double horizontal)
{
	Shape::setX(Shape::getX() + horizontal);
	Shape::setY(Shape::getY() + vertical);
	x2 = x2 + horizontal;
	y2 = y2 + vertical;
}

bool Line::WithinCircle(double x, double y, double r)
{
	double first = sqrt((x - Shape::getX()) * (x - Shape::getX()) + (y - Shape::getY()) * (y - Shape::getY()));
	double second = sqrt((x - this->x2) * (x - this->x2) + (y - this->y2) * (y - this->y2));
	if (first <= r && second <= r) return true;
	else return false;
}

bool Line::WithinRectangle(double x, double y, double width, double height)
{
	int tempTrue = 0;
	double bottom_right_x = x + width;
	double bottom_right_y = y - height;
	if (x >= Shape::getX() && Shape::getX() <= bottom_right_x && y >= Shape::getY() && Shape::getY() >= bottom_right_y) tempTrue++;
	if (x >= this->x2 && this->x2 <= bottom_right_x && y >= this->y2 && this->y2 >= bottom_right_y) tempTrue++;
	if (tempTrue == 2) return true;
	else return false;
}

const MyString& Line::saveShape() 
{
	char dbl[20];
	MyString tag;
tag = ("<line x1=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", Shape::getX());
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" y1=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", Shape::getY());
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" x2=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", x2);
	tag.concat(dbl);
	tag.concatOneChar(34);

	tag.concat(" y2=");
	tag.concatOneChar(34);
	sprintf(dbl, "%lf", y2);
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
