#include "shel.h"
void shell()
{
char input[MAX_INPUT_LENGTH];
char *args[MAX_ARGS];
int foreground;
FILE *fptr;
while (1)
{
printf("%s$ ", current_working_directory);
fgets(input, MAX_INPUT_LENGTH, stdin);
if (feof(stdin))
{
printf("\n");
exit(0);
}
parse_input(input, args, &foreground);
if (args[0] == NULL)
{
continue;
}
else if (strcmp(args[0], "exit") == 0)
{
fptr = fopen("output.txt", "a");
if (fptr == NULL)
{
perror("Error opening file!\n");
exit(1);
}
fprintf(fptr, "All processes terminated \n");
fclose(fptr);
kill(0, SIGKILL);
exit(0);
}
else if (strcmp(args[0], "cd") == 0 || strcmp(args[0], "echo") == 0 || strcmp(args[0], "export") == 0)
{
run_builtin_shell_cmd(args);
}
else
{

run_command(args, foreground, environ);
}
}
}

