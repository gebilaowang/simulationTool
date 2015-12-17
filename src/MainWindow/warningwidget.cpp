#include "warningwidget.h"
#include <QHBoxLayout>
#include <QTextEdit>
#include <QTableWidget>

WarningWidget::WarningWidget(QDockWidget *parent) :
    QDockWidget(parent)
{
    createUI();
}

WarningWidget::~WarningWidget()
{

}

void WarningWidget::createUI()
{
    tabWidget =new QTabWidget;
    issueWidget=new IssueWidget;

    tabWidget->addTab(issueWidget,"Issues");

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(tabWidget);

    setLayout(layout);
}


IssueWidget::IssueWidget()
{
    createUI();
}

IssueWidget::~IssueWidget()
{

}

void IssueWidget::createUI()
{
    textEdit=new QTextEdit;

    textEdit->setText("456789567895678756789rtghyjutyu");

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(textEdit);

    setLayout(layout);
}
