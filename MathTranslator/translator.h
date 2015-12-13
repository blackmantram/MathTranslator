#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>

class Translator
{
public:
    Translator();
    std::string translate(std::string);
private:
    bool hasExponential(std::string);
};

#endif // TRANSLATOR_H
