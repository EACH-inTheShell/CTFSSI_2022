#include <stdio.h>

void win()
{
	char flag[40] = {0};

	FILE *f = fopen("flag.txt", "r");
	fread(flag, 1, 40, f);
	fclose(f);

	puts(flag);
}

void vulneravel()
{
	char buffer[64] = {0};

	printf("Toma, para tu: %p\n> ", (void *)win);

	gets(buffer);
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	vulneravel();
}
