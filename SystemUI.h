#pragma once
#include<iostream>
#include<windows.h>
#include "SystemEvent.h"
#include "RankingView.h"

using namespace std;

class SystemUI
{
private:
	RankingView rankingView;

public:
	SystemUI();
	~SystemUI();
	void initFrame();
	void mainTitle();
	void cursorMoveXY(int x, int y);
	int mainTitleMenu();
	void mainMenuAction(int index);
};

