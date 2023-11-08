#include "main.h"

/**
 * main - A simple shell with 0 leaks
 * Return: 0 when succes
 */

int main(void)
{
	char *buff = NULL;
	size_t len = 0;
	ssize_t read_line;
	int child_process_id;
	char *pathEnv[] = {"PATH=/usr/bin", NULL};

	while (1)
	{
		printf("#cisfun$ ");
		read_line = getline(&buff, &len, stdin);

		if (read_line == -1)
		{
			printf("\n");
			break;
		}
		if (buff[read_line - 1] == '\n')
		{
			buff[read_line - 1] = '\0';
		}
		child_process_id = fork();

		if (child_process_id == -1)
		{
			printf("Error while Forking");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (child_process_id == 0)
		{
			char *args[2];

			args[0] = buff;
			args[1] = NULL;

			if (execve(args[0], args, pathEnv) == -1)
				perror("/shell");
		}
		else
		{
			wait(NULL);
		}
	}
	free(buff);
	return (0);
}
