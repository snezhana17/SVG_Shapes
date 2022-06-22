#pragma once

class MyString
{
private:
	char* str;
	size_t size;
	void copyFrom(const MyString&);
	void free();
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	char getLetterFromStr(size_t);//gets a specific char, given the index
	/*void setLetterFromStr(size_t, char);*/
	void print();
	void printnl();
	bool operator==(const MyString&);
	bool operator!=(const MyString&);
	bool operator>(const MyString&);
	bool operator<(const MyString&);
	size_t getSize()const;
	char* c_str()const;
	void concat(const MyString&);
	~MyString();
	void concatOneChar(const char);
};

