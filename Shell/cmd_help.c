
#include "cmd_help.h"

#ifdef _WIN64
void cmd_help(char** input) {
	if (!strcmp(input[1], "help")) {
		int idx = 0, err = 0;
		idx = sprintf_s(input[0], CLSIZE, "C:\\Windows\\System32\\%s.exe", input[1]);
		if ((err = _access_s(input[0], F_OK)) == 0) {
			idx += sprintf_s(input[0] + idx, (size_t)CLSIZE - idx, " %s", input[2]);
			system(input[0]);
		}
		else printf("Windows Help not found.\n\n");
		memset(input[0], 0, idx);
		printf("\n");
	}
	return;
}
#endif

#ifdef __linux__
void cmd_help(char** input) {
	if (!strcmp(input[1], "help")) {
		int idx = 0, err = 0;
		idx = snprintf(input[0], CLSIZE, "/bin/bash");
		if ((err = access(input[0], F_OK)) == 0) {
			idx += snprintf(input[0] + idx, (size_t)CLSIZE - idx, " -c %s %s", input[1], input[2]);
			system(input[0]);
		}
		else printf("GUN bash not found.\n\n");
		memset(input[0], 0, idx);
		printf("\n");
	}
	return;
}
#endif
