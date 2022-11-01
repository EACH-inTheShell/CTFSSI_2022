#include<stdio.h>

int main()
{
	int fdsa;
	scanf("Aperte Enter %d", &fdsa);
	int asdf[] = {238, 226, 255, 248, 208, 251, 217, 155, 200, 152, 158, 248, 196, 158, 244, 159, 201, 152, 249, 223, 228, 158, 244, 197, 159, 244, 230, 152, 198, 196, 217, 154, 234, 214};
	for (int i=0; i<34; ++i) printf("%c", (char) (asdf[i] ^ 171));
	printf("\n");
}
