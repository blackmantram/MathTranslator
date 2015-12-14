#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "stdio.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::translate(QString expression)
{
    /*if (isEquation(expression))
    {
        QStringList expressions = expression.split('=');
        return QString(expressions[0]+" igual a "+expressions[1]);

        for(int i=0;i<expressions.count();i++)
        {
            QString expression = expressions[i];
        }
    }*/
    return translateExpression(expression);
}

QString MainWindow::translateExpression(QString expression)
{
    if (expression.trimmed().length() == 0)
        return QString("");
    if (hasExponential(expression))
    {
        QChar delimiter = '^';
        QStringList expresions = expression.split(delimiter);
        QString base = expresions[0];
        QString exponent = expresions[1];
        return QString(base+" a la "+exponent);
    }
    return expression;
}

bool MainWindow::hasExponential(QString expression) {
    return expression.count(QRegExp("([a-zA-Z0-9])\\^([a-zA-Z0-9])"));
}

bool MainWindow::isEquation(QString expression) {
    return expression.count(QRegExp("={1,1}"));
}

void MainWindow::speak(QString text)
{
    std::string stdString = "eSpeak -v es \""+text.toStdString()+"\"";
    //system(stdString.c_str());
}

void MainWindow::on_pushButton_clicked()
{
    QString code = ui->lineEdit->text();
    QString translatedText = translate(code);
    ui->textEdit->setPlainText(translatedText);
    speak(translatedText);
}
