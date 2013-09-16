/*
/ This program fork a child process while the parent process does not wait. 
/The result should be that tthere is a defunc process shown in the result of 
/ps command.
*/

#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
   signal(SIGCHLD,SIG_IGN);
   PID_t PID;
   
   PID=fork();
   
   if (PID==0)
   {
      execlp("/bin/ls","ls",NULL);
      cout<<"this is the child process!";
   }else if(PID>0)
   {
      cout<<"this is the parent process!"
   }


   return 0;
}