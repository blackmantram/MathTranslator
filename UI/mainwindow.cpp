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
    /*return expression;*/
    return QString("a a la dos más b a la dos igual a c a la dos");
}

bool MainWindow::hasExponential(QString expression) {
    return expression.toStdString().find("^") != string::npos;
}

void MainWindow::speak(QString text)
{
    std::string stdString = "eSpeak -v es \""+text.toStdString()+"\"";
    system(stdString.c_str());
}

void MainWindow::on_pushButton_clicked()
{
    QString code = ui->lineEdit->text();
    QString translatedText = translate(code);
    ui->textEdit->setPlainText(translatedText);
    speak(translatedText);
}
