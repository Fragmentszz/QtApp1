#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTtry1.h"
#include<QTableWidget>
#include"newProjectWindow.h"
#include"MyTable.h"


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
    MyTable *t_now, *t_process;
    void initTable(pair<int,int> result);
private slots:
    void newProject();




    //void fillAllBlank();
    //void fillAll();
    //void bindtb(QTableWidgetItem* item);
    //void fillNow();
};
