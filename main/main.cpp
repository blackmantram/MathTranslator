#include <iostream>
#include <string>
#include "translator.h"
using namespace std;

int main(int argc, char *argv[])
{
	Translator translator;
	string translation = translator.translate(argv[1]);
    cout << translation << endl;
}
