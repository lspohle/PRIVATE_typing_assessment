#include "assessment.hpp"

Assessment::Assessment() {
	std::string filename;
	filename = "file.txt";
	this->filename = filename;
}

bool Assessment::openFile() {
	this->file.open(this->filename, std::ios::in);
	if(!this->file) {
		std::cerr << "Experienced an error trying to open the file\n";
		return false;
	}
	return true;
}

void Assessment::promptUserToType() {
	std::cout << WHITE << "\n╔══════════════════════════════════════════════════════╗\n" << ESCAPE;
	std::cout << WHITE << "║" << CYAN << "           Challenge your typing skills 😎            " << WHITE << "║\n" << ESCAPE;
	std::cout << WHITE << "╚══════════════════════════════════════════════════════╝\n\n" << ESCAPE;
}

void Assessment::examineLineByLine(Assessment& typing) {
	while(!this->file.eof()) {
		typing.compareUserLineWithFileLine();
	}
	this->file.close();
}

void Assessment::compareUserLineWithFileLine() {
	std::getline(this->file, this->fileLine);
	std::cout << YELLOW << this->fileLine << ESCAPE << std::endl;
	std::getline(std::cin, this->userLine);
	for(int i = 0; this->fileLine[i] != '\0' && this->userLine[i] != '\0'; i++) {
		if(this->fileLine[i] == this->userLine[i]) {
			std::cout << GREEN << this->userLine[i] << ESCAPE;
		}
		else {
			std::cout << RED << this->userLine[i] << ESCAPE;
		}
	}
	std::cout << std::endl << std::endl;
}

Assessment::~Assessment() {
}
