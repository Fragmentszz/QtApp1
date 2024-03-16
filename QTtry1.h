#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTtry1.h"
#include<QTableWidget>
#include"newProjectWindow.h"
#include"MyTable.h"
#include"BAWindow.h"

class QTtry1 : public QMainWindow
{
    Q_OBJECT
public:
    QTtry1(QWidget *parent = nullptr);
    ~QTtry1();

public:
    Ui::QTtry1Class ui;
    QLabel* lab;

    std::vector<std::vector<int>> tb;
    MyTable *t_now, *t_process, *t_nowR, *t_apply;
    AllocationTable* t_allocation;
    void initTable(pair<int,int> result);
    BAWindow* baw;
private slots:
    void newProject();
    void runBA();
    //void requestEmpty();
    void tabChange();
    void allocationChange(QTableWidgetItem* item);
    //void fillAllBlank();
    //void fillAll();
    //void bindtb(QTableWidgetItem* item);
    //void fillNow();
};
