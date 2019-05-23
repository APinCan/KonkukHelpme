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
	cout << "																						" << endl;//9
	cout << "              #                                        ##########              #########      " << endl;//10
	cout << "              #                                       #          #                      #     " << endl;//11
	cout << "              #                                       #          #              ########      " << endl;//12
	cout << "              #########                                 ########                #			   " << endl;//13
	cout << "																		         #######	   " << endl;//14
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
void SystemUI::mainTitleMenu()
{
	cursorMoveXY(24 - 2, 16);
	cout << "> 게임시작";
	cursorMoveXY(24, 17);
	cout << "게임정보";
	cursorMoveXY(24, 18);
	cout << "    종료    " << endl;
}
