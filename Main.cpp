#include <iostream>
#include "SystemUI.h"

using namespace std;

int main() {
	SystemUI sysui;

	sysui.frameDesign();
	sysui.mainTitle();
	sysui.mainTitleMenu();
	
	system("pause");

	return 0;
}