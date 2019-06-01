#include "RankingView.h"

RankingView::RankingView()
{
}


RankingView::~RankingView()
{
}

void RankingView::showRankingView()
{
	//콘솔창 지우기
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
	printf("||%3s %10s %30s %30s          ||\n","순위", "이름", "점수", "학점"); //공백10칸
	printf("======================================================================================\n");

	//정해진 형태에 맞춰
	for (int i = 0; i < userdata.size(); i++) {
		printf("||%3d %10s %29d %29d            ||\n", i+1, (userdata.at(i).name).c_str(), userdata.at(i).score, userdata.at(i).grade); //공백 12칸
		Sleep(200); //조금 느리게 ㅊ ㅜㄹ력
	}
	printf("======================================================================================\n");
}

void RankingView::getGameResult(string name, int score, int grade)
{
}

//파일을 읽어서 userdata 벡터변수에 저장
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

	//타이틀부분 제거
	getline(file, line, '\n');
	//라인단위로 읽어서 임시로 line에 ㅓ장
	while (getline(file, line, '\n')) {
		//string to char >> stringd르 char타입변수로 저장
		//strtok를 위해서
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
