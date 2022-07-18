#include <stdio.h>
#include <malloc.h>

int main()
{
	printf("> ");
	fflush(stdout);

	char *input = NULL;
	size_t input_len = 0;
	getline(&input, &input_len, stdin);

	char command[64] = {0};
	snprintf(command, sizeof(command), "python3 -c 'print(%s)'", input);

	free(input);

	FILE* fd = popen(command, "r");

	char output[128] = {0};
	fread(output, sizeof(*output), sizeof(output), fd);
	printf("%s", output);
	fflush(stdout);

	fclose(fd);
}
