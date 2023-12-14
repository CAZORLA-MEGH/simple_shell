#include "shel.h"
void parent_signal_handler()
{

FILE *fptr;
int child_status;
pid_t child_pid;
int status = 1;

while ((child_pid = waitpid(-1, &child_status, WNOHANG)) > 0)
{
status = 0;
if (WIFEXITED(child_status))
{
fptr = fopen("output.txt", "a");
if (fptr == NULL)
{
perror("Error opening file!\n");
exit(1);
}
kill(child_pid, SIGKILL);
fprintf(fptr, "Child process %d terminated \n", child_pid);
fclose(fptr);
}
}
if (status)
{
fptr = fopen("output.txt", "a");
if (fptr == NULL)
{
perror("Error opening file!\n");
exit(1);
}
fprintf(fptr, "Child process %d terminated \n", ppid);
fclose(fptr);
}
}

