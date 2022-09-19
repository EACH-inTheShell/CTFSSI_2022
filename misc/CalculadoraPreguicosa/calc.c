#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <sys/wait.h>

int main()
{
	printf("Bem vindos à calculadora do EiTS :)\n> ");
	fflush(stdout);

	char *input = NULL;
	size_t input_len = 0;
	getline(&input, &input_len, stdin);

	char command[64] = {0};
	snprintf(command, sizeof(command), "print(%s)", input);

	free(input);

	int pid = fork();

	if (pid == 0) {
		char* cmd = "/bin/python3";
		char* args[] = {cmd, "-c", command, NULL};
		char* env[] = {NULL};
		execve(cmd, args, env);
	}
	else if (pid > 0) {
		waitpid(pid, NULL, 0);
	}
}
