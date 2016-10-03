#include <iostream>
using namespace std;
#include "console.h"
#include "myscreen.h"

CConsole * console;
extern CConsole * console;
int main(){
	// new 
	CMyScreen main;
	main.Init();
	
	return 0;
}

