#include <unistd.h>
#include <stdio.h>

void vulneravel()
{
	char buffer[64] = {0};
	printf("Toma um outro presente: %p\nAgora brinha\n> ", (void*)read);
	gets(buffer);
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	vulneravel();
}
