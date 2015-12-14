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
    QString translatedExpression("");
    QStringList expressions (expression);
    if (isEquation(expression))
    {
        expressions = expression.split('=');
    }
    for(int i=0;i<expressions.count();i++)
    {
        QString expression = expressions[i];
        translatedExpression += translateExpression(expression);
        if (i < expressions.count()-1)
            translatedExpression += QString(" igual a ");
    }
    return translatedExpression;
}

QString MainWindow::translateExpression(QString expression)
{
    if (containsMultipleExpressions(expression))
        return translateMultipleExpressions(expression);
    else
        return translateSingleExpression(expression);
}

QString MainWindow::translateSingleExpression(QString expression)
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

QString MainWindow::translateMultipleExpressions(QString expression)
{
    QString translatedExpressions ("");
    QStringList expressions = expression.split(QRegExp("\\+|\\-"));
    for(int i=0; i<expressions.count(); i++)
    {
        translatedExpressions += translateSingleExpression(expressions[i]);
        if (i < expressions.count()-1)
            translatedExpressions += QString(" más ");
    }
    return translatedExpressions;
}

bool MainWindow::hasExponential(QString expression) {
    return expression.count(QRegExp("([a-zA-Z0-9])\\^([a-zA-Z0-9])"));
}

bool MainWindow::isEquation(QString expression) {
    return expression.count(QRegExp("={1,1}"));
}

bool MainWindow::containsMultipleExpressions(QString expression) {
    return expression.count(QRegExp("\\+|\\-"));
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
