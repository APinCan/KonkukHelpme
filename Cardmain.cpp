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

		if (c.getOC() == 14) break;//?¼ê³±ì§???ì°¾ìœ¼ë©??ˆì¶œ //OR ?™ì‹??ê³ ë¥´ë©? game over.//playcountë¥??œí•œ???¬ì„œ game over? ê¹Œ ê³ ë?ì¤?

	}

	c.GameOver();




}
