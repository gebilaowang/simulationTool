#ifndef WARNINGWIDGET_H
#define WARNINGWIDGET_H

#include <QWidget>
#include <QDockWidget>

class IssueWidget;
class QTextEdit;
class QTabWidget;
class WarningWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WarningWidget(QWidget *parent = 0);
    ~WarningWidget();
private:
    void createUI();
private:
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    IssueWidget *issueWidget;
};

class IssueWidget:public QWidget
{
    Q_OBJECT
public:
    IssueWidget();
    ~IssueWidget();

private:
    void createUI();
private:
    QTextEdit *textEdit;
};

#endif // WARNINGWIDGET_H
