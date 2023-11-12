#include "shell.h"

/**
 * prompter - used to display user prompt
 * @buff_inp: is the memory for input typed by user
 * @size_buff: is the number of bytes in buff_inp
 * Return: nothing
 */
void prompter(char **buff_inp, size_t *size_buff)
{
	printf("#cisfun$ ");
	getline(buff_inp, size_buff, stdin);
}
/****************input process***********************************/
/**
 * input_proc - takes in user inputt and removes \n
 * @buff_inp: is the user input to be checked
 * Return: nothing
 */
void input_proc(char *buff_inp)
{
	size_t line_len = strlen(buff_inp);

	if (line_len && buff_inp[line_len - 1] == '\n')
	{
		buff_inp[strlen(buff_inp) - 1] = '\0';
	}
}
/**
 * command_exec - checks and execute commands
 * @cmd: the command input
 * Return: nothing
 */
void command_exec(char *cmd)
{
	char *args[3];

	args[0] = strtok(cmd, " ");
	args[1] = strtok(NULL, " ");
	args[2] = NULL;

	if (execve(args[0], args, NULL) == -1)
	{
		perror("/shell");
		exit(EXIT_FAILURE);
	}
}
