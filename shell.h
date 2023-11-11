#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

void command_exec(char *cmd);
void prompter(char **buff_inp, size_t *size_buff);
void input_proc(char *buff_inp);
void command_exec(char *cmd);

#endif
