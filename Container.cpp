#include "Container.h"
#include "Rectangle.h"
#include "Circle.h"
#include"Line.h"
#include <iostream>
#include <fstream>


void Container::free()
{
	for (size_t i = 0; i < size; i++) delete shapes[i];
	delete[] shapes;
}

void Container::copy(const Container& other)
{
	capacity = other.capacity;
	size = other.size;
	shapes = new Shape * [capacity];
	for (size_t i = 0; i < size; i++) {
		shapes[i] = other.shapes[i]->clone();
	}
}

void Container::resize()
{
	Shape** temp = new Shape * [capacity *= 2];
	for (size_t i = 0; i < size; i++) {
		temp[i] = shapes[i];
	}
	delete[] shapes;
	shapes = temp;
	temp = nullptr;
}

Container::Container()
{
	capacity = 2;
	size = 0;
	shapes = new Shape * [capacity];
}

Container::Container(const Container& other)
{
	copy(other);
}

Container& Container::operator=(const Container& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

Container::~Container()
{
	free();
}

void Container::addShapeR(const Shape& other)
{
	if (size >= capacity) resize();
	size++;
	shapes[size - 1] = other.clone();
}

void Container::addShapeL(const Shape& other)
{
	if (size >= capacity) resize();
	size++;
	shapes[size - 1] = other.clone();
}

void Container::addShapeC(const Shape& other)
{
	if (size >= capacity) resize();
	size++;
	shapes[size - 1] = other.clone();
}


bool Container::deleteShape(size_t index)
{
	if (index >= size) return false;
	Shape* temp = shapes[index];
	shapes[index] = shapes[size - 1];
	shapes[size - 1] = temp;
	delete shapes[size - 1];
	size--;
	return true;
}

void Container::printAll() const
{
	for (size_t i = 0; i < size; i++) {
		std::cout << i + 1 << ". ";
			shapes[i]->print();
			std::cout << std::endl;
	}
}

void Container::printAreas() const
{
	
	for (size_t i = 0; i < size; i++) {
		std::cout << i + 1 << ". ";
		shapes[i]->print();
		std::cout << "Area: " << shapes[i]->calculateArea() << std::endl;

	}
}

void Container::printParameters() const
{
	for (size_t i = 0; i < size; i++) {
		std::cout << i + 1 << ". ";
		shapes[i]->print();
		std::cout << "Parameter: " << shapes[i]->calculateParameter() << std::endl;

	}
}

void Container::PointInn(double x, double y) const
{
	std::cout << "Shapes that contain the point :" << std::endl;
	for (size_t i = 0; i < size; i++) {
		if (shapes[i]->PointIn(x, y) == true) {
			shapes[i]->print();
		}
	}
}

void Container::addAllShapes()
{
	size_t sizeOfShapes = 0;
		size_t number = 0;
		while (number < buffer.getSize()) {

			if (buffer.getLetterFromStr(number) == '<') {
				number++;
				MyString shape;
				while (buffer.getLetterFromStr(number) != ' ') {
					shape.concatOneChar(buffer.getLetterFromStr(number));
					number++;
				}
				number++;
				//it can be done with less code, but this way we first check if it is right and when i tried doing it in one function it turns out to be much longer and even more spaghetti
				if (shape == "rect") {
	 
					double array[4];//number of variable besides fill that we need to fill
					size_t i = -1;
					MyString fill;
					while (buffer.getLetterFromStr(number) != '>') {
						if (buffer.getLetterFromStr(number) == '"')
						{
							number++;
							MyString temp;
							while (buffer.getLetterFromStr(number) != '"')
							{
								
								temp.concatOneChar(buffer.getLetterFromStr(number));
									number++;
							}
							number++;
							i++;
							if(i<4)array[i] = CharToDouble(temp);
							
							if (i == 3) {
								number++;
								while (buffer.getLetterFromStr(number) != '/') {
									number++;
									if (buffer.getLetterFromStr(number) == '"') {
										number++;
										while (buffer.getLetterFromStr(number) != '"') {
											fill.concatOneChar(buffer.getLetterFromStr(number));
											number++;
										}
										if (size >= capacity) resize();
										shapes[sizeOfShapes] = new Rectangle(array[0], array[1], fill, array[2], array[3]);
										if (shapes[sizeOfShapes] != nullptr) {
											//shapes[sizeOfShapes]->print();
											sizeOfShapes++;
											size++;

										}
									}
								}

							}


						}
							number++;
					}

				}
				else if (shape == "circle") {
					double array[3];//number of variable besides fill that we need to fill
					size_t i = -1;
					MyString fill;
					while (buffer.getLetterFromStr(number) != '>') {
						if (buffer.getLetterFromStr(number) == '"')
						{
							number++;
							MyString temp;
							while (buffer.getLetterFromStr(number) != '"')
							{

								temp.concatOneChar(buffer.getLetterFromStr(number));
								number++;
							}
							number++;
							i++;
							if (i < 3)array[i] = CharToDouble(temp);

							if (i == 2) {
								number++;
								while (buffer.getLetterFromStr(number) != '/') {
									number++;
									if (buffer.getLetterFromStr(number) == '"') {
										number++;
										while (buffer.getLetterFromStr(number) != '"') {
											fill.concatOneChar(buffer.getLetterFromStr(number));
											number++;
										}
										if (size >= capacity) resize();
										shapes[sizeOfShapes] = new Circle(array[0], array[1], fill, array[2]);
										if (shapes[sizeOfShapes] != nullptr) {
											//shapes[sizeOfShapes]->print();
											sizeOfShapes++;
											size++;

										}
									}
								}

							}


						}
						number++;
					}
				}
				else if (shape == "line") {
					double array[4];//number of variable besides fill that we need to fill
					size_t i = -1;
					MyString fill;
					while (buffer.getLetterFromStr(number) != '>') {
						if (buffer.getLetterFromStr(number) == '"')
						{
							number++;
							MyString temp;
							while (buffer.getLetterFromStr(number) != '"')
							{

								temp.concatOneChar(buffer.getLetterFromStr(number));
								number++;
							}
							number++;
							i++;
							if (i < 4)array[i] = CharToDouble(temp);

							if (i == 3) {
								number++;
								while (buffer.getLetterFromStr(number) != '/') {
									number++;
									if (buffer.getLetterFromStr(number) == '"') {
										number++;
										while (buffer.getLetterFromStr(number) != '"') {
											fill.concatOneChar(buffer.getLetterFromStr(number));
											number++;
										}
										if (size >= capacity) resize();
										shapes[sizeOfShapes] = new Line(array[0], array[1], fill, array[2], array[3]);
										if (shapes[sizeOfShapes] != nullptr) {
											//shapes[sizeOfShapes]->print();
											sizeOfShapes++;
											size++;

										}
									}
								}

							}


						}
						number++;
					}
				}
			}
			number++;
		}
	

}

void Container::setBuffer(const MyString& buffer)//we get the buffer from the file, we send it to class buffer, in order to use it shape by shape
{
	this->buffer=buffer;
}

double Container::CharToDouble(const MyString& other)
{
	return strtod(other.c_str(),nullptr);
}

void Container::saveALL()
{

	buffer="<?xml version=\"1.0\" standalone=\"no\"?>\n< !DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\" >\n< svg>";

		for (size_t i = 0; i < size; i++) {
			buffer.concat(shapes[i]->saveShape());
			buffer.concatOneChar('\n');
		}
		buffer.concat("</svg>");
		//std::cout << buffer.c_str();
		std::fstream file(fileName.c_str());
		if (file.is_open()) {
			file.write(buffer.c_str(), buffer.getSize());
		}
		file.close();
}

void Container::translateALL(double vertical, double horizontal) const
{
	for (size_t i = 0; i < size; i++) {
		//shapes[i]->print();
		shapes[i]->translate(vertical, horizontal);
		//shapes[i]->print();
	}
	std::cout << "All figures are translated" << std::endl;
}

void Container::translateParticular(double vertical, double horizontal, size_t index) const
{
	index = index - 1;
	if (index < size) {
		//shapes[index]->print();
		shapes[index]->translate(horizontal, vertical);
		//shapes[index]->print();
	}
	else std::cout << "No such figure." << std::endl;

}

void Container::WithinR(double x, double y, double width, double height) const
{
	std::cout << "Shapes that are in the Rectangle :" << std::endl;
	for (size_t i = 0; i < size; i++) {
		if (shapes[i]->WithinRectangle(x, y,width,height) == true) {
			shapes[i]->print();
		}
	}
}

void Container::WithinC(double x, double y, double r) const
{
	std::cout << "Shapes that are in the Circle :" << std::endl;
	for (size_t i = 0; i < size; i++) {
		if (shapes[i]->WithinCircle(x, y, r) == true) {
			shapes[i]->print();
		}
	}
}

void Container::setFileName(const MyString& name)
{
	fileName = name;
}



