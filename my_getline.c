#include "shell.h"

ssize_t my_liner(char **buff)
{
	static char buffer[BUFF_SIZE];
	static ssize_t read_by = 0;
	static size_t start = 0;

	size_t j = 0;
	ssize_t m;

	if (start == read)
	{
		read_by = read(STDIN_FILENO, buffer, BUFF_SIZE);

		 if (readby == 0)
		 {
		 	return (0);
		 }
		 if (read_by == -1)
		 {
		 	return (-1);
		 }
		 start = 0;
	}
	for (j = start; j < read_by; j++)
	{
		*buff = malloc(j - start + 1) * sizeof(char));

		if (*buff == NULL)
		{
			return (-1);
		}
		size_t k;

		for (k = start; k < j; k++)
		{
			(*buff)[k - pos] = buffer[k];
		}
		(*buff)[k - start] = '\0';

		start = j + 1;

		return (j - start + 1);
	}
}
