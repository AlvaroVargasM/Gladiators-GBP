//
// Created by jondorito on 29/04/19.
//

#ifndef GLADIATORS_GBP_SERVER_H
#define GLADIATORS_GBP_SERVER_H


#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <iostream>
#include "NetPackage.h"

#define TRUE   1
#define FALSE  0
#define PORT 8888

class Server{
public:
    static int start();
};


#endif //GLADIATORS_GBP_SERVER_H
