#include "SystemUI.h"



SystemUI::SystemUI()
{
}


SystemUI::~SystemUI()
{
}

//�ܼ�â�� ũ�⸦ ����
void SystemUI::frameDesign()
{
	system("mode con cols=150 lines=60 | title �Ǵ�� �����");
}

//����Ÿ��Ʋ �ؽ�Ʈ ���
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
	//�ܼ��� �ڵ� ��������
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

//Ÿ��Ʋ�� �޴��� ���
void SystemUI::mainTitleMenu()
{
	cursorMoveXY(24 - 2, 16);
	cout << "> ���ӽ���";
	cursorMoveXY(24, 17);
	cout << "��������";
	cursorMoveXY(24, 18);
	cout << "    ����    " << endl;
}
