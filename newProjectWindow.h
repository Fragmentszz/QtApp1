#pragma once

#include <QtWidgets>

class PopupDialog : public QDialog {
public:
    PopupDialog(QWidget* parent = nullptr);
    std::pair<int,int> getResult() const;

private:
    int rowcount, columncount;
};
