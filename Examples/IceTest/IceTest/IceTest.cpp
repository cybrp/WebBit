#include "stdafx.h"

#include "../../../Ice/ice.h"
using namespace System;

class Console
{
public:
	static void WriteLine(string &str)
	{
		std::cout << str;
	}

	static void ReadKey()
	{
		std::cin.get();
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	string str = "Hello World\n";
	Console::WriteLine(str);
	str += "Yes :-)";
	Console::WriteLine(str);
	Console::ReadKey();
	return 0;
}

