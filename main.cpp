#include "QTtry1.h"
#include<iostream>
#include<QLabel>
#include<qscreen.h>
#include <QtWidgets/QApplication>
#include<sstream>


int main(int argc, char *argv[])
{
    using namespace std;
    QApplication a(argc, argv);
    QTtry1 w;
    w.setWindowTitle("你是谁");
    //w.setGeometry(0, 0, 1440, 960);
    w.setWindowState(Qt::WindowMaximized);
    QLabel lab(&w);
    lab.setGeometry(0, 300, 100, 100);
    std::stringstream ss;
    string str;
    getline(ss, str);
    QString s1;
    s1.append(str);
    lab.setText(s1);

    w.lab = &lab;
    
    w.show();


    
    return a.exec();
}

// 从excel导入
// 创建空白进程
// 新建资源列
// 随机填充空白数据
// 随机生成新进程
// 加入新资源

// 随机生成初始数据
// 执行银行家算法