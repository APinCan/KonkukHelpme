#include "SystemUI.h"



SystemUI::SystemUI()
{
}


SystemUI::~SystemUI()
{
}

//콘솔창의 크기를 조정
void SystemUI::frameDesign()
{
	system("mode con cols=150 lines=60 | title 건대생 살려조");
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
	cout << "> 게임시작";
	cursorMoveXY(x, y+1);
	cout << "게임정보";
	cursorMoveXY(x, y + 2);
	cout << "  랭킹";
	cursorMoveXY(x, y+3);
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
			if (y < 19) {
				cursorMoveXY(x - 2, y);
				cout << " ";
				cursorMoveXY(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT:
			//메서드를 통해 뭘 눌렀는지에 따른 적절한 함수로 이동할수있게
			return y - 16;
		}
	}
}
