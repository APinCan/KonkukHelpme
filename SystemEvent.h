#pragma once
#include<iostream>
#include<Windows.h>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

/*
https://codevkr.tistory.com/15?category=699626
*/


class SystemEvent
{
public:
	SystemEvent();
	~SystemEvent();
	int keyboardEvent();
};

