#pragma once
#include<windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include"SystemEvent.h"

using namespace std;

struct UserData {
	string name;
	int score;
	int grade;
};

class RankingView
{
private:
	string filePath;
	vector<UserData> userdata;
	string tmpUsername;
	int tmpScore;
	int tmpGrade;

public:
	RankingView();
	~RankingView();
	void showRankingView();
	void rankingViewFrame();
	void addGameResult(string name, int score, int grade);
	void showResultPage();

private:
	void readRankingFile();
	void bubbleSort();
	void writeRankingFile(UserData tmpData);
	void getUserScore();
};

