#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/**
 * main - A simple shell with 0 leaks
 * Return: 0 when succes
 */

int main(void)
{
	char *buff = NULL;
	size_t len = 0, read_line;

	while (1)
	{
		printf("#cisfun$ ");
		read_line = getline(&buff, &len, stdin);

		if (read_line == EOF)
			break;
		if (buff[read_line - 1] == '\n')
		{
			buff[read_line - 1] = '\0';
		}
		int child_process_id = fork();

		if (child_process_id == -1)
		{
			printf("Error");
			return (-1);
			free(buff);
		}
		char *cmd = buff;

		if (child_process_id == 0)
		{
			char *args[2];

			args[0] = buff;
			args[1] = NULL;
			char *pathEnv[] = {"PATH=/usr/bin", NULL};

			if (execve(args[0], args, pathEnv) == -1)
				perror("/shell");
		}
		else
		{
			wait(NULL);
		}
	}
}
