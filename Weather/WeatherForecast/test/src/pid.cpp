#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <signal.h>
#include <unistd.h>
#include <fstream>   
class Testing
{
public:
  Testing()
  { 
    std::cout << "TestingPID()\n";
  }
  ~Testing()
  { 
    std::cout << "~TestingPID()\n";
  }
};

bool isResetCalled = false;
void  SIGTERM_handler(int sig);
int main()
{
  Testing t;
  pid_t pid = getpid();

  std::ofstream fh;
  fh.open ("fileContainingPID.txt", std::ofstream::out | std::ofstream::app);

  fh << pid;

  fh.close();

  if(signal(SIGTERM, SIGTERM_handler) == SIG_ERR) 
  {
     printf("SIGTERM install error\n");
     exit(1);
  }
  
  while(!isResetCalled){}

  return 1;
}

void  SIGTERM_handler(int sig)
{
  std::cout <<"Signal to restart program received" << std::endl;
	isResetCalled =true;
  //exit(3);
}

