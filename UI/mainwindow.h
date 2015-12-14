#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString translate(QString expression);
    QString translateExpression(QString expression);
    QString translateSingleExpression(QString expression);
    QString translateMultipleExpressions(QString expression);
    bool hasExponential(QString expression);
    bool isEquation(QString expression);
    bool containsMultipleExpressions(QString expression);
    void speak(QString text);
};

#endif // MAINWINDOW_H
