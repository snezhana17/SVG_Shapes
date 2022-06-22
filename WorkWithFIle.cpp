#include "WorkWithFile.h"
#include <fstream>
#include <iostream>
bool WorkWithFile::readFromFile()
{
	std::ifstream file(fileName.c_str());
	if (file.is_open()) {
		file.seekg(0, std::ios::end);
		//tells where the end of the file is
		size_t size = file.tellg();
		//puts the reading of the file at the beginning again
		file.seekg(0);
		size_t indexOfChar=0;
		char* temp = new char[size+1];
		while (indexOfChar < size)//we send all the text to a char array
		{
			file.get(temp[indexOfChar]);
			indexOfChar++;
		}
		temp[size] = '\0';
		buffer = temp;//we send the char array to a MyString, to be  able to work easier with it
		//std::cout << buffer.c_str();
		delete[] temp;
		setBuffer();
		file.close();
		return true;
	}
	else return false;
}

void WorkWithFile::setFileName(const MyString& fileName)
{
	this->fileName = fileName;
	//std::cout << this->fileName.c_str();
}

MyString& WorkWithFile::getFileName()
{
	return this->fileName;
}

void WorkWithFile::setBuffer()
{
	size_t number = 0;
	while (number < buffer.getSize())
	{
		if (buffer.getLetterFromStr(number) == '<')//we search until the first opening tag {
		{
			MyString tag;
			while (buffer.getLetterFromStr(number) != '>'&&number<buffer.getSize())
			{

				tag.concatOneChar(buffer.getLetterFromStr(number));
				number++;
			}
			MyString tagName = "<svg";//we create this to check wether the tag is svg
			if (tag == tagName) // if it is we save everything from that tag 
			{
				number++;
				/*realBuffer.concat("<svg>");*/
				for (size_t i = number; i < buffer.getSize(); i++)
				{
					realBuffer.concatOneChar(buffer.getLetterFromStr(i));
					
					number++;
				}

				
				
			}
			
		}
			number++;
	}
	removeSvgTags();
}

void WorkWithFile::removeSvgTags()
{
	size_t number = 0;
	while (number < realBuffer.getSize())
	{
		if (realBuffer.getLetterFromStr(number) == '<')//we search until  opening tag {
		{
			MyString tag;
			while (realBuffer.getLetterFromStr(number) != '>'&&number<realBuffer.getSize())
			{

				tag.concatOneChar(realBuffer.getLetterFromStr(number));
				number++;
			}
			MyString tagName = "</svg";//we create this to check wether the tag is /svg
			if (tag == tagName) //if it is we save everything up until that tag
			{
				size_t freeSVG = number-5;
				MyString tempBuffer;
				for (size_t i = 0; i <freeSVG; i++)
				{
					tempBuffer.concatOneChar(realBuffer.getLetterFromStr(i));

					number++;
				}
				realBuffer = tempBuffer;
			}
				
		}
		number++;
	}
	//std::cout << realBuffer.c_str();
}

const MyString& WorkWithFile::getRealBuffer() const
{
	return realBuffer;
}
