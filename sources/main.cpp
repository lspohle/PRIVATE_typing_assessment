#include "assessment.hpp"

int main() {
	Assessment typing;

	if(!typing.openFile())
		return 1;
	typing.promptUserToType();
	typing.examineLineByLine(typing);
	return 0;
}
