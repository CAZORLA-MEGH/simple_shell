#include "shel.h"
void signal_handler()
{
struct sigaction sigact;
sigemptyset(&sigact.sa_mask);
sigact.sa_flags = SA_RESTART | SA_NOCLDSTOP;
sigact.sa_handler = parent_signal_handler;
sigaction(SIGCHLD, &sigact, NULL);
}

