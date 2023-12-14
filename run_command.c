#include "shel.h"

void run_command(char **args, int foreground, char **environ)
{

char *varname = NULL, *varvalue = NULL, *token = NULL;
int arg_count = 0;
int i = 0;
pid_t pid;

pid = fork();
(void)environ;
if (pid < 0)
{
perror("Error: fork() failed\n");
return;
}
else if (pid == 0)
{
for (i = 0; args[i] != NULL; i++)
{
if (args[i][0] == '$')
{
varname = args[i] + 1;
varvalue = getenv(varname);
if (varvalue != NULL)
{
arg_count = i;
token = strtok(varvalue, " ");
while (token != NULL)
{
args[arg_count] = token;
arg_count++;
token = strtok(NULL, " ");
}
}
}
}

if (execvp(args[0], args) < 0)
{
perror("Error: execvp() failed\n");
exit(1);
}
}
else
{
if (foreground)
{
ppid = pid;
waitpid(pid, NULL, 0);
}
}
}

