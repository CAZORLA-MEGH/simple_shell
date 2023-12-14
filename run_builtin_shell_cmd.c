#include "shel.h"

void run_builtin_shell_cmd(char **args)
{
int i = 0;
char *varname = NULL;
char *varvalue = NULL;
char result[100] = "";
int len = 0;
int j = 0;
char *token = NULL;
char *name = NULL;
char *value = NULL;
if (strcmp(args[0], "cd") == 0)
{
if (args[1] == NULL || strcmp(args[1], "~") == 0)
{
chdir(getenv("HOME"));
}
else
{
chdir(args[1]);
}
getcwd(current_working_directory, MAX_INPUT_LENGTH);
}
else if (strcmp(args[0], "echo") == 0)
{
for (i = 1; args[i] != NULL; i++)
{
if (args[i][0] == '$')
{
varname = args[i] + 1;
varvalue = getenv(varname);
if (varvalue != NULL)
{
args[i] = varvalue;
}
}
printf("%s ", args[i]);
}
printf("\n");
}
else if (strcmp(args[0], "export") == 0)
{
if (args[1] != NULL && strchr(args[1], '=') != NULL)
{

for (i = 2; args[i] != NULL; i++)
{
strcat(result, " ");
strcat(result, args[i]);
}

strcat(args[1], result);

len = strlen(args[1]);
for (i = 0; i < len; i++)
{
if (args[1][i] == '\"')
{
for (j = i; j < len; j++)
{
    args[1][j] = args[1][j + 1];
}
len--;
i--;
}
}
token = strtok(args[1], "=");
name = token;
token = strtok(NULL, "=");
value = token;
setenv(name, value, 1);
}
}
}

