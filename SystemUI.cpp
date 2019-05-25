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
	cout << "\n\n\n\n"; //0,1,2,3
	cout << "           ######     #       ######    #    #          #     #    #             #     #      "<<endl; //4
	cout << "               #      #       #         #    #         #      #    #            #      #	   "<< endl; //5
	cout << "              #    ####       #         ######        # #     ######           # #     #####  " << endl;//6
	cout << "             #        #       #         #    #       #   #    #    #          #   #    #	   " << endl;//7
	cout << "            #         #       ######    #    #      #     #   #    #         #     #   #	   " << endl;//8
	cout <<endl;//9
	cout << "              #                                        ##########              #########      " << endl;//10
	cout << "              #                                       #          #                      #     " << endl;//11
	cout << "              #                                       #          #              ########      " << endl;//12
	cout << "              #########                                 ########                #			   " << endl;//13
	cout << "                                                                                 #######	   " << endl;//14
}

void SystemUI::cursorMoveXY(int x, int y)
{
	//콘솔의 핸들 가져오기
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

//타이틀의 메뉴를 출력
int SystemUI::mainTitleMenu()
{
	SystemEvent systemEvent;
	int x = 24;
	int y = 16;

	cursorMoveXY(x - 2, y);
	cout << "> 게임시작(game1)";
	cursorMoveXY(x, y+1);
	cout << "게임시작(game2)";
	cursorMoveXY(x, y + 2);
	cout << "게임시작(game3)";
	cursorMoveXY(x, y + 3);
	cout << "  랭킹";
	cursorMoveXY(x, y+4);
	cout << "  종료";

	//특정 이벤트가 발생할때까지 무한반복
	while (true) {
		int key = systemEvent.keyboardEvent();

		switch (key) {
		case UP:
			if (y > 16) {
				cursorMoveXY(x - 2, y);
				cout << " ";
				cursorMoveXY(x - 2, --y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 20) {
				cursorMoveXY(x - 2, y);
				cout << " ";
				cursorMoveXY(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT:
			//메서드를 통해 뭘 눌렀는지에 따른 적절한 함수로 이동할수있게
			//인덱스는 0부터 시작
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
		//랭킹
	case 3:
		rankingView.showRankingView();
		break;
		//종료
	case 4:
		break;
	}
}
