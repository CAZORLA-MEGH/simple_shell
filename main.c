#include "shel.h"                                                                                                                
int main (int argc, char *argv[], char **environ)
{
signal_handler();
setup_environment();
shell();
(void)argc;
(void)argv;
(void)environ;

return 0;
}

