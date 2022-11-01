#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
	for (int i = 0; i < 10; i++) {
		int* ptr = malloc(10 * 1024 * 1024);
		memset(ptr, 0, 10 * 1024 * 1024);
		sleep(1);
	}
	return 0;
	
	// si & so are 0 if running the code
	// si & so increases if running the code with top command
}
