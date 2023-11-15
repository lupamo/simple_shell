#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024

#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

void prompter(char **buff_inp, size_t *size_buff);
void input_proc(char *buff_inp);
void command_exec(char *cmd);
ssize_t read_input(char **buff);
#endif
