#pragma once
#include<iostream>
#include<windows.h>

using namespace std;

class SystemUI
{
public:
	SystemUI();
	~SystemUI();
	void frameDesign();
	void mainTitle();
	void cursorMoveXY(int x, int y);
	void mainTitleMenu();
};

