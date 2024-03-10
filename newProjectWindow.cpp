#include"newProjectWindow.h"

PopupDialog::PopupDialog(QWidget* parent) : QDialog(parent),rowcount(0),columncount(0)
{
    setWindowTitle("新建项目");
    // 创建布局
    QVBoxLayout* layout = new QVBoxLayout(this);

    // 创建图片
    QLabel* imageLabel = new QLabel(this);
    QPixmap pixmap("image.jpg");  // 图片路径
    imageLabel->setPixmap(pixmap);
    layout->addWidget(imageLabel);

    // 创建文字
    QLabel* textLabel = new QLabel("资源数:", this);
    layout->addWidget(textLabel);
    // 创建选项框_column
    QLineEdit* inputLineEdit_column = new QLineEdit(this);
    layout->addWidget(inputLineEdit_column);
    layout->addWidget(inputLineEdit_column);


    // 创建文字
    QLabel* textLabel2 = new QLabel("进程数:", this);
    layout->addWidget(textLabel2);
    // 创建输入框_row
    QLineEdit* inputLineEdit_row = new QLineEdit(this);
    layout->addWidget(inputLineEdit_row);

    

    // 创建按钮
    QPushButton* okButton = new QPushButton("确定", this);
    connect(okButton, &QPushButton::clicked, [this, inputLineEdit_row, inputLineEdit_column]() {
        QString inputText_row = inputLineEdit_row->text();
        QString inputText_column = inputLineEdit_column->text();
        // 根据输入框的内容和选项来修改变量a的值
        // 这里只是一个简单示例，可以根据业务逻辑进行具体实现
            if (1){                                                             //判断纯数字
                rowcount = inputText_row.toInt();
                columncount = inputText_column.toInt();
                // 关闭弹窗
                accept();
            }
        });
    layout->addWidget(okButton);

    setLayout(layout);
}

std::pair<int,int> PopupDialog::getResult() const {
    return {rowcount,columncount};
}