#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define SUM 100000
#define MAX 200000

int main(int argc, char **argv) {
	int i = 0;
	int sum = SUM, max = MAX;
	switch (argc) {
	case 2:
		sscanf(argv[1], "%d", &sum);
	case 3:
		sscanf(argv[2], "%d", &max);
		break;
	default:
		break;
	}

	srand(time(NULL));
	for (i = 0; i < SUM; i++)
		printf("%ld ", random() % MAX);
	return 0;
}