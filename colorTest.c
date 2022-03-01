#include <stdio.h>
#include <windows.h>

int main() {
	int n = 1;
	HANDLE  hConsole;
 	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for(;;n++) {
	    SetConsoleTextAttribute(hConsole, n);
	  	printf("balls\t");
		if(n>420) n = 0;
	}
	return 0;
}
