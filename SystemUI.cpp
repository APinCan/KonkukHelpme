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
	cout <<endl;//9
	cout << "              #                                        ##########              #########      " << endl;//10
	cout << "              #                                       #          #                      #     " << endl;//11
	cout << "              #                                       #          #              ########      " << endl;//12
	cout << "              #########                                 ########                #			   " << endl;//13
	cout << "                                                                                 #######	   " << endl;//14
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
int SystemUI::mainTitleMenu()
{
	SystemEvent systemEvent;
	int x = 24;
	int y = 16;

	cursorMoveXY(x - 2, y);
	cout << "> ���ӽ���";
	cursorMoveXY(x, y+1);
	cout << "��������";
	cursorMoveXY(x, y + 2);
	cout << "  ��ŷ";
	cursorMoveXY(x, y+3);
	cout << "  ����";

	//Ư�� �̺�Ʈ�� �߻��Ҷ����� ���ѹݺ�
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
			//�޼��带 ���� �� ���������� ���� ������ �Լ��� �̵��Ҽ��ְ�
			return y - 16;
		}
	}
}
