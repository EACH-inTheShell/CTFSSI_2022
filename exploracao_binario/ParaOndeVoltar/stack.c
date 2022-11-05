#include <stdio.h>

char flag[40] = {0};

void win()
{
	FILE *f = fopen("flag.txt", "r");
	fread(flag, 1, 40, f);
	fclose(f);

	printf("Parabens, aqui esta a sua flag: %s\n", flag);
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
