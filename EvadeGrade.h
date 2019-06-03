#pragma once
#include<windows.h>
#include<iostream>

using namespace std;

class EvadeGrade
{
public:
	EvadeGrade();
	~EvadeGrade();
	void gotoxy(int x, int y);
	int gradespeed(int *speed, int *score);
	void Mapline();
	void InitMap();
	void PrintMap(int * P);
	void RowDownMap();
	int CollisionDetection(int *score, int * P, int *life);
	void randline();
	void keycontrol();
	void play();
	void showEvadeGradeView();
};
