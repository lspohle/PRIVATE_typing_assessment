#include <iostream>
#include <fstream>
#include <time.h>

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\e[38;5;227m"
#define CYAN "\e[38;5;44;1m"
#define MAGENTA	"\033[1;35m"
#define WHITE "\033[4;37m"
#define ESCAPE "\033[0m"

class Assessment {
private:
	std::fstream file;
	std::string filename;
	std::string fileLine;
	std::string userLine;
	double errors;
	unsigned int characters;
public:
	// Constructor
	Assessment();
	bool openFile();
	void printPromptToType();
	void examineLineByLine(Assessment& typing);
	void getUserLineAndFileLine();
	void compareUserLineWithFileLine();
	void printFinalStats(unsigned int time);
	// Destructor
	~Assessment();
};