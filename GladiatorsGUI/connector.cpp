#include "connector.h"
#include "string"
#include <sstream>
//prototypes

Connector::Connector()
{
}

int convertCommandToInt(std::string data) {
    enum commands {
        setStats = 0,
        setChampions,
        setSteps,
    };
    if (data == "setStats") {
        return setStats;
    }
    if (data == "setChampions") {
        return setChampions;
    }
    if (data == "setSteps") {
        return setSteps;
    }
    return -1;
}

GenericLinkedList<std::string>* Connector::get(std::string request){
    //	Create a socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
        {
            //return nullptr;
        }

        //	Create a hint structure for the server we're connecting with
        int port = 8888;
        std::string ipAddress = "127.0.0.1";

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        //	Connect to the server on the socket
        int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
        /*if (connectRes == -1)
        {
            std::cout <<
            return nullptr;
        }*/

        //	While loop:
        char buf[4096];
        NetPackage netpack = NetPackage();
        netpack.setFrom("Client");
        int requestStr = convertCommandToInt(request);
        std::cout << requestStr << std::endl;
        switch(requestStr){
        case 0:
            break;
        case 1:
            //Do something
            break;
        case 2:
        {netpack.setCommand("getSteps");
            std::string test = "None";
            netpack.setData(test);
            std::string finalMessage = netpack.getJSONPackage();
            send(sock, finalMessage.c_str(), finalMessage.size(), 0);
            memset(buf, 0, 4096);
            int bytesReceived = recv(sock, buf, 4096, 0);
            std::string preResponse =  std::string(buf, bytesReceived);

            std::cout << "Llego " << preResponse << std::endl;

            rapidjson::Document doc = NetPackage::convertToRJ_Document(preResponse);

            std::string response = doc["NetPackage"]["data"].GetString();

            std::cout << "Llego " << response << std::endl;

            std::stringstream ss(response);
            GenericLinkedList<std::string>* list = new GenericLinkedList<std::string>;

            while( ss.good() )
            {
                std::string substr;
                getline( ss, substr, ',' );
                list->add(substr);
            }

            close(sock);

            return list;

        }
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


