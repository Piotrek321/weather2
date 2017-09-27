#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include "../inc/MessagingHandler.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <mqueue.h>

#define MSGSZ     128

bool isResetCalled = false;
void  SIGTERM_handler(int sig);

int main()
{
	mqd_t messageQueueHandler;

	struct mq_attr attr;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 30;

	messageQueueHandler= mq_open("/myqueue", O_RDWR | O_NONBLOCK, 0655, &attr);
	if(messageQueueHandler == -1)
  {
  	std::cout <<"Mq_open went wrong" <<std::endl;
  }
	Plotter y;
	y.init();
	WeatherAPI * b = new WeatherOWM;
	WeatherAPI * c= new WeatherYahoo;
/*
  struct sigaction sigac;
  sigemptyset(&sigac.sa_mask);
  sigac.sa_sigaction = handler;
  sigac.sa_flags = SA_SIGINFO;
  sigaction(SIGINT, &sigac, NULL);
*/

  if(signal(SIGTERM, SIGTERM_handler) == SIG_ERR) 
  {
     printf("SIGTERM install error\n");
     exit(1);
  }

	while(isResetCalled != true)
	{
		char * message = new char [100];
		if( mq_receive(messageQueueHandler, message, 100, NULL) != -1)
		{
			c->printTemperature(message);
			b->printTemperature(message);
		}
		delete [] message;
		sleep(1);
	}
	delete b;
	delete c;
  //std::cout << mq_close(messageQueueHandler) << std::endl;
  //mq_unlink("/myqueue");
	exit(3);
	return 1;
}



void  SIGTERM_handler(int sig)
{
  std::cout <<"Signal to restart program received" << std::endl;
	isResetCalled =true;
  //exit(3);
}



