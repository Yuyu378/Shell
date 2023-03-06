
#include "cmd_product.h"

#ifdef _WIN64
void cmd_product(char** input) {
	if (!strcmp(input[1], "product")) {
		double ans = 1, tmp = 0;
		char* parameter = strtok_s(NULL, " ", &input[2]);
		if (parameter == NULL) {
			printf("Product not found parameters.\n\n");
			return;
		}
		while (parameter != NULL) {
			if ((tmp = strtod(parameter, 0)) == 0 && !(parameter[0] == '0' || parameter[1] == '0')) {
				printf(" %s <- error here\n\n", parameter);
				return;
			}
			printf(" %s", parameter);
			ans *= tmp;
			(parameter = strtok_s(NULL, " ", &input[2])) == NULL ? printf(" =") : printf(" *");
		}
		printf((fabs(ans) < 1e4) ? " %lf\n\n" : " %e\n\n", ans);
	}
	return;
}
#endif

#ifdef __linux__
void cmd_product(char** input) {
	if (!strcmp(input[1], "product")) {
		double ans = 1, tmp = 0;
		char* parameter = __strtok_r(NULL, " ", &input[2]);
		if (parameter == NULL) {
			printf("Product not found parameters.\n\n");
			return;
		}
		while (parameter != NULL) {
			if ((tmp = strtod(parameter, 0)) == 0 && !(parameter[0] == '0' || parameter[1] == '0')) {
				printf(" %s <- error here\n\n", parameter);
				return;
			}
			printf(" %s", parameter);
			ans *= tmp;
			(parameter = __strtok_r(NULL, " ", &input[2])) == NULL ? printf(" =") : printf(" *");
		}
		printf((fabs(ans) < 1e4) ? " %lf\n\n" : " %e\n\n", ans);
	}
	return;
}
#endif
