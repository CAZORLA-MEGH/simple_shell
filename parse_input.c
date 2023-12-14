#include "shel.h"
void parse_input(char *input, char **args, int *foreground)
{
char *token = strtok(input, " \t\n");
int i = 0;
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " \t\n");
}
args[i] = NULL;
if (i > 0 && strcmp(args[i - 1], "&") == 0)
{
*foreground = 0;
args[i - 1] = NULL;
}
else
{
*foreground = 1;
}
}

