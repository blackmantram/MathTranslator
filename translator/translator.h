#include <string>

class Translator
{
public:
	Translator();
	std::string translate(std::string);
private:
	bool hasExponential(std::string);
};