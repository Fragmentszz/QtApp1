#pragma once
#include"_basic.h"
class QTtry1;
class MyTable :
	public QTableWidget
{
    friend class QTtry1;
public:
    MyTable(QWidget* parent = nullptr);
    ~MyTable();

public:
    std::vector<std::vector<int>> tb;
    void initTable(pair<int,int> size);
private slots:
    void newProject();
    void fillAllBlank();
    void fillAll();
    void bindtb(QTableWidgetItem* item);
};