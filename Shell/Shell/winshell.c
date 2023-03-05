// 
// winshell.c
// 
//		Implement the execution details of shell
// 

#include "winshell.h"
#include "winshell_command.h"

char* argGetter(void) {

	char* argv = 0;
	if ((argv = (char*)calloc(CLSIZE, sizeof(char))) == NULL) {
		printf("Allocation failed.\n\n");
		return 0;
	}
	fgets(argv, CLSIZE, stdin);

	char ch = 0;
	unsigned argc = (unsigned)strlen(argv);
	if (argv[argc - 1] != '\n') while ((ch = getchar()) != '\n' && ch != EOF);
	else argv[argc - 1] = '\0';

	char* command = 0;
	if ((command = (char*)calloc((size_t)argc + 1, sizeof(char))) == NULL) {
		printf("Allocation failed.\n\n");
		free(argv);
		return 0;
	}

	for (unsigned i = 0; i < argc; i++) command[i] = argv[i];
	free(argv);
	return command;
}

void executor(char* commandLine) {

	char* command = 0;
	char* parameterLine = 0;
	command = strtok_s(commandLine, " ", &parameterLine);
	if (!strcmp(command, "bye")) {
		free(commandLine);
		exit(EXIT_SUCCESS);
	}

	char* call = 0;
	if ((call = (char*)calloc(CLSIZE, sizeof(char))) == NULL) {
		printf("Allocation failed.\n\n");
		return;
	}

	char** input = 0;
	if ((input = (char**)calloc(3, sizeof(char*))) == NULL) {
		printf("Allocation failed.\n\n");
		return;
	}
	input[0] = call, input[1] = command, input[2] = parameterLine;

	calc(input);
	notepad(input);
	hostname(input);
	help(input);
	time(input);
	product(input);

	free(call);
	return;
}
