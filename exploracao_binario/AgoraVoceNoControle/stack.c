#include <stdio.h>

char flag[40] = {0};

struct Object {
	char buffer[32];
	unsigned int variavel;
};

int main()
{
	struct Object object;
	object.variavel = 0;

	setvbuf(stdout, NULL, _IONBF, 0);
	FILE* f = fopen("flag.txt", "r");
	fread(flag, 1, 40, f);
	fclose(f);

	printf("Sera que voce consegue?\n> ");
	gets(object.buffer);

	if (object.variavel == 0xe175babe) {
		printf("Parabens, aqui esta a sua flag: %s\n", flag);
	}
	else {
		printf("Boa sorte na proxima\n");
	}
}
