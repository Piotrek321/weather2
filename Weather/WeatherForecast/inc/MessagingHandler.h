#ifndef MESSAGINGHANDLER_H
#define MESSAGINGHANDLER_H

#include <errno.h>
#include <mqueue.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MSGSZ     128
/*
 * Declare the message structure.
 */

class MessagingHandler
{
public:
    MessagingHandler(std::string serverOrClient, bool a);
    void sendMessage(std::string datatoSend, unsigned int priority);
    bool receiveMessage(std::string &message);
 struct mq_attr attr;
    mqd_t messageQueueHandler;


};

#endif // MESSAGINGHANDLER_H
