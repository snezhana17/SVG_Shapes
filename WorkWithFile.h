#pragma once
#include "MyString.h"
class WorkWithFile {
	MyString fileName; //the file name we get from the user
	MyString buffer; //all the information we get from the file
	MyString realBuffer;//the information we receive after the <svg> file including that tag
public:
	bool readFromFile();
	void setFileName(const MyString&);
	MyString& getFileName();
	void setBuffer();
	void removeSvgTags();
	const MyString& getRealBuffer() const;

};