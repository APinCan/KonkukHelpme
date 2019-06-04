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

	printf("=================================================================================\n");
	printf("||%3s %10s %25s %25s          ||\n","순위", "이름", "점수", "학점"); //공백10칸
	printf("=================================================================================\n");

	//정해진 형태에 맞춰
	for (int i = 0; i < userdata.size(); i++) {
		printf("||%3d %10s %24d %24d            ||\n", i+1, (userdata.at(i).name).c_str(), userdata.at(i).score, userdata.at(i).grade); //공백 12칸
		Sleep(200); //조금 느리게 ㅊ ㅜㄹ력
	}
	printf("=================================================================================\n");
}

//다른 클래스에서 ranking에 새로운 유저데이터 추가
void RankingView::addGameResult(string name, int score, int grade)
{
	UserData tmpData;
	
	tmpData.name = name;
	tmpData.score = score;
	tmpData.grade = grade;
	//csv파일에 넣기
	writeRankingFile(tmpData);
}

void RankingView::showResultPage()
{
	SystemEvent systemEvent;
	cout << "  _______   ______     ______    _______       _______      ___      .___  ___.  _______     __" << endl;
	cout << "/  _____| /  __   |   /  __  |  |       |     /  _____|    /   |     |   |/   | |   ____|   |  |" << endl;
	cout << "|  |  __  |  |  |  | |  |  |  | |  .--.  |   |  |  __     /  ^  |    |  |  /  | |  |__      |  |" << endl;
	cout << "|  | |_ | |  |  |  | |  |  |  | |  |  |  |   |  | |_ |   /  /_|  |   |  ||/|  | |   __|     |  |" << endl;
	cout << "|  |__| | |  `--'  | |  `--'  | |  '--'  |   |  |__| |  /  _____  |  |  |  |  | |  |____    |__|" << endl;
	cout << "|_______|._______./   |______/  |.________.  ________| /__/     |__| |__|  |__| |_______|   (__)" << endl;
	cout << "          __   __       ___       ___  ___   _______                                      \n\n\n" << endl;
	cout << "         |  | |  |     /   |     |   |/   | |   ____|" << endl;
	cout << "         |   ||  |    /  ^  |    |  |  /  | |  |__" << endl;
	cout << "         |  . `  |   /  /_|  |   |  ||/|  | |   __|" << endl;
	cout << "         |  ||   |  /  _____  |  |  |  |  | |  |____" << endl;
	cout << "         |__| |__| /__/     |__| |__|  |__| |_______|" << endl;

	systemEvent.cursorMoveXY(19, 10);
	cout << "> ";
	cin >> tmpUsername;

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
	bubbleSort();

	file.close();
}

void RankingView::bubbleSort()
{
	for (int i = 0; i < userdata.size()-1; i++) {
		for (int j = 0; j < userdata.size() - i-1; j++) {
			if (userdata.at(j).score<userdata.at(j+1).score) {
				UserData tmp = userdata.at(j);
				userdata.at(j) = userdata.at(j + 1);
				userdata.at(j + 1) = tmp;
			}
		}
	}
}

void RankingView::writeRankingFile(UserData tmpData)
{
	ofstream file;

	//쓰기 파일의 끝에 위치
	file.open("Ranking.csv", ios::out | ios::ate);
	if (file.fail()) {
		cout << "file open fail" << endl;
		exit(0);
	}

	file << tmpData.name << ", "
		<< tmpData.score << ", "
		<< tmpData.grade << ", "
		<< "\n";

	file.close();
}

void RankingView::getUserScore()
{
	UserData setuser;

	int sum = 0;
	/*
	sum+=userscore.첫번째게임
	sum+=userscore.두번째게임
	sum+=userscore.세번째게임
	int score=(int)(sum/3);

	//등급평가 코드

	setuser.name="";
	setuser.score=score;
	setuser.grade=;
	*/
	userdata.push_back(setuser);
	writeRankingFile(setuser);
}
