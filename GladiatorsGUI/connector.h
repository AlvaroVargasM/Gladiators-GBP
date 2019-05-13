#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#include "netpackage.h"
#include "genericlinkedlist.h"

class Connector
{
public:
    Connector();
    static GenericLinkedList<std::string>* get(std::string);
};

#endif // CONNECTOR_H
