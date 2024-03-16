﻿#include"BAWindow.h"
#include<sstream>

BAWindow::BAWindow(QWidget* parent):QWidget(parent)
{
	this->setWindowTitle("银行家算法执行结果");
	this->setGeometry(360, 270, 720, 540);
	tb = new QTextBrowser(this);
	tb->setText("empty!");
}

typedef vector<int> VI;
static VI operator-(const VI& a, const VI& b)
{
	VI res;
	for (int i = 0; i < a.size(); i++)
	{
		res.push_back(a[i] - b[i]);
	}
	return res;
}
static VI operator+(const VI& a, const VI& b)
{
	VI res;
	for (int i = 0; i < a.size(); i++)
	{
		res.push_back(a[i] + b[i]);
	}
	return res;
}
static bool operator<=(const VI& a, const VI& b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > b[i])	return 0;
	}
	return 1;
}

vector<vector<int>> dneed;
vector<int> dwork;
vector<int> dflag;
vector<vector<int>> dallocation;
vector<vector<int>> dpaths;
vector<int> dpath;
void bankAlgorithm(int now)							//内部使用
{
	int n = dneed.size(), m = dwork.size();
	if (now == n) {
		dpaths.push_back(dpath);
	}
	for (int i = 0; i < n; i++)
	{
		if (dneed[i] <= dwork && dflag[i] == 0)
		{
			dflag[i] = 1;
			dwork = dwork + dallocation[i];
			dpath[now] = i;
			bankAlgorithm(now + 1);
			dflag[i] = 0;
			dwork = dwork - dallocation[i];
		}
	}
}


void BAWindow::BankAlgorithm(vector<vector<int>>& Need, vector<vector<int>>& allocation, vector<int>& nowR, int needid, vector<int>& apply)
{
	int n = Need.size(),m = apply.size();
	for (int j = 0; j < m; j++)
	{
		if (apply[j] + allocation[needid][j] > Need[needid][j])
		{
			tb->setText("请求资源超过进程总请求");
			cout << "请求资源超过进程总请求" << endl;
			;							//请求资源超过进程总请求
		}
		else if (apply[j] > nowR[j]) {
			tb->setText("请求资源超过现有资源");
			cout << "请求资源超过现有资源" << endl;
			;							//请求资源超过现有
		}
	}
	//vector<vector<int>> hneed;
	dneed.resize(n);
	for (int i = 0; i < n; i++)
	{
		dneed[i].resize(m);
		for (int j = 0; j < m; j++)
		{
			dneed[i][j] = Need[i][j] - allocation[i][j];
		}
	}
	vector<int> work = nowR;
	work = work - apply;
	allocation[needid] = allocation[needid] + apply;

	dneed[needid] = dneed[needid] - apply;
	dallocation = allocation;
	dflag = vector<int>(n, 0);
	dwork = work;
	dpaths.clear();
	dpath.resize(n);
	bankAlgorithm(0);


	if (dpaths.empty()) {
		tb->setText("不能响应请求！");
		cout << "不能响应请求！" << endl;
	}
	else {
		stringstream ss;
		ss << dpaths.size() << endl;
		for (VI vi : dpaths) {
			for (int t : vi) {
				ss << t << " ";
			}
			ss << endl;
		}
		string s = stringFromSS(ss);
		tb->setText(QString::fromStdString(s));
	}
}