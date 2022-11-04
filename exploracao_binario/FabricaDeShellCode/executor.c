#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHELLCODE_BUFFER_SIZE 16
#define FLAG_BUFFER_SIZE 40

void win()
{
	FILE *flag_file = fopen("flag.txt", "r");
	char flag[FLAG_BUFFER_SIZE] = {0};
	fread(flag, 1, FLAG_BUFFER_SIZE, flag_file);
	fclose(flag_file);

	printf("Parabens, aqui sua flag: %s\n", flag);
}

int main()
{
	char buffer[SHELLCODE_BUFFER_SIZE] = {0};

	printf("Toma, um presente: %p\nBoa sorte!\n", (void *)win);
	read(0, buffer, SHELLCODE_BUFFER_SIZE);

	((void (*)())buffer)();

	exit(0);
}
