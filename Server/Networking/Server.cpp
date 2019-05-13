//
// Created by jondorito on 08/05/19.
//

#include "Server.h"
#include "../Logic/GenericLinkedList.h"


int convertCommandToInt(std::string data) {
    enum commands {
        getStats = 0,
        getChampions,
        getSteps,
    };
    if (data == "getStats") {
        return getStats;
    }
    if (data == "getChampions") {
        return getChampions;
    }
    if (data == "getSteps") {
        return getSteps;
    }
    return -1;
}


int Server::start()
{
    Game* game = new Game();
    int opt = TRUE;
    int master_socket , addrlen , new_socket , client_socket[30] ,
            max_clients = 1 , activity, i , valread , sd;
    int max_sd;
    struct sockaddr_in address;

    char buffer[1025];  //data buffer of 1K

    //set of socket descriptors
    fd_set readfds;

    //a message
    char *message = "ECHO Daemon v1.0 \r\n";

    //initialise all client_socket[] to 0 so not checked
    for (i = 0; i < max_clients; i++)
    {
        client_socket[i] = 0;
    }

    //create a master socket
    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //set master socket to allow multiple connections ,
    //this is just a good habit, it will work without this
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
                   sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    //bind the socket to localhost port 8888
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", PORT);

    //try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //accept the incoming connection
    addrlen = sizeof(address);
    puts("Waiting for connections ...");

    while(TRUE)
    {
        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        //add child sockets to set
        for ( i = 0 ; i < max_clients ; i++)
        {
            //socket descriptor
            sd = client_socket[i];

            //if valid socket descriptor then add to read list
            if(sd > 0)
                FD_SET( sd , &readfds);

            //highest file descriptor number, need it for the select function
            if(sd > max_sd)
                max_sd = sd;
        }

        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);

        if ((activity < 0) && (errno!=EINTR))
        {
            printf("select error");
        }

        //If something happened on the master socket ,
        //then its an incoming connection
        if (FD_ISSET(master_socket, &readfds))
        {
            if ((new_socket = accept(master_socket,
                                     (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform user of socket number - used in send and receive commands
            printf("New connection , socket fd is %d , ip is : %s , port : %d\n" , new_socket , inet_ntoa(address.sin_addr) , ntohs
                    (address.sin_port));

            //send new connection greeting message
            /*if( send(new_socket, message, strlen(message), 0) != strlen(message) )
            {
                perror("send");
            }*/

            //puts("Welcome message sent successfully");

            //add new socket to array of sockets
            for (i = 0; i < max_clients; i++)
            {
                //if position is empty
                if( client_socket[i] == 0 )
                {
                    client_socket[i] = new_socket;
                    printf("Adding to list of sockets as %d\n" , i);

                    break;
                }
            }
        }

        //else its some IO operation on some other socket
        for (i = 0; i < max_clients; i++)
        {
            sd = client_socket[i];

            if (FD_ISSET( sd , &readfds))
            {
                //Check if it was for closing , and also read the
                //incoming message
                if ((valread = read( sd , buffer, 1024)) == 0)
                {
                    //Somebody disconnected , get his details and print
                    getpeername(sd , (struct sockaddr*)&address , \
                        (socklen_t*)&addrlen);
                    printf("Host disconnected , ip %s , port %d \n" ,
                           inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

                    //Close the socket and mark as 0 in list for reuse
                    close( sd );
                    client_socket[i] = 0;
                }

                    //Echo back the message that came in
                else
                {
                    std::string json = std::string(buffer, valread);

                    std::cout << "Me llego " << json << std::endl;

                    rapidjson::Document doc = NetPackage::convertToRJ_Document(json);

                    std::string command = doc["NetPackage"]["command"].GetString();

                    int commandInt = convertCommandToInt(command);
                    std::cout << commandInt << std::endl;
                    NetPackage* netpack = new NetPackage();
                    netpack->setFrom("Server");
                    switch(commandInt) {
                        case 0:
                        {std::string data = game->getChampions();
                            netpack->setCommand("setStats");
                            netpack->setData(data);
                            std::string final = netpack->getJSONPackage();
                            std::cout << "Voy a enviar " << final << std::endl;
                            send(sd , final.c_str() , strlen(final.c_str()), 0 );}
                            break;
                        case 1:
                        {GenericLinkedList<std::string> champions ;
                            netpack->setCommand("steps");
                            std::string finalData = "";
                            finalData += champions.get(0)->getData();
                            for(int i = 1; i < *champions.getLength(); i++){
                                finalData += ',' + champions.get(i)->getData();
                            }
                            netpack->setData(finalData);
                            send(master_socket, finalData.c_str(), strlen(finalData.c_str()), 0);}
                            break;
                        case 2:
                        {
                            NetPackage* netpack = new NetPackage;
                            game->generateTowers();
                            GenericLinkedList<std::string> towers = game->getTowers();
                            GenericLinkedList<std::string> *list = new GenericLinkedList<std::string>;
                            for(int i = 0; i < *towers.getLength(); i++){
                                std::string temp = towers.get(i)->getData();
                                list->add(temp);
                            }
                            list->add("move.a.right");
                            list->add("move.a.right");
                            list->add("move.a.right");
                            list->add("move.a.down");
                            list->add("move.b.down");
                            list->add("move.b.down");
                            list->add("move.b.down");
                            list->add("move.b.down");
                            list->add("create.1.explosive.2.2");
                            list->add("shoot.1.b");
                            list->add("shoot.1.a");
                            list->add("finish");
                            std::string test = "";
                            test += list->get(i)->getData();
                            for(int i = 1; i < *list->getLength()-1; i++){
                                test += ',' + list->get(i)->getData();
                            }test += ',' +  list->get(*list->getLength()-1)->getData();
                            netpack->setData(test);
                            std::string final = netpack->getJSONPackage();
                            std::cout << "Voy a enviar " << test << std::endl;
                            send(sd , final.c_str() , strlen(final.c_str()), 0 );}
                            break;
                    }
                }
            }
        }
    }

    return 0;
}
