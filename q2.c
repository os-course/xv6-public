#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int
main(void)
{
    int pid, wpid;
    set_priority(0);
    for (int i = 0; i < 8; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            int p = 100 - (i*10 + i + 1);
            printf(1, "Process with PID %d and Priority %d \n", getpid(), p);
            set_priority(p);
            while (1)
            {
                continue;
            }
            exit();
        }        
    }

    sleep(50);
    cps();
    while ((wpid = wait()) > 0);                // WAIT FOR ALL CHILDREN TO EXIT
    exit();        
}
