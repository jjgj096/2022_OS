//20201866
#include "types.h"
#include "stat.h"
#include "user.h"
//20201866

#define PNUM 5
#define PRINT_CYCLE 10000000  //1천만
#define TOTAL_COUNTER 500000000 //5억

void sdebug_func(void)
{
  int n, pid;

  printf(1, "start sdebug command\n");

  for(n=0; n<PNUM; n++)
  {
    pid = fork();
    if(pid < 0)
      break;
    if(pid == 0)
    {
      //20201866
      int counter = 0;
      int pid = getpid();
      int weight;
      int begin_ticks = uptime();
      int end_ticks;
      if((weight = weightset(n+1)) == -1) {
        printf(1, "weightset error\n");
        exit();
      }
      //20201866

      while(counter < TOTAL_COUNTER)
      {
        if(counter++ == PRINT_CYCLE)
        {
          end_ticks = uptime();
          printf(1, "PID : %d, WEIGHT : %d, TIMES : %d ms\n", pid, weight, (end_ticks - begin_ticks)*10);
        }
      }

      printf(1, "PID : %d terminated\n", pid);
      exit();
    }
  }
    //wait() 부분
    for(n = 0; n < PNUM; n++) {
      if(wait() < 0) {
        printf(1, "wait error\n");
        exit();
      }
    }

    if(wait() != -1) {
      printf(1, "wait error\n");
      exit();
    }

    printf(1, "end of sdebug command\n");
}

int main(void)
{
  sdebug_func();
  exit();
}