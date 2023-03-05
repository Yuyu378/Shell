
#include "wcmd_time.h"

void time(char** input) {
	if (!strcmp(input[1], "time")) {
		int idx = 0;
		idx = sprintf_s(input[0], CLSIZE, "echo %%%s%%", input[1]);
		system(input[0]);
		memset(input[0], 0, idx);
		printf("\n");
	}
	return;
}