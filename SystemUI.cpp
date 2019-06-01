#include "SystemUI.h"



SystemUI::SystemUI()
{
}


SystemUI::~SystemUI()
{
}

//�ܼ�â�� ũ�⸦ ����
void SystemUI::initFrame()
{
	system("mode con cols=150 lines=60 | title �Ǵ�� �����");

	//�ܼ�â�� Ŀ�� �����
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//�ܼ�â �ڵ鰡������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	//flase or 0�� �ϸ� Ŀ���� ����
	ConsoleCursor.bVisible = 0; 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

//����Ÿ��Ʋ �ؽ�Ʈ ���
void SystemUI::mainTitle()
{
	cout << "\n\n\n\n"; //0,1,2,3

	cout << "         __ __            __         __" << endl;
	cout << "        / //_/___  ____  / /____  __/ /__" << endl;
	cout << "       / ,< / __ |/ __ |/ //_/ / / / //_/" << endl;
	cout << "      / /| / /_/ / / / / ,< / /_/ / ,<" << endl;
	cout << "     /_/ |_|____/_/ /_/_/|_||__,_/_/|_| __" << endl;
	cout << "" << endl;
	cout << "        / / / /__  / /___  /  |/  /__  / /" << endl;
	cout << "       / /_/ / _ |/ / __ |/ /|_/ / _ |/ /" << endl;
	cout << "      / __  /  __/ / /_/ / /  / /  __/_/" << endl;
	cout << "     /_/ /_/|___/_/ .___/_/  /_/|___(_)" << endl;
	cout << "                 /_/" << endl;
}

/*
void SystemUI::cursorMoveXY(int x, int y)
{
	//�ܼ��� �ڵ� ��������
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
*/

//Ÿ��Ʋ�� �޴��� ���
int SystemUI::mainTitleMenu()
{
	SystemEvent systemEvent;
	int x = 24;
	int y = 16;

	systemEvent.cursorMoveXY(x - 2, y);
	cout << "> ���ӽ���(game1)";
	systemEvent.cursorMoveXY(x, y+1);
	cout << "���ӽ���(game2)";
	systemEvent.cursorMoveXY(x, y + 2);
	cout << "���ӽ���(game3)";
	systemEvent.cursorMoveXY(x, y + 3);
	cout << "  ��ŷ";
	systemEvent.cursorMoveXY(x, y+4);
	cout << "  ����";

	//Ư�� �̺�Ʈ�� �߻��Ҷ����� ���ѹݺ�
	while (true) {
		int key = systemEvent.keyboardEvent();

		switch (key) {
		case UP:
			if (y > 16) {
				systemEvent.cursorMoveXY(x - 2, y);
				cout << " ";
				systemEvent.cursorMoveXY(x - 2, --y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 20) {
				systemEvent.cursorMoveXY(x - 2, y);
				cout << " ";
				systemEvent.cursorMoveXY(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT:
			//�޼��带 ���� �� ���������� ���� ������ �Լ��� �̵��Ҽ��ְ�
			//�ε����� 0���� ����
			return y - 16;
		}
	}
}

void SystemUI::mainMenuAction(int index)
{
	switch (index) {
	//0 = game1
	case 0:
		cout << "game1" << endl;
		break;
		//1= game2
	case 1:
		cout << "game2" << endl;
		break;
		//2=game3
	case 2:
		cout << "game3" << endl;
		break;
		//��ŷ
	case 3:
		rankingView.showRankingView();
		break;
		//����
	case 4:
		break;
	}
}
