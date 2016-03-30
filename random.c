#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define SUM 100
#define MAX 2000

int main(int argc, char *argv[]) {
	int i = 0;
	int sum, max;
	sscanf(argv[1], "%d", &sum);
	sscanf(argv[2], "%d", &max);
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
		printf("%d ", random() % MAX);
	return 0;
}