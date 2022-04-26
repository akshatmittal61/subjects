#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    char *argv[] = {"./fork1", NULL};
    int pid = fork();
    if (pid == 0)
    {
        printf(" Hello\n");
        execvp(argv[0], argv);
    }
    else
    {
        sleep(2);
        printf(" Finished executing the parent process\n"
               " - the child won't get here--you will only see this once\n");
    }
    return 0;
}