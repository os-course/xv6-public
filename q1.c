#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{
	int pid;
    int result_pid = 0;
	int w, r;
	pid = fork();
	if (pid == 0)           // CHILD
  	{	
        printf(1, "Child PID : %d\n", getpid());
        for (int i = 0; i < 2000; i++) {
			printf(1, "Vahid\n");
        }
		exit();
    }
  	else if (pid > 0)       // PARENT
 	{
    	result_pid = waitx(&w, &r);
 	}  
 	printf(1, "Wait Time = %d\nRun Time = %d\nPID %d \n", w, r, result_pid); 
 	exit();
}
