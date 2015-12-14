#include <QString>
#include <QStringList>
#include "translator.h"
#include "iostream"
#include "stdio.h"

QString Translator::translate(QString expression)
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

bool Translator::hasExponential(QString expression) {
    return expression.toStdString().find("^") != std::string::npos;
}

void Translator::speak(QString text)
{
    std::string stdString = "eSpeak -v es \""+text.toStdString()+"\"";
    system(stdString.c_str());
}
