#include <iostream>
#include <fstream>

#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define YELLOW "\e[38;5;227m"
#define CYAN "\e[38;5;44;1m"
#define WHITE "\033[1;37m"
#define ESCAPE "\033[0m"

class Assessment {
private:
	std::fstream file;
	std::string filename;
	std::string fileLine;
	std::string userLine;
public:
	// Constructor
	Assessment();
	bool openFile();
	void promptUserToType();
	void examineLineByLine(Assessment& typing);
	void compareUserLineWithFileLine();
	// Destructor
	~Assessment();
};