#include <QTextEdit>
#include <QHBoxLayout>

#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("backgroung-color:green");

    QTextEdit *textEdit=new QTextEdit;
QHBoxLayout *layout=new QHBoxLayout;
layout->addWidget(textEdit);

setLayout(layout);
}

CentralWidget::~CentralWidget()
{

}
