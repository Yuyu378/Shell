
#include "wcmd_hostname.h"

void hostname(char** input) {
	if (!strcmp(input[1], "hostname")) {
		int idx = 0, err = 0;
		idx = sprintf_s(input[0], CLSIZE, "C:\\Windows\\System32\\%s.exe", input[1]);
		if ((err = _access_s(input[0], 0)) == 0) {
			idx += sprintf_s(input[0] + idx, (size_t)CLSIZE - idx, " %s", input[2]);
			system(input[0]);
		}
		else printf("Hostname not found.\n\n");
		memset(input[0], 0, idx);
		printf("\n");
	}
	return;
}
