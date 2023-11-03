#include "assessment.hpp"

int main() {
	Assessment typing;

	if(!typing.openFile())
		return 1;

	typing.printPromptToType();

	time_t start, finish;
	time(&start);
	typing.examineLineByLine(typing);
	time(&finish);
	
	typing.printFinalStats(difftime(finish, start));
	return 0;
}
