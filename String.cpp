#include "String.h"

using namespace HomeMadeString;

//Default Contructor
String::String() : elementNum(0), pData(NULL)
{}

// Copy constructor:
String::String(const String &oldString)
{
	elementNum = oldString.elementNum;
	pData = new char[elementNum + 1];
	for (int i = 0; i < elementNum; i++)
	{
		pData[i] = oldString.pData[i];
	}
	pData[elementNum] = '\0';
}


// Conversion constructor that expects a char* with '\0' at the end
// This constructor is responsible for the conversion char*-> String
String::String(const char *str)
{
	//char null;
	int i = 0, count = 0;
	while (true)
	{
		if (str[i] != '\0')
			count++;
		else
			break;
		i++;
	}
	elementNum = count;
	pData = new char[elementNum + 1];
	for (i = 0; i < elementNum; i++)
	{
		pData[i] = str[i];
	}
	pData[elementNum] = '\0';
}


// Constructor with a char (c) and an int parameter (times)
// This constructor creates a string that contains 'times' pieces of the character c
// e.g. if c='$' and times=5 then String="$$$$$"
String::String(const char c, int times)
{
	elementNum = times;
	pData = new char[elementNum + 1];
	for (int i = 0; i < elementNum; i++)
	{
		pData[i] = c;
	}
	pData[elementNum] = '\0';
}


// Destructor:
String::~String()
{
	elementNum = 0;
	delete[] pData;
	pData = NULL;
}


// Copies the string to the buffer and terminates it with '\0' (string terminating character)
// Memory allocation for the buffer is to be done by a caller
void String::getStr(char *pBuff)
{
	for (int i = 0; i < elementNum; i++)
	{
		pBuff[i] = pData[i];
	}
	pBuff[elementNum] = '\0';
}


// Returns with the string length
int String::getLength()
{
	return elementNum;
}


// Writes the string to the given stream
void String::print(std::ostream &os)
{
	for (unsigned int i = 0; i < elementNum; i++)
	{
		os << pData[i];
	}
}


// Returns with the character at the given position, othewise 0
char String::getChar(int pos)
{
	if (pos < 0 || pos >= elementNum)
		return 0;
	return pData[pos];
}

// --- Static Class Members. They work with two strings passed as parameters. ---



// Returns with a concatenated string
String String::concatenate(const String &string1, const String &string2)
{
	int length = string1.elementNum + string2.elementNum;
	String string3;
	string3.elementNum = length;
	string3.pData = new char[length + 1];
	int i;
	for (i = 0; i < string1.elementNum; i++)
	{
		string3.pData[i] = string1.pData[i];
	}
	for (i = string1.elementNum; i < length; i++)
	{
		int x = 0;
		string3.pData[i] = string2.pData[x];
		x++;
	}
	string3.pData[length] = '\0';
	return string3;
}



// Compares two strings
bool String::compare(const String &string1, String string2)
{
	if (string1.elementNum == string2.elementNum)
	{
		for (int i = 0; i < string1.elementNum; i++)
		{
			if (string1.pData[i] == string2.pData[i])
				;
			else
			{
				return false;
			}
		}
		return true;
	}
	return false;
}



// Copies string2 to string1
void String::copy(String &string1, const String &string2)
{
	int size = string2.elementNum;
	string1.elementNum = size;
	char *tempPtr = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		tempPtr[i] = string2.pData[i];
	}
	tempPtr[size] = '\0';
	string1.pData = tempPtr;

	/*
	ALTERNATE METHOD
	Copy Constructor can be called here!!!
	string1(string2);
	*/
}
