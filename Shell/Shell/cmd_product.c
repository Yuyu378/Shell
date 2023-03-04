
#include "cmd_product.h"

void product(char** input) {
	if (!strcmp(input[1], "product")) {
		double ans = 1, tmp = 0;
		char* parameter = strtok_s(NULL, " ", &input[2]);
		if (parameter == NULL) {
			printf("Product not found parameters.\n\n");
			return;
		}
		while (parameter != NULL) {
			if (!strcmp(parameter, "0")) {
				ans = 0;
				break;
			}
			else if ((tmp = strtod(parameter, 0)) == 0) {
				printf(" %s <- error here\n\n", parameter);
				return;
			}
			printf(" %lf", tmp);
			ans *= tmp;
			(parameter = strtok_s(NULL, " ", &input[2])) == NULL ? printf(" =") : printf(" *");
		}
		printf(" %lf\n\n", ans);
	}
	return;
}
