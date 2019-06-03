#include "SystemUI.h"



SystemUI::SystemUI()
{
}


SystemUI::~SystemUI()
{
}

//콘솔창의 크기를 조정
void SystemUI::initFrame()
{
	system("mode con cols=150 lines=60 | title 건대생 살려조");

	//콘솔창의 커서 숨기기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//콘솔창 핸들가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	//flase or 0을 하면 커서를 숨김
	ConsoleCursor.bVisible = 0; 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

//메인타이틀 텍스트 출력
void SystemUI::mainTitle()
{
	SystemEvent systemEvent;
	cout << "\n\n\n\n"; //0,1,2,3

	cout << "         __ __            __         __" << endl; //4
	cout << "        / //_/___  ____  / /____  __/ /__" << endl; //5
	cout << "       / ,< / __ |/ __ |/ //_/ / / / //_/" << endl;//6
	cout << "      / /| / /_/ / / / / ,< / /_/ / ,<" << endl;//7
	cout << "     /_/ |_|____/_/ /_/_/|_||__,_/_/|_| __" << endl;//8
	cout << "" << endl;//9
	cout << "        / / / /__  / /___  /  |/  /__  / /" << endl; //10
	cout << "       / /_/ / _ |/ / __ |/ /|_/ / _ |/ /" << endl; //11
	cout << "      / __  /  __/ / /_/ / /  / /  __/_/" << endl;//12
	cout << "     /_/ /_/|___/_/ .___/_/  /_/|___(_)" << endl;//13
	cout << "                 /_/" << endl;//14
	cout << "\n\n";//15,16
	cout << "===============================================" << endl; //17
	cout << "||                                           ||" << endl;//18
	cout << "||                                           ||" << endl;//19
	cout << "||                                           ||" << endl; //20
	cout << "||                                           ||" << endl; //21
	cout << "=============================================== " << endl;

}

/*
void SystemUI::cursorMoveXY(int x, int y)
{
	//콘솔의 핸들 가져오기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
*/

//타이틀의 메뉴를 출력
int SystemUI::mainTitleMenu()
{
	SystemEvent systemEvent;
	int x = 28;
	int y = 28;

	systemEvent.cursorMoveXY(19, 20);
	cout << "> Name" << endl;
	systemEvent.cursorMoveXY(x - 2, y);
	cout << "> 게임시작(game1)";
	systemEvent.cursorMoveXY(x, y+1);
	cout << "게임시작(game2)";
	systemEvent.cursorMoveXY(x, y + 2);
	cout << "게임시작(game3)";
	systemEvent.cursorMoveXY(x, y + 3);
	cout << "  랭킹";
	systemEvent.cursorMoveXY(x, y+4);
	cout << "  종료";

	//특정 이벤트가 발생할때까지 무한반복
	while (true) {
		int key = systemEvent.keyboardEvent();

		switch (key) {
		case UP:
			if (y > 28) {
				systemEvent.cursorMoveXY(x - 2, y);
				cout << " ";
				systemEvent.cursorMoveXY(x - 2, --y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 32) {
				systemEvent.cursorMoveXY(x - 2, y);
				cout << " ";
				systemEvent.cursorMoveXY(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT:
			//메서드를 통해 뭘 눌렀는지에 따른 적절한 함수로 이동할수있게
			//인덱스는 0부터 시작
			return y - 28;
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
		evadeGrade.showEvadeGradeView();
		break;
		//2=game3
	case 2:
		cout << "game3" << endl;
		break;
		//랭킹
	case 3:
		rankingView.showRankingView();
		break;
		//종료
	case 4:
		break;
	}
}
