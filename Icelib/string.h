/*
	Icelib
	string type
	2015 © Bitcup
	http://www.bitcup.net
*/

#pragma once
#include "types.h"

namespace System
{
	class string
	{
	private:
		int length = 0;
		char *data = null;		

	public:		
		// Constructor by default
		string() {};

		// Constructor from char string
		string(const char *str);

		// Constructor from string
		string(const string &str);

		// Destructor
		~string();

		// Concatenates two strings
		const string operator +(const string &str);

		// Concatenates string and char string
		const string operator +(const char *str);

		// Concatenates char string and string
		friend string operator+(const char *str1, const string &str2);

		// Concatenates string and char
		const string operator +(char c);

		// Concatenates char and string
		friend string operator+(const char c, const string &str);		

		// Assigns string to the string
		string& operator= (const string &str);

		// Assigns char string to the string
		string& operator= (const char *str);

		// Assigns char to the string
		string& operator= (char c);

		// Appends string to the string
		string& operator+= (const string &str);

		// Appends char string to the string
		string& operator+= (const char *str);

		// Appends char symbol to the string
		string& operator+= (char c);

		// Returns char symbol at index position
		char& operator[] (uint index);

		// Returns char symbol at index position
		const char& operator[] (uint index) const;

		// Returns char string
		operator char*() const;

		// Returns length of the string
		uint Length() const;

		// Returns size of the string in bytes
		uint Size() const;

		// Returns true if the string is empty
		bool IsEmpty() const;
	};
};

