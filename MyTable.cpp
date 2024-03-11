#include"MyTable.h"



MyTable::MyTable(QWidget* parent)
    :QTableWidget(parent)
{
    
    connect(this, &QTableWidget::itemChanged, this, &MyTable::bindtb);
}
void MyTable::fillAllBlank()         //填充全部空白
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        for (int j = 0; j < this->columnCount(); j++)
        {
            if (this->item(i, j) == nullptr)
            {
                int rd = randint(0, 100);
                this->setItem(i, j, new QTableWidgetItem(N2S(rd)));
            }
        }
    }
}

void MyTable::fillAll()          //填充全部
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        for (int j = 0; j < this->columnCount(); j++)
        {
            int rd = randint(0, 100);
            this->setItem(i, j, new QTableWidgetItem(N2S(rd)));
        }
    }
    for (int i = 0; i < this->rowCount(); i++)
    {
        for (int j = 0; j < this->columnCount(); j++)
        {
            cout << tb[i][j] << " ";
        }
        cout << endl;
    }
}

void MyTable::bindtb(QTableWidgetItem* item)
{
    int i = item->row(), j = item->column();
    tb[i][j] = S2N(item->text());
}

void MyTable::initTable(pair<int, int> result)
{
    tb.resize(result.first + 1);
    for (int i = 0; i < result.first; i++) {
        tb[i].resize(result.second + 1);
    }
    this->setRowCount(result.first);
    this->setColumnCount(result.second);
    QStringList header_column;
    QStringList header_row;
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
    this->setHorizontalHeaderLabels(header_column);
    this->setVerticalHeaderLabels(header_row);
}


void MyTable::addRow()
{
    int nowrow = this->rowCount();
    tb.resize(++nowrow + 1);
    tb[nowrow - 1].resize(this->columnCount());
    QString s = "进程";
    s.append(N2S(nowrow));
    this->setRowCount(nowrow);
    auto tmpItem = new QTableWidgetItem(s);
    this->setVerticalHeaderItem(nowrow - 1, tmpItem);
}


void MyTable::addRow_r()
{
    addRow();
    int nowrow = this->rowCount();
    for (int j = 0; j < this->columnCount(); j++)
    {
        int rd = randint(0, 100);
        this->setItem(nowrow-1, j, new QTableWidgetItem(N2S(rd)));
    }
}

void MyTable::addColumn()
{
    int nowcolumn = this->columnCount();
    nowcolumn++;
    for (int i = 0; i < tb.size(); i++){
        tb[i].resize(nowcolumn + 1);
    }
    QString s = "资源";
    s.append(N2S(nowcolumn));
    this->setColumnCount(nowcolumn);
    auto tmpItem = new QTableWidgetItem(s);
    this->setHorizontalHeaderItem(nowcolumn - 1, tmpItem);
}
bool MyTable::hasEmpty()    const
{
    for (int i = 0; i < this->rowCount(); i++)
    {
        for (int j = 0; j < this->columnCount(); j++)
        {
            if (this->item(i, j) == nullptr)
            {
                return 1;
            }
        }
    }
    return 0;
}
MyTable::~MyTable()
{

}
