#include <iostream>
#include "conio.h"
#include "windows.h"
using namespace std;

class Setting {
public:
	void SetConsoleSize(int width, int height) {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, width, height, TRUE);
	}
	void gotoxy(int x, int y) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		_COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
	}
	/*
	void TextColor(int x) {
		HANDLE mau;
		mau = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(mau, x);
	}
	*/
};
const int screenWidth = 60, screenHeight = 35;
//enum Dir { STOP = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4 };
struct Position {
	int x;
	int y;
};
class Player
{
private:
	Position originalPivotPos; Position pivotPos;
	int direction;
public:
	Position bodyPos[3][3];
	inline void CalcBodyPos() {
		if (pivotPos.x <= 2) {
			pivotPos.x = 2;
		}
		if (pivotPos.x > screenWidth - 2) {
			pivotPos.x = screenWidth - 2;
		}
		if (pivotPos.y > screenHeight - 2) {
			pivotPos.y = screenHeight - 3;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i < 1) bodyPos[i][j].y = pivotPos.y - 1;
				else if (i > 1) bodyPos[i][j].y = pivotPos.y + 1;
				else bodyPos[i][j].y = pivotPos.y;
				if (j < 1) bodyPos[i][j].x = pivotPos.x - 1;
				else if (j > 1) bodyPos[i][j].x = pivotPos.x + 1;
				else bodyPos[i][j].x = pivotPos.x;
			}
		}
	}
	Player(int posX, int posY) {
		originalPivotPos.x = posX;
		originalPivotPos.y = posY;
		pivotPos = originalPivotPos;
		CalcBodyPos();
		direction = 0;
	}
	void Reset() {
		pivotPos = originalPivotPos;
		CalcBodyPos();
		direction = 0;
	}
	void Move() {
		switch (direction) {
		case 0:
			break;
		case 1:
			pivotPos.x -= 3;
			break;
		case 2:
			pivotPos.x += 3;
			break;
		case 3:
			pivotPos.y -= 3;
			break;
		case 4:
			pivotPos.y += 3;
			break;
		default:
			break;
		}
		CalcBodyPos();
	}
	inline int getPivotPosX() {
		return pivotPos.x;
	}
	inline int getPivotPosY() {
		return pivotPos.y;
	}
	inline int getDirection() {
		return direction;
	}
	inline void setDirection(int dir) {
		direction = dir;
	}
};
class Obstacle {
private:
	int speed; char bodyChar;
	Position originalPivotPos; Position pivotPos;
	int direction;
public:
	Position bodyPos[3][3];
	inline void CalcBodyPos() {
		if (pivotPos.x > screenWidth) {
			pivotPos.x = -1;
			speed = rand() % 3 + 1;
		}
		if (pivotPos.x < -1) {
			pivotPos.x = screenWidth - 1;
			speed = rand() % 3 + 1;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i < 1)
					bodyPos[i][j].y = pivotPos.y - 1;
				else if (i > 1) bodyPos[i][j].y = pivotPos.y + 1;
				else bodyPos[i][j].y = pivotPos.y;
				if (j < 1) bodyPos[i][j].x = pivotPos.x - 1;
				else if (j > 1) bodyPos[i][j].x = pivotPos.x + 1;
				else bodyPos[i][j].x = pivotPos.x;
			}
		}
	}
	Obstacle(int posX, int posY, int dir, int spd, char ch) {
		originalPivotPos.x = posX;
		originalPivotPos.y = posY;
		pivotPos = originalPivotPos;
		CalcBodyPos();
		speed = spd;
		direction = dir;
		bodyChar = ch;
	}
	void Reset() {
		pivotPos = originalPivotPos;
		CalcBodyPos();
	}
	void Move() {
		switch (direction) {
		case 0:
			break;
		case 1:
			pivotPos.x -= speed;
			break;
		case 2:
			pivotPos.x += speed;
			break;
		default:
			break;
		}
		CalcBodyPos();
	}
	inline int getPivotPosX() {
		return pivotPos.x;
	}
	inline int getPivotPosY() {
		return pivotPos.y;
	}
	inline char getBodyChar() {
		return bodyChar;
	}
	inline int getDirection() {
		return direction;
	}
};
class GameManager {
private:
	int score;
	int width; int height;
	bool quit; bool restart;
	bool gameOver;
	Player *player;
	Obstacle *obs[10];
	Setting* set;
public:
	GameManager(int h, int w) {
		height = h, width = w;
		score = 0;
		gameOver = false;
		player = new Player(width / 2 - 1, height - 3);
		for (int i = 0; i < 10; i++) {
			int randomSpeed = rand() % 2 + 1;
			{
				if (i % 2 == 0) {
					obs[i] = new Obstacle(2, i * 3 + 2, 2, randomSpeed, '>');
				}
				else {
					obs[i] = new Obstacle(width - 2, i * 3 + 2, 1, randomSpeed, '<');
				}
			}
		}

	}
	~GameManager() {
		delete player, obs;
	}
	void Reset() {
		score = 0;
		gameOver = false;
		player->Reset();
		for (int t = 0; t < 10; t++) {
			obs[t]->Reset();
		}
	}
	void CheckInput() {
		if (_kbhit()) {
			char current = _getch();
			if (current == 'w' || current == 'W') {
				player->setDirection(3);
			}
			else if (current == 's' || current == 'S') {
				if (player->getPivotPosY() < height - 3) player->setDirection(4);
			}
			else if (current == 'a' || current == 'A') {
				player->setDirection(1);
			}
			else if (current == 'd' || current == 'D') {
				player->setDirection(2);
			}
		}
		else player->setDirection(0);
	}
	void scoreUp() {
		score += 100;
		//set->TextColor(14);
		set->gotoxy(width / 2 - 8, height / 2);
		cout << "100점 획득!";
		Beep(1200, 100);
		Sleep(1000);
		player->Reset();
	}
	void Logic() {
		player->Move();
		for (int t = 0; t < 10; t++) {
			obs[t]->Move();
		}
		if (player->getPivotPosY() < 2) {
			scoreUp();
		}
	}
	void Draw() {
		set->gotoxy(0, 0);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				bool isPrinted = false;
				bool playerPrinted = false;
				if (y == 0 || y == height - 1) {
					//set->TextColor(1);
					cout << '#';
					isPrinted = true;
					//set->TextColor(0);
				}
				if (!isPrinted) {
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							if (y == player->bodyPos[i][j].y && x == player->bodyPos[i][j].x) {
								//set->TextColor(14);
								cout << '^';
								isPrinted = true;
								playerPrinted = true;
								//set->TextColor(0);
							}
						}
					}
				}
				for (int t = 0; t < 10; t++) {
					for (int u = 0; u < 3; u++) {
						for (int v = 0; v < 3; v++) {
							if (y == obs[t]->bodyPos[u][v].y && x == obs[t]->bodyPos[u][v].x) {
								if (!playerPrinted) {
									//if (enemy[t]->getBodyChar() == '>'); set->TextColor(11);
									//else set->TextColor(10);
									cout << obs[t]->getBodyChar();
									isPrinted = true;
									//set->TextColor(0);
								}
								else gameOver = true;
							}
						}
					}
				}
				if (!isPrinted) cout << ' ';
			}
			cout << endl;
		}
		//set->TextColor(15);
		set->gotoxy(width / 2 - 8, height);
		cout << "점수: " << score;
		//set->TextColor(0); set->TextColor(10);
		set->gotoxy(width / 2 - 16, height + 1);
		cout << "건국대 살려조_일감호를 건너라";
	}
	void Run() {
	play:
		while (!gameOver) {
			CheckInput();
			Logic();
			Draw();
		}
		GameOver();
		goto play;
	}
	void GameOver() {
		set->gotoxy(width / 2 - 8, height / 2);
		//set->TextColor(12);
		cout << "게임 오버 ㅠ_ㅠ" << endl;
		Beep(300, 500);
		set->gotoxy(width / 2 - 13, height / 2 + 1);
		cout << "획득한 총 점수는 " << score << "점 입니다.\n";
		if (score == 0) {
			set->gotoxy(width / 2 - 3, height / 2 + 2); cout << "F학점!!" << endl;
		}
		else if (score > 0 && score <= 200) {
			set->gotoxy(width / 2 - 3, height / 2 + 2); cout << "D학점!!" << endl;
		}
		else if (score > 200 && score <= 400) {
			set->gotoxy(width / 2 - 3, height / 2 + 2); cout << "C학점!!" << endl;
		}
		else if (score > 400 && score <= 600) {
			set->gotoxy(width / 2 - 3, height / 2 + 2); cout << "B학점!!" << endl;
		}
		else {
			set->gotoxy(width / 2 - 3, height / 2 + 2); cout << "A학점!!" << endl;
		}
		system("pause");
		exit(0);
	}
};
int Ilgamlake() {
	Setting* sett = new Setting();
	sett->SetConsoleSize(520, 640);
	GameManager GM(screenHeight, screenWidth);
	GM.Run();
	return 0;
}