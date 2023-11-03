#include "assessment.hpp"

Assessment::Assessment() {
	std::string filename;
	filename = "file.txt";
	this->filename = filename;
	errors = 0;
	characters = 0;
}

bool Assessment::openFile() {
	this->file.open(this->filename, std::ios::in);
	if(!this->file) {
		std::cerr << "Experienced an error trying to open the file\n";
		return false;
	}
	return true;
}

void Assessment::printPromptToType() {
	std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
	std::cout << "║" << CYAN << "           Challenge your typing skills 😎            " << ESCAPE << "║\n";
	std::cout << "╚══════════════════════════════════════════════════════╝";
}

void Assessment::examineLineByLine(Assessment& typing) {
	while(!this->file.eof()) {
		typing.getUserLineAndFileLine();
		typing.compareUserLineWithFileLine();
	}
	this->file.close();
}

void Assessment::getUserLineAndFileLine() {
	std::cout << std::endl << std::endl;
	std::getline(this->file, this->fileLine);
	characters += this->fileLine.length();
	std::cout << YELLOW << this->fileLine << ESCAPE << std::endl;
	std::getline(std::cin, this->userLine);
}

void Assessment::compareUserLineWithFileLine() {
	for(int i = 0; this->fileLine[i] != '\0' && this->userLine[i] != '\0'; i++) {
		if(this->fileLine[i] == this->userLine[i]) {
			std::cout << GREEN << this->userLine[i] << ESCAPE;
		}
		else {
			std::cout << RED << this->userLine[i] << ESCAPE;
			++errors;
		}
	}
}

void Assessment::printFinalStats(unsigned int time) {
	std::cout << "\n\n╔══════════════════════════════════════════════════════╗\n";
	std::cout << "║" << CYAN << "               Check out your stats 🥳                " << ESCAPE "║\n";
	std::cout << "╚══════════════════════════════════════════════════════╝\n\n";

	std::cout << WHITE << "Time:		" << ESCAPE << MAGENTA << time/60;
	time%60 < 10 ? std::cout << ".0" : std::cout << ".";
	std::cout << time%60 << " minutes\n" << ESCAPE;
	std::cout << WHITE << "Characters:	" << ESCAPE << YELLOW << characters << " characters\n" << ESCAPE;
	std::cout << WHITE << "Errors:		" << ESCAPE << RED << errors << " errors\n" << ESCAPE;
	std::cout << WHITE << "Your Score:	" << ESCAPE << GREEN << time*3 + errors << " points\n\n" << ESCAPE;
}

Assessment::~Assessment() {
}
