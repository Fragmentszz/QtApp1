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
                //tb[i][j] = rd;
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
            //tb[i][j] = rd;
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
}





MyTable::~MyTable()
{

}
