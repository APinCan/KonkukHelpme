#include "card.h"

Card::Card()
{
	this->resultX1 = 5;
	this->resultX2 = 5;
	this->resultY1 = 6;
	this->resultY2 = 6;
	this->playCount = 0;
	this->openCount = 0;
	this->score = 0;
}
int Card::getScore() {
	return this->score;
}
int Card::getOC() {
	return this->openCount;
}
int Card::getPC() {
	return this->playCount;
}

void Card::cardShuffle() {
	srand(time(NULL));

	int row1, row2, col1, col2;	// ī�� ���� ����

	for (int i = 0; i < 1000; i++) {

		row1 = rand() % 4;

		row2 = rand() % 4;

		col1 = rand() % 4;

		col2 = rand() % 4;

		swap(back[row1][col1], back[row2][col2]);

		swap(result[row1][col1], result[row2][col2]);
	}
}

void Card::Display0() {
	system("cls");
	cout << endl;
	cout << "                ī�� ������ ����" << endl;
	cout << " ������ Ƚ�� : " << playCount << endl;
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	for (int i = 0; i < 4; i++) {
		cout << "              " << "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;
		cout << "              " << "  ��          ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		cout << "              " << "  �� " << back[i][0] << " ��" << " �� " << back[i][1] << " ��" << " �� " << back[i][2] << " �� " << "�� " << back[i][3] << " �� " << endl;
		cout << "              " << "  ��          ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		cout << "              " << "  ��          ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		cout << "              " << "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;
	}
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
}

