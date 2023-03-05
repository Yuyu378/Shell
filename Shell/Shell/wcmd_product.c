
#include "wcmd_product.h"

void product(char** input) {
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
		printf((ans < 1e3 && ans > 1e-3) ? " %lf\n\n" : " %e\n\n", ans);
	}
	return;
}
