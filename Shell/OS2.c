// 
// OS2.c
// 
//		Main file
// 

#include <stdio.h>
#include <stdbool.h>

#include "shell.h"

int main(void) {

	printf(
		"\033[97mOperating System Shell\033[0m \033[90m[version 0.1.0.030323.beta]\033[0m\n"
		"Copyright (C) 2023 Yuyu378. All rights reserved.\n"
		"License GPLv3+: GNU GPL version 3 or later <\033[4mhttps://www.gnu.org/licenses/gpl-3.0.en.html\033[0m>.\n"
		"This is free software; you can freely change and redistribute it.\n"
		"There is NO WARRANTY, to the extent permitted by law.\n\n"
	);

	while (true) {
		char* commandLine = 0;
		printf("Shell >");
		commandLine = argGetter();
		if (*commandLine) executor(commandLine);
		free(commandLine);
	}

	return 0;
}
