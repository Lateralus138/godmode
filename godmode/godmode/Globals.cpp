#include "Globals.h"
#include <iostream>
void WaitCheck()
{
	const bool ISOWNWINDOW = []()
	{
		DWORD processList[2] = { 0 };
		const DWORD maxList = 2;
		DWORD result = GetConsoleProcessList((LPDWORD)processList, maxList);
		return (result == 1);
	}();
	if (ISOWNWINDOW)
	{
		std::cout << "Press [\x1b[1;3;93mEnter\x1b[m] to continue... > ";
		std::cin.ignore();
	}
}