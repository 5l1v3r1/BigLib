#include <iostream>
#include <windows.h>
#include "include/big_n.h"
#include "include/big_z.h"
#include "include/big_q.h"
#include "include/API.h"

void testPol();

int main(int argc, char *argv[]){
	//Set console color
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, ("green",10));

	API::parse_args(argc, argv);
}
