#include "../../inc/MessagingHandler.h"
#include <cassert>
#include <mqueue.h>
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

  MessagingHandler mh("/queueTest");
  std::string messageToSend = "messageToReceive";
  std::string messageToReceive;
  std::string messageToReceive1 = "messageToSend"; 

  if(signal(SIGTERM, SIGTERM_handler) == SIG_ERR) 
  {
     printf("SIGTERM install error\n");
     exit(1);
  }
  
  while(!isResetCalled)
  {
		if(mh.receiveMessage(messageToReceive))
		{
		  assert(messageToReceive == messageToReceive1);
		  mh.sendMessage(messageToSend,0);
		}
  }

  return 1;
}

void  SIGTERM_handler(int sig)
{
  std::cout <<"Signal to restart program received" << std::endl;
	isResetCalled =true;
  //exit(3);
}

