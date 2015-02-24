#include "stdafx.h"
#include "string.h"
#include <cstring>

namespace System
{
	string::string(const char *str)
	{
		length = strlen(str);
		data = new char[length + 1];		
		memcpy(data, str, length + 1);
	}

	string::string(const string &str)
	{
		length = str.length;
		data = new char[length + 1];
		memcpy(data, str.data, length + 1);
	}

	string::~string()
	{
		if (length > 0)
		{
			delete data;
		}
	};
	
	const string string::operator +(const string &str)
	{
		return *this += str;
	}
	
	const string string::operator +(const char *str)
	{
		return *this += str;
	}

	string operator+(const char *str1, const string &str2)
	{
		return string();	// TODO: 
	}

	const string string::operator +(char c)
	{
		return *this += c;
	}

	string operator+(const char c, const string &str2)
	{
		return string();	// TODO:
	}

	string& string::operator= (const string &str)
	{
		if (this == &str)
			return *this;
		if (length > 0)
			delete data;
		length = str.length;
		data = new char[length + 1];
		memcpy(data, str.data, length + 1);
		return *this;
	}

	string& string::operator= (const char *str)
	{
		if (length > 0)
			delete data;
		length = strlen(str);
		data = new char[length + 1];
		memcpy(data, str, length + 1);
		return *this;
	}

	string& string::operator= (char c)
	{
		if (length > 0)
			delete data;
		data = new char[2];
		data[0] = c;
		data[1] = '\0';
		return *this;
	}

	string& string::operator+= (const string &str)
	{
		if (str.IsEmpty())
			return *this;
		int newLength = length + str.length;
		char *buf = new char[newLength + 1];
		memcpy(buf, data, length);
		memcpy(buf + length, str.data, str.length + 1);
		if (length > 0)
			delete data;
		data = buf;
		length = newLength;
		return *this;
	}

	string& string::operator+= (const char *str)
	{
		int strLength = strlen(str);
		if (strLength <= 0)
			return *this;
		int newLength = length + strLength;
		char *buf = new char[newLength + 1];
		memcpy(buf, data, length);
		memcpy(buf + length, str, strLength + 1);
		if (length > 0)
			delete data;
		data = buf;
		length = newLength;
		return *this;
	}

	string& string::operator+= (char c)
	{
		if (c == '\0')
			return *this;
		char *buf = new char[length + 2];
		memcpy(buf, data, length);
		buf[length] = c;
		buf[length + 1] = '\0';
		if (length > 0)
			delete data;
		data = buf;
		length++;
		return *this;
	}

	char& string::operator[] (uint index)
	{
		if (index < 0 || index >= length) 
			throw "Error out of range!";
		return data[index];
	}

	const char& string::operator[] (uint index) const
	{
		if (index < 0 || index >= length)
			throw "Error out of range!";
		return data[index];
	}

	string::operator char*() const
	{
		return data;
	}

	uint string::Length() const
	{
		return length;
	}

	uint string::Size() const
	{
		return length;
	}

	bool string::IsEmpty() const
	{
		return (length <= 0);
	}
};
