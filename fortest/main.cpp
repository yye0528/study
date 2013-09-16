/*
/ This program fork a child process while the parent process does not wait.
/The result should be that tthere is a defunc process shown in the result of
/ps command.
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
   signal(SIGCHLD,SIG_IGN);
   pid_t PID;

   PID=fork();

   if (PID==0)
   {
	  cout<<"this is the child process! \n";
      execlp("/bin/ls","ls",NULL);

   }else if(PID>0)
   {
      cout<<"this is the parent process! \n";
   }


   return 0;
}
