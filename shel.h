#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

pid_t ppid;
extern char **environ;
char current_working_directory[MAX_INPUT_LENGTH];
void parent_signal_handler();
void setup_environment();
void run_builtin_shell_cmd(char **args);
void run_command(char **args, int foreground, char **env);
void parse_input(char *input, char **args, int *foreground);
void signal_handler();
extern void shell(void);
#endif
