#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define SUM 100
#define MAX 200

int main(int argc, char **argv) {
	int i = 0;

	srand(time(NULL));
	for (i = 0; i < SUM; i++)
		printf("%d ", random() % MAX);
	return 0;
}