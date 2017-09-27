#include "../inc/MessagingHandler.h"
//TODO add design pattern
MessagingHandler::MessagingHandler(std::string queueName, bool a)
{
   attr.mq_maxmsg = 10;
   attr.mq_msgsize = 30;
   messageQueueHandler= mq_open(queueName.c_str(), O_WRONLY|O_CREAT, 0655, &attr);
   if(messageQueueHandler == -1)
   {
     std::cout <<"Mq_open went wrong" <<std::endl;
   }
}


void MessagingHandler::sendMessage(std::string datatoSend, unsigned int priority)
{
  mq_send(messageQueueHandler,datatoSend.c_str(), datatoSend.length(), priority);

}
bool MessagingHandler::receiveMessage(std::string &message)
{
   return true;
}
