#pragma once
#include<windows.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

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

public:
	RankingView();
	~RankingView();
	void showRankingView();
	void rankingViewFrame();
	void getGameResult(string name, int score, int grade);

private:
	void readRankingFile();
	void bubbleSort();
};

