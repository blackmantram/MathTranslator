#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "translator_global.h"

class TRANSLATORSHARED_EXPORT Translator
{

public:
    Translator();
private:
    QString translate(QString expression);
    bool hasExponential(QString expression);
    void speak(QString text);
};

#endif // TRANSLATOR_H
