#pragma once
#include <QtWidgets>
#include"_basic.h"
class BAWindow: 
	public QWidget
{
public:
	BAWindow(QWidget* parent = nullptr);
	void BankAlgorithm(vector<vector<int>>& Need, vector<vector<int>>& allocation, vector<int>& nowR,int needid, vector<int>& apply);

	QTextBrowser* tb;
};
