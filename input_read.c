#include "shell.h"
/**
 * read_input - reads a line typed
 * @buff: stores memory of input
 * Return: 0 on success
 */
ssize_t read_input(char **buff)
{
	int ty = 0, le = 0;
	ssize_t rex = 0;
	size_t j = 0;

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}
	rex = getline(buff, &j, stdin);
	while (rex != -1 && *buff && (*buff)[ty] != 0)
	{
		if ((*buff)[ty] != ' ' && (*buff[ty] != '\t'))
		{
			le = 1;
		}
		ty++;
	}
	if (!le)
	{
		rex = -1;
	}
	return (rex);
}
