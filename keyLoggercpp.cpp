#include <iostream>
#include <fstream>
using namespace std;

//functions used:
void StartLog(string input);


int main()
{
	cout << "hello";
	StartLog("hi");
}


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