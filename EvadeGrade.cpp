#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include "EvadeGrade.h"
#define MapX 30
#define MapY 30
using namespace std;
int map[MapY][MapX];
int Person[MapX] = { 0, };
int PerPosition = (int)(MapX / 2.0);

EvadeGrade::EvadeGrade()
{
}


EvadeGrade::~EvadeGrade()
{
}

void EvadeGrade:: gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//speed ��Ʈ��
int EvadeGrade::gradespeed(int *speed, int *score)
{
	if (*score > 50) *speed = 80;
	if (*score > 100) *speed = 50;
	if (*score > 150) *speed = 30;
	if (*score > 200) *speed = 10;
	if (*score > 250) *speed = 1;
	return *speed;
}


//�ʰ��ǥ��
void EvadeGrade:: Mapline()
{
	for (int i = 0; i < MapY + 1; i++)
	{
		gotoxy(MapX, i); printf("��\n");
	}
	gotoxy(0, MapY);
	for (int i = 0; i < MapX / 2; i++) printf("��");
}

//�� �ʱ�ȭ
void EvadeGrade:: InitMap()
{
	for (int i = 0; i < MapY; i++)
	{
		for (int j = 0; j < MapX; j++)
		{
			map[i][j] = 0;
		}
	}
}

//���� ���
void EvadeGrade:: PrintMap(int * P)
{
	for (int i = 0; i < MapY - 1; i++)
	{
		for (int j = 0; j < MapX; j++)
		{
			switch (map[i][j])
			{
			case 0:  printf(" "); break;
			case 1:  printf("A"); break;
			case 2:  printf("B"); break;
			case 3:  printf("C"); break;
			case 4:  printf("D"); break;
			case 5:  printf("F"); break;
			}
		}
		printf("\n");
	}

	for (int j = 0; j < MapX; j++)
	{
		if (P[j] == 0) printf(" ");
		else if (P[j] == 1) printf("��");
	}

}

void EvadeGrade:: RowDownMap()
{
	for (int i = MapY - 1; i > 0; i--)
	{
		for (int j = 0; j < MapX; j++)
		{
			map[i][j] = map[i - 1][j];
		}
	}
	for (int j = 0; j < MapX; j++)
	{
		map[0][j] = 0;
	}
}

//���, ���� ��� �Լ�
int EvadeGrade:: CollisionDetection(int *score, int * P, int *life)
{
	for (int i = 0; i < MapX; i++)
	{
		if (map[MapY - 1][i] && P[i]) {
			switch (map[MapY - 1][i])
			{
				gotoxy(MapX + 2, 3);
			case 1:
				printf(" A���� ���!! ���� ȸ��(+2)! ");
				*life += 2;
				break;
			case 2:
				printf(" B���� ���!! ���� ����(-1)! ");
				*life -= 1;
				break;
			case 3:
				printf(" C���� ���!! ���� ����(-1)! ");
				*life -= 2;
				break;
			case 4:
				printf(" D���� ���!! ���� ����(-1)! ");
				*life -= 3;
				break;
			case 5:
				system("color f0");
				*life -= 1000;
				break;
			}

			gotoxy(MapX + 2, 0);
			printf("LIFE:                                         ");
			gotoxy(MapX + 2, 0);
			printf("LIFE:");

			for (unsigned int i = 0; i < *life; i++)
			{
				printf("��");
				if (*life < 0) {
					break;
				}
			}
		}

		else if (P[i] != 1) {
			switch (map[MapY - 1][i])
			{
			case 2:
				*score += 1;
				break;//B�� ������
			case 3:
				*score += 2;
				break;//C�� ������
			case 4:
				*score += 3;
				break;//D�� ������
			case 5:
				*score += 4;
				break;//F�� ������
			}
		}
	}
	if (*life < 0) {
		return 1;
	}
	return 0;
}

void EvadeGrade:: randline() 
{
	int Position;
	for (int i = 0; i < rand() % 4; i++)// ���δ� ���� 0~3�� ��������
	{
		int num = rand() % 6;
		Position = rand() % MapX;
		map[0][Position] = num;
	}
}

void EvadeGrade:: keycontrol() {
	int ch;
	if (_kbhit())
	{
		ch = _getch();
		ch = _getch();
		if (ch == 75 && PerPosition > 0)
		{
			Person[PerPosition] = 0;
			PerPosition--;
			Person[PerPosition] = 1;
		}
		else if (ch == 77 && PerPosition < MapX - 1)
		{
			Person[PerPosition] = 0;
			PerPosition++;
			Person[PerPosition] = 1;
		}
	}
}
void EvadeGrade::play()
{
	int stage = 1;
	int score = 0;
	int life = 5;
	int speed = 100;

	InitMap();
	Mapline();

	gotoxy(MapX + 2, 0);
	printf("LIFE:����������");

	srand((unsigned)time(NULL));
	Person[PerPosition] = 1;

	for (;;)
	{
		RowDownMap();
		randline();
		keycontrol();
		gotoxy(0, 0);
		PrintMap(Person);

		if (life < 2)
			system("color f4");//����
		if (life >= 2 and life < 5)
			system("color f6");//���
		if (life >= 5)
			system("color f1");//�Ķ�

		if (CollisionDetection(&score, Person, &life)) break;
		gradespeed(&speed, &score);
		Sleep(speed);
		//���,��������,���� ���
		gotoxy(MapX + 2, 1);
		printf("STAGE:%d", (score / 50) + 1);
		gotoxy(MapX + 2, 2);
		printf("score:%d", score);
	}

	system("cls"); //���� ���� ���

	for (int i = 0; i < 5; i++) { cout << "                                                                 " << endl; }
	cout << " " << "###################################################################################" << endl;
	cout << " " << "                                    Game Over!!                                   " << endl;
	cout << " " << "                           � ����� ������ " << score << " �� �Դϴ� �                      " << endl;
	cout << " " << "                                                                                 " << endl;
	cout << " " << "###################################################################################" << endl;

	for (int i = 0; i < 3; i++) { cout << "                                                                 " << endl; }
	cout << " " << ".d8888b.                                        .d88888b." << endl;
	cout << " " << "d88P  Y88b                                     d88P' 'Y88b" << endl;
	cout << " " << "888    888                                     888     888" << endl;
	cout << " " << "888         8888b.  88888b.d88b.   .d88b.      888     888 888  888  .d88b.  888d888" << endl;
	cout << " " << "888  88888     '88b 888 '888 '88b d8P  Y8b     888     888 888  888 d8P  Y8b 888P'" << endl;
	cout << " " << "888    888 .d888888 888  888  888 88888888     888     888 Y88  88P 88888888 888" << endl;
	cout << " " << "Y88b  d88P 888  888 888  888  888 Y8b.         Y88b. .d88P  Y8bd8P  Y8b.     888" << endl;
	cout << " " << "'Y8888P88  'Y888888 888  888  888  'Y8888       'Y88888P'    Y88P    'Y8888  888" << endl;
}


void EvadeGrade::showEvadeGradeView(int width, int height)
{
	system("cls");
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
	play();
}