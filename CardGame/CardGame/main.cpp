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

		if (c.getOC() == 14) break;//�ϰ�¦ �� ã���� Ż�� //OR �н��� ����  game over.//playcount�� ������ �ּ� game over�ұ� �����.

	}

	c.GameOver();




}
