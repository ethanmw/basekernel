#include "library/syscalls.h"
#include "library/string.h"

int main(const char *argv[], int argc)
{
	printf("hello world, I am %d.\n", process_self());
	int x = process_fork();
	if (x == 0) {
		for (int a = 0; a < 1000; a++) {
			printf("child\n");
		}
	} else {
		for (int b = 0; b < 1000; b++) {
			printf("parent\n");
		}
	}

	return 0;
}
