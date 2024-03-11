#include "QTtry1.h"
#include"_basic.h"

QTtry1::QTtry1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    t_now = new MyTable(this->ui.MaxAndNeed);
    t_process = new MyTable(this->ui.MaxAndNeed);

    t_allocation = new MyTable(this->ui.Allocation);
    t_nowR = new MyTable(this->ui.Allocation);
    t_apply = new MyTable(this->ui.Allocation);

    t_process->setGeometry(0, 30, 1440, 700);
    t_now->setGeometry(0, 760, 1440, 60);

    t_allocation->setGeometry(0, 30, 1440, 700);
    t_nowR->setGeometry(0, 750, 1440, 60);
    t_apply->setGeometry(0, 830, 1440, 60);

    connect(ui.newProject, &QAction::triggered, this, &QTtry1::newProject);

    connect(ui.fillAll, &QAction::triggered, t_process, &MyTable::fillAll);
    connect(ui.fillAll, &QAction::triggered, t_now, &MyTable::fillAll);

    connect(ui.run, &QAction::triggered, this, &QTtry1::runBA);                                     //运行银行家算法

    connect(ui.fillAll1, &QAction::triggered, t_process, &MyTable::fillAll);                        //随机生成所有
    connect(ui.fillAllBlank1, &QAction::triggered, t_process, &MyTable::fillAllBlank);              //随机填充空白
    connect(ui.createBProcess, &QAction::triggered, t_process, &MyTable::addRow);                   //添加空白进程
    connect(ui.createRProcess, &QAction::triggered, t_process, &MyTable::addRow_r);                 //添加空白进程
    connect(ui.newResource, &QAction::triggered, t_process, &MyTable::addColumn);                   //添加资源

    connect(ui.fillAll2, &QAction::triggered, t_now, &MyTable::fillAll);                            //随机生成所有现有资源
    connect(ui.fillAllBlank2, &QAction::triggered, t_now, &MyTable::fillAllBlank);                  //随机填充空白现有资源
    connect(ui.newResource, &QAction::triggered, t_now, &MyTable::addColumn);                       //添加资源

    initTable({ 3, 3 });

    connect(ui.tabWidget, &QTabWidget::currentChanged, this, &QTtry1::tabChange);                   //更换页面

    baw = new BAWindow();
    baw->hide();
    this->ui.tabWidget->setCurrentIndex(0);
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
    t_process->clearContents();
    t_now->clearContents();
    
    
    t_process->initTable(result);
    t_now->initTable({1, result.second });
}

void QTtry1::runBA()
{
    baw->show();
}

void QTtry1::tabChange()
{
    if (ui.tabWidget->currentIndex() == 0)   return;
    if (t_process->hasEmpty())
    {
        ui.tabWidget->setCurrentIndex(0);
        auto critical  = QMessageBox::critical(this, "初始化错误", "进程需求资源量有空值未填！");
    }
    else if (t_now->hasEmpty())
    {
        ui.tabWidget->setCurrentIndex(0);
        auto critical = QMessageBox::critical(this, "初始化错误", "资源最大量有空值未填！");
    }
    else
    {
        //t_allocation->clear();
        t_allocation->initTable({ t_process->rowCount(),t_process->columnCount() });

        //t_nowR->clear();
        t_nowR->initTable({ 1,t_process->columnCount() });

        //t_apply->clear();
        t_apply->initTable({ 1,t_process->columnCount() });
    }
}


QTtry1::~QTtry1()
{
    
}
