#include "connector.h"
#include "string"
//prototypes

Connector::Connector()
{
}

void Connector::sendTest(int request){
    //	Create a socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
        {
            //return nullptr;
        }

        //	Create a hint structure for the server we're connecting with
        int port = 8888;
        std::string ipAddress = "192.168.0.102";

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        //	Connect to the server on the socket
        int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
        if (connectRes == -1)
        {
            //return nullptr;
        }

        //	While loop:
        char buf[4096];
        NetPackage netpack = NetPackage();
        netpack.setFrom("Server");
        switch(request){
        case 1:
        {netpack.setCommand("Message");
            std::string test = "HOla mundo";
            netpack.setData(test);
            std::string finalMessage = netpack.getData();
            send(sock, finalMessage.c_str(), finalMessage.size(), 0);}
            break;
        case 2:
            //Do something
            break;
        case 3:
            //Do something
            break;
        default:
            //Default state
            break;
        }


        /*do {
            //		Enter lines of text
            std::cout << "> ";
            getline(std::cin, userInput);

            //		Send to server
            int sendRes = send(sock, userInput.c_str(), userInput.size() + 1, 0);
            if (sendRes == -1)
            {
                std::cout << "Could not send to server! Whoops!\r\n";
                continue;
            }

            //		Wait for response
            memset(buf, 0, 4096);
            int bytesReceived = recv(sock, buf, 4096, 0);
            if (bytesReceived == -1)
            {
                std::cout << "There was an error getting response from server\r\n";
            }
            else
            {
                //		Display response
                std::cout << "SERVER> " << std::string(buf, bytesReceived) << "\r\n";
            }
        } while(true);*/

        //	Close the socket
        close(sock);

        //return nullptr;
}