void Card::Display1() {
	system("cls");
	cout << endl;
	cout << "                ī�� ������ ����" << endl;
	cout << " ������ Ƚ�� : " << playCount << endl;
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	for (int i = 0; i < 4; i++) {
		cout << "              " << "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;

		if ((resultX1 == i && resultY1 == 0) || (resultX2 == i && resultY2 == 0) || openCard[i][0] == 1)
		{
			cout << "              " << "  �� " << back[i][0] << " ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		}
		else { cout << "              " << "  ��    " << back[i][0] << "    ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 1) || (resultX2 == i && resultY2 == 1) || openCard[i][1] == 1)
		{
			cout << "              " << "  ��          ��" << " �� " << back[i][1] << " �� " << "��          ��" << " ��          ��" << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��    " << front[i][1] << "    ��" << " ��          ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 2) || (resultX2 == i && resultY2 == 2) || openCard[i][2] == 1)
		{
			cout << "              " << "  ��          ��" << " ��          ��" << " �� " << back[i][2] << " �� " << "��          ��" << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��          ��" << " ��    " << front[i][2] << "    ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 3) || (resultX2 == i && resultY2 == 3) || openCard[i][3] == 1)
		{
			cout << "              " << "  ��          ��" << " ��          ��" << " ��          �� " << "�� " << back[i][3] << " �� " << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��          ��" << " ��          ��" << " ��    " << front[i][3] << "    �� " << endl; }

		cout << "              " << "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;
	}
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
}



void Card::selectPlay1() {

	int x, y;	// 0�� 0���� �ƴ� 1�� 1���� �����ϰ� �ϱ� ���� ����

	cout << " 1��° ������ ī�带 �����ϼ��� ( ex) 1 1 ~ 4 4 ) : ";

	cin >> x >> y;

	resultX1 = x - 1;

	resultY1 = y - 1;

	// 4�� 4�� �ȿ� ������ Ȯ���ؼ� �ƴϸ� �ٽ� �Է�

	while (resultX1 > 3 || resultX1 < 0 || resultY1 > 4 || resultY1 < 0 || openCard[resultX1][resultY1] == 1) {

		cout << " �߸��Է��ϼ̰ų� �̹� ���µ� ī���Դϴ�." << endl;

		cout << " 1��° ������ ī�带 �缱���ϼ��� ( ex) 1 1 ~ 4 4 ) : ";

		cin >> x >> y;

		resultX1 = x - 1;

		resultY1 = y - 1;
	}
}

void Card::selectPlay2() {
	playCount++;	// �Է��Ҷ����� ����

	int x, y;		// 0�� 0���� �ƴ� 1�� 1���� �����ϰ� �ϱ� ���� ����

	cout << " 2��° ������ ī�带 �����ϼ��� ( ex) 1 1 ~ 4 4 ) : ";

	cin >> x >> y;

	resultX2 = x - 1;

	resultY2 = y - 1;

	// 4�� 5�� �ȿ� ������ Ȯ���ؼ� �ƴϸ� �ٽ� �Է�

	while (resultX2 > 3 || resultX2 < 0 || resultY2 > 4 || resultY2 < 0 || openCard[resultX2][resultY2] == 1 || (resultX1 == resultX2 && resultY1 == resultY2)) {

		cout << " �߸��Է��ϼ̰ų� �̹� ���µ� ī���Դϴ�." << endl;

		cout << " 2��° ������ ī�带 �缱���ϼ��� ( ex) 1 1 ~ 4 4 ) : ";

		cin >> x >> y;

		resultX2 = x - 1;

		resultY2 = y - 1;
	}

	// ī�带 ���߾��ٸ� 
	// ī�带 ���߾��µ� ���� �н��̴�. --> �ٷ� game out
	if (result[resultX1][resultY1] == 3 && result[resultX2][resultY2] == 3) {
		GameOver();
	}
	else if (result[resultX1][resultY1] == result[resultX2][resultY2]) {

		openCard[resultX1][resultY1] = 1;

		openCard[resultX2][resultY2] = 1;

		openCount += 2;

		score += 10;
	}
}

void Card::Display2() {

	system("cls");

	cout << endl;

	cout << "                ī�� ������ ����" << endl;

	cout << " ������ Ƚ�� : " << playCount << endl;
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	for (int i = 0; i < 4; i++) {
		cout << "              " << "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;

		if ((resultX1 == i && resultY1 == 0) || (resultX2 == i && resultY2 == 0) || openCard[i][0] == 1)
		{
			cout << "              " << "  �� " << back[i][0] << " ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		}
		else { cout << "              " << "  ��    " << front[i][0] << "    ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 1) || (resultX2 == i && resultY2 == 1) || openCard[i][1] == 1)
		{
			cout << "              " << "  ��          ��" << " �� " << back[i][1] << " �� " << "��          ��" << " ��          ��" << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��    " << front[i][1] << "    ��" << " ��          ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 2) || (resultX2 == i && resultY2 == 2) || openCard[i][2] == 1)
		{
			cout << "              " << "  ��          ��" << " ��          ��" << " �� " << back[i][2] << " �� " << "��          ��" << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��          ��" << " ��    " << front[i][2] << "    ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 3) || (resultX2 == i && resultY2 == 3) || openCard[i][3] == 1)
		{
			cout << "              " << "  ��          ��" << " ��          ��" << " ��          �� " << "�� " << back[i][3] << " �� " << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��          ��" << " ��          ��" << " ��    " << front[i][3] << "    �� " << endl; }

		cout << "              " << "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;
	}
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	Sleep(500);

	// �ʱ�ȭ

	resultX1 = 5;
	resultY1 = 6;
	resultX2 = 5;
	resultY2 = 6;
}

void Card::SetConsoleSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Card::grade(int score) {
	if (score >= 70) { cout << " " << "#                                A �Դϴ�.                                        #" << endl; }
	else if (score >= 50) { cout << " " << "#                                B �Դϴ�.                                        #" << endl; }
	else if (score >= 30) { cout << " " << "#                                C �Դϴ�.                                        #" << endl; }
	else if (score >= 10) { cout << " " << "#                                D �Դϴ�.                                        #" << endl; }
	else { cout << " " << "#                                F �Դϴ�.                                        #" << endl; }
}

void Card::GameOver() {
	system("cls");

	for (int i = 0; i < 5; i++) { cout << "                                                                 " << endl; }
	cout << " " << "###################################################################################" << endl;
	cout << " " << "#                                                                                 #" << endl;
	cout << " " << "#                                " << playCount << " �� ������ �����ϼ̽��ϴ�                       #" << endl;
	grade(score);
	cout << " " << "#                                                                                 #" << endl;
	cout << " " "###################################################################################" << endl;

	for (int i = 0; i < 3; i++) { cout << "                                                                 " << endl; }
	cout << " " << ".d8888b.                                        .d88888b." << endl;
	cout << " " << "d88P  Y88b                                     d88P' 'Y88b" << endl;
	cout << " " << "888    888                                     888     888" << endl;
	cout << " " << "888         8888b.  88888b.d88b.   .d88b.      888     888 888  888  .d88b.  888d888" << endl;
	cout << " " << "888  88888     '88b 888 '888 '88b d8P  Y8b     888     888 888  888 d8P  Y8b 888P'" << endl;
	cout << " " << "888    888 .d888888 888  888  888 88888888     888     888 Y88  88P 88888888 888" << endl;
	cout << " " << "Y88b  d88P 888  888 888  888  888 Y8b.         Y88b. .d88P  Y8bd8P  Y8b.     888" << endl;
	cout << " " << "'Y8888P88  'Y888888 888  888  888  'Y8888       'Y88888P'    Y88P    'Y8888  888" << endl;
	Sleep(10000000);//�ϴ��� ������� �ϴ°ɷ�.....
}
