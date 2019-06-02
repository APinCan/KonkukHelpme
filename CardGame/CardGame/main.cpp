#include"card.h"
#include<iostream>

using namespace std;

void main()
{
	Card c;
	c.SetConsoleSize(720, 640);
	c.cardShuffle();
	c.Display0();
	Sleep(4000);

	while (1)

	{

		c.Display1();

		c.selectPlay1();

		c.Display1();

		c.selectPlay2();

		c.Display2();

		if (c.getOC() == 14) break;//일곱짝 다 찾으면 탈출 //OR 학식을 고르면  game over.//playcount를 제한을 둬서 game over할까 고민중.

	}

	c.GameOver();




}
