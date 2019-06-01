#include "RankingView.h"

RankingView::RankingView()
{
}


RankingView::~RankingView()
{
}

void RankingView::showRankingView()
{
	//�ܼ�â �����
	system("cls");
	readRankingFile();
	rankingViewFrame();
}

void RankingView::rankingViewFrame()
{
	printf("\n\n\n\n");
	cout << "______                _     _" << endl;
	cout << "| ___                | |   (_)" << endl;
	cout << "| |_/ /  __ _  _ __  | | __ _  _ __    __ _" << endl;
	cout << "|    /  / _` || '_   | |/ /| || '_    / _` |" << endl;
	cout << "| |  | (_| | || | | ||   < | || | | |(_| |"<<endl;
	cout << "|_| |_| |__,_||_| |_||_| _||_||_| |_|  __, |" << endl;
	cout << "                                       __/ |" << endl;
	cout << "                                      |___/" << endl;

	printf("======================================================================================\n");
	printf("||%3s %10s %30s %30s          ||\n","����", "�̸�", "����", "����"); //����10ĭ
	printf("======================================================================================\n");

	//������ ���¿� ����
	for (int i = 0; i < userdata.size(); i++) {
		printf("||%3d %10s %29d %29d            ||\n", i+1, (userdata.at(i).name).c_str(), userdata.at(i).score, userdata.at(i).grade); //���� 12ĭ
		Sleep(200); //���� ������ �� �̤���
	}
	printf("======================================================================================\n");
}

void RankingView::getGameResult(string name, int score, int grade)
{
}

//������ �о userdata ���ͺ����� ����
void RankingView::readRankingFile()
{
	fstream file;
	char ch[100];
	char *context;
	string line;
	UserData tmpdata;
	file.open("Ranking.csv");
	if (file.fail()) {
		cout << "cannot found ranking fild" << endl;
		exit(0);
	}

	//Ÿ��Ʋ�κ� ����
	getline(file, line, '\n');
	//���δ����� �о �ӽ÷� line�� ����
	while (getline(file, line, '\n')) {
		//string to char >> stringd�� charŸ�Ժ����� ����
		//strtok�� ���ؼ�
		strcpy_s(ch, sizeof(ch), line.c_str());

		char *tok = strtok_s(ch, ",", &context);
		tmpdata.name = tok;
		tok = strtok_s(NULL, ",", &context);
		tmpdata.score = atoi(tok);
		tok = strtok_s(NULL, ",", &context);
		tmpdata.grade = atoi(tok);

		userdata.push_back(tmpdata);
		
	}

	file.close();
}

void RankingView::bubbleSort()
{
	for (int i = 0; i < userdata.size(); i++) {

	}
}
