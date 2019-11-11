#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    int pid, count_vater = 1000, count_sohn = 1000;

    pid = fork();

    if (pid == 0)
    {

        while (count_sohn > 0)
        {

            printf("[PID: %d] [PPID: %d]: Ich bin der Vater.\n", getpid(), getppid());

            count_sohn--;
            sleep(1);
        }

        exit(EXIT_SUCCESS);
    }
    else
    {

        while (count_vater > 0)
        {
            printf("[PID: %d] [PPID: %d]: Ich bin der Sohn.\n", getpid(), getppid());

            count_vater--;
            sleep(1);
        }
        exit(EXIT_SUCCESS);
    }

    return 0;
    sleep(5);
}