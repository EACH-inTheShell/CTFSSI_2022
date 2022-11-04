#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHELLCODE_BUFFER_SIZE 32

int main()
{
	char buffer[SHELLCODE_BUFFER_SIZE] = {0};

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("O arquivo esta aqui. Voce consegue ver ele?\n");
	read(0, buffer, SHELLCODE_BUFFER_SIZE);

	((void (*)())buffer)();

	exit(0);
}
