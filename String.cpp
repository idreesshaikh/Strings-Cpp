#include "String.h"

using namespace HomeMadeString;

String::String() : elementNum(0), pData(NULL)
{}

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


String::~String()
{
	elementNum = 0;
	delete[] pData;
	pData = NULL;
}


void String::getStr(char *pBuff)
{
	for (int i = 0; i < elementNum; i++)
	{
		pBuff[i] = pData[i];
	}
	pBuff[elementNum] = '\0';
}


int String::getLength()
{
	return elementNum;
}


void String::print(std::ostream &os)
{
	for (unsigned int i = 0; i < elementNum; i++)
	{
		os << pData[i];
	}
}


char String::getChar(int pos)
{
	if (pos < 0 || pos >= elementNum)
		return 0;
	return pData[pos];
}


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
