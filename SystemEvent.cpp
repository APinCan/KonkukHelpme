#include "SystemEvent.h"



SystemEvent::SystemEvent()
{
}


SystemEvent::~SystemEvent()
{
}

//Ű���� �̺�Ʈ�� �޾ƿ�
int SystemEvent::keyboardEvent()
{
	char key = getchar();

	if (key == 'w' || key == 'W') {
		return UP;
	}
	else if (key == 'a' || key == 'A') {
		return LEFT;
	}
	else if (key == 's' || key == 'S') {
		return DOWN;
	}
	else if (key == 'd' || key == 'D') {
		return RIGHT;
	}
}