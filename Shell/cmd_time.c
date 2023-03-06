
#include "cmd_time.h"

#ifdef _WIN64
void cmd_time(char** input) {
	if (!strcmp(input[1], "time")) {
		system("echo %time%");
		printf("\n");
	}
	return;
}
#endif

#ifdef __linux__
void cmd_time(char** input) {
	if (!(strcmp(input[1], "time"))) {
		system("date +\"%T.%2N\"");
		printf("\n");
	}
	return;
}
#endif
