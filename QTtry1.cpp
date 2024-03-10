#include "QTtry1.h"
#include"_basic.h"

QTtry1::QTtry1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    t_now = new MyTable(this);
    t_process = new MyTable(this);
    t_process->setGeometry(100, 100, 1440, 700);
    t_now->setGeometry(0, 800, 1440, 100);

    connect(ui.newProject, &QAction::triggered, this, &QTtry1::newProject);
    QObject::connect(ui.fillNow, &QAction::triggered, t_now, &MyTable::fillAllBlank);
    QObject::connect(ui.fillAllBlank, &QAction::triggered, t_process, &MyTable::fillAllBlank);
    connect(ui.fillAll, &QAction::triggered, t_now, &MyTable::fillAll);
    connect(ui.fillAll, &QAction::triggered, t_process, &MyTable::fillAll);
    //connect(ui.tableWidget, &QTableWidget::itemChanged, this, &QTtry1::bindtb);
    initTable({ 3, 3 });
}


void QTtry1::newProject()           //新项目
{
    PopupDialog pw(this);
    // 显示弹窗，并等待弹窗关闭
    if (pw.exec() == QDialog::Accepted) {                      // 返回回调
        // 获取弹窗中的变量a的值
        auto result = pw.getResult();
        initTable(result);   
    }

}
void QTtry1::initTable(pair<int,int> result)
{
    QStringList header_column;
    QStringList header_row;
    tb.resize(result.first + 1);
    for (int i = 0; i < result.second; i++) {
        QString s = "资源";
        s.append(N2S(i + 1));
        header_column << s;
    }
    for (int i = 0; i < result.first; i++) {
        QString s = "进程";
        s.append(N2S(i + 1));
        tb[i].resize(result.second + 1);
        header_row << s;
    }
    t_process->initTable(result);
    t_process->setHorizontalHeaderLabels(header_column);
    t_process->setVerticalHeaderLabels(header_row);

    t_now->initTable({1, result.second });
    t_now->setHorizontalHeaderLabels(header_column);
}


//void QTtry1::fillAllBlank()         //填充全部空白
//{
//    QTableWidget* table = ui.tableWidget;
//    for (int i = 0; i < table->rowCount(); i++)
//    {
//        for (int j = 0; j < table->columnCount(); j++)
//        {
//            if (table->item(i, j) == nullptr)
//            {
//                int rd = randint(0, 100);
//                //tb[i][j] = rd;
//                table->setItem(i, j, new QTableWidgetItem(N2S(rd)));
//            }
//        }
//    }
//}
//
//
//
//void QTtry1::fillAll()          //填充全部
//{
//    QTableWidget* table = ui.tableWidget;
//    for (int i = 0; i < table->rowCount(); i++)
//    {
//        for (int j = 0; j < table->columnCount(); j++)
//        {
//            int rd = randint(0, 100);
//            //tb[i][j] = rd;
//            table->setItem(i, j, new QTableWidgetItem(N2S(rd)));
//        }
//    }
//    for (int i = 0; i < table->rowCount(); i++)
//    {
//        for (int j = 0; j < table->columnCount(); j++)
//        {
//            cout << tb[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//void QTtry1::bindtb(QTableWidgetItem* item)
//{
//    int i = item->row(), j = item->column();
//    tb[i][j] = S2N(item->text());
//}











QTtry1::~QTtry1()
{
    
}
