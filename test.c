#include "types.h"
#include "user.h"

#define WNOHANG 	1
  
int exitWait(void) {
	  int pid, ret_pid, exit_status;
    int i;
  // use this part to test exit(int status) and wait(int* status)
 
  printf(1, "\n  Parts a & b) testing exit(int status) and wait(int* status):\n");

  for (i = 0; i < 2; i++) {
    pid = fork();
    if (pid == 0) { // only the child executed this code
      if (i == 0){
        printf(1, "\nThis is child with PID# %d and I will exit with status %d\n", getpid(), 0);
        exit2(0);
      }
      else{
	      printf(1, "\nThis is child with PID# %d and I will exit with status %d\n" ,getpid(), -1);
        exit2(-1);
      } 
    } else if (pid > 0) { // only the parent executes this code
      ret_pid = wait2(&exit_status);
      printf(1, "\n This is the parent: child with PID# %d has exited with status %d\n", ret_pid, exit_status);
    } else { // something went wrong with fork system call
	    printf(2, "\nError using fork\n");
      exit2(-1);
    }
  }
  return 0;
}

int main(int argc, char *argv[])
{
	
	//int exitWait(void);
	//int waitPid(void);

  printf(1, "\n This program tests the correctness of your lab#1\n");
  
  if (atoi(argv[1]) == 1)
	exitWait();
//   else if (atoi(argv[1]) == 2)
// 	waitPid();
  else 
   printf(1, "\ntype \"%s 1\" to test exit and wait, \"%s 2\" to test waitpid\n", argv[0], argv[0]);
  
    // End of test
	 exit2(0);
	 return 0;
 }