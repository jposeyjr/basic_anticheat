#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <tlhelp32.h>



int main() {
	HWND hWnd = FindWindowA(NULL, "Cheat Engine 7.2"); 

	if (hWnd) {
		std::cout << "found you!" << '\n';
	}
	std::cout << "No cheat found" << '\n';

}