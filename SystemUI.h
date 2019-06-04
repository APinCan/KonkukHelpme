#pragma once
#include<iostream>
#include<windows.h>
#include "SystemEvent.h"
#include "RankingView.h"
#include "EvadeGrade.h"
#include "card.h"

using namespace std;

class SystemUI
{
private:
	RankingView rankingView;
	EvadeGrade evadeGrade;
	Card card;

public:
	SystemUI();
	~SystemUI();
	void initFrame(int width, int height);
	void mainTitle();
	//void cursorMoveXY(int x, int y);
	int mainTitleMenu();
	void mainMenuAction(int index);
};

