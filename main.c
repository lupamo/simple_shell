#include "shell.h"
/**
 * main - A simple shell with 0 leaks
 * Return: 0 when succes
 */

int main(void)
{
	char *buff = NULL;
	size_t len = 0;
	int child_process_id;
	ssize_t read_char;

	while (1)
	{
		prompter(&buff, &len);
		read_char = getline(&buff, &len, stdin);

		if (read_char == -1)
		{
			if (errno == EOF)
			{
				printf("End of file");
				break;
			}
			else
			{
				perror("shell closed");
				free(buff);
				exit(EXIT_FAILURE);
			}
		}
		input_proc(buff);

		child_process_id = fork();

		if (child_process_id == -1)
		{
			perror("Error forking");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (child_process_id == 0)
		{
			command_exec(buff);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	free(buff);
	return (0);
}
