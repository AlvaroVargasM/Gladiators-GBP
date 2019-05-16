#include "connector.h"
#include "string"
#include <sstream>

Connector::Connector()
{
}

GenericLinkedList<std::string>* convertStringToLL(std::string data){
    std::stringstream ss(data);
    GenericLinkedList<std::string>* list = new GenericLinkedList<std::string>;

    while( ss.good() )
    {
        std::string substr;
        getline( ss, substr, ',' );
        list->add(substr);
    }
    return list;
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
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
        {
        }
        int port = 8888;
        std::string ipAddress = "192.168.0.103";

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));

        char buf[4096];
        NetPackage netpack = NetPackage();
        netpack.setFrom("Client");
        int requestStr = convertCommandToInt(request);
        std::cout << requestStr << std::endl;
        switch(requestStr){
        case 0:
        {netpack.setCommand("getStats");
            std::string finalMessage = netpack.getJSONPackage();
            std::cout << finalMessage << std::endl;
            send(sock, finalMessage.c_str(), finalMessage.size(), 0);
            memset(buf, 0, 4096);
            int bytesReceived = recv(sock, buf, 4096, 0);
            std::string preResponse =  std::string(buf, bytesReceived);

            std::cout << "Llego " << preResponse << std::endl;

            rapidjson::Document doc = NetPackage::convertToRJ_Document(preResponse);

            std::string response = doc["NetPackage"]["data"].GetString();

            std::cout << "Llego " << response << std::endl;

            GenericLinkedList<std::string>* list = convertStringToLL(response);

            close(sock);

            return list;


        }
            break;
        case 1:
        {
            netpack.setCommand("getCharts");

        }
            break;
        case 2:
        {netpack.setCommand("getSteps");
            std::string test = "None";
            netpack.setData(test);
            std::string finalMessage = netpack.getJSONPackage();
            std::cout << finalMessage << std::endl;
            send(sock, finalMessage.c_str(), finalMessage.size(), 0);
            memset(buf, 0, 4096);
            int bytesReceived = recv(sock, buf, 4096, 0);
            std::string preResponse =  std::string(buf, bytesReceived);

            std::cout << "Llego " << preResponse << std::endl;

            rapidjson::Document doc = NetPackage::convertToRJ_Document(preResponse);

            std::string response = doc["NetPackage"]["data"].GetString();

            std::cout << "Llego " << response << std::endl;

            GenericLinkedList<std::string>* list = convertStringToLL(response);

            close(sock);

            return list;

        }
            break;
        default:
            break;
        }

        close(sock);
}

GraphPac Connector::getCharts(){
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1)
        {
        }

        int port = 8888;
        std::string ipAddress = "127.0.0.1";

        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));

        char buf[4096];
        NetPackage netpack = NetPackage();
        netpack.setFrom("Client");
        netpack.setCommand("getCharts");
        std::string final = netpack.getJSONPackage();
        std::string received = "received";
        send(sock, final.c_str(), strlen(final.c_str()), 0);

        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);

        std::string prefitness = std::string(buf, bytesReceived);

        rapidjson::Document doc = netpack.convertToRJ_Document(prefitness);

        std::string stats = doc["NetPackage"]["data"].GetString();

        GraphPac graphpac;

        std::string statsNew = stats.substr(0, stats.find('/'));
        GenericLinkedList<std::string>* list1 = convertStringToLL(statsNew);
        int index = stats.find('/');
        stats = stats.substr(index+1);
        std::cout << "This is the new String " << stats << std::endl;
        std::string statsNew1 = stats.substr(0, stats.find('/'));
        GenericLinkedList<std::string>* list2 = convertStringToLL(statsNew1);
        index = stats.find('/');
        stats = stats.substr(index+1);
        std::cout << "This is the new String " << stats << std::endl;
        std::string statsNew2 = stats.substr(0, stats.find('/'));
        GenericLinkedList<std::string>* list3 = convertStringToLL(statsNew2);
        index = stats.find('/');
        stats = stats.substr(index+1);
        std::string statsNew3 = stats.substr(0, stats.find('/'));
        GenericLinkedList<std::string>* list4 = convertStringToLL(statsNew3);
        std::cout << "This is the new String " << stats << std::endl;

        for(int i = 0; i < list1->getLength(); i++){
            int current = std::stoi(list1->get(i)->getData());
            if(i % 2 == 0){
                graphpac.add(1, current);
            }else{
                graphpac.add(2, current);
            }
        }

        for(int i = 0; i < list2->getLength(); i++){
            int current = std::stoi(list2->get(i)->getData());
            if(i % 2 == 0){
                graphpac.add(3, current);
            }else{
                graphpac.add(4, current);
            }
        }

        for(int i = 0; i < list3->getLength(); i++){
            int current = std::stoi(list3->get(i)->getData());
            if(i % 2 == 0){
                graphpac.add(5, current);
            }else{
                graphpac.add(6, current);
            }
        }

        for(int i = 0; i < list4->getLength(); i++){
            int current = std::stoi(list4->get(i)->getData());
            if(i % 4 == 0){
                graphpac.add(7, current);
            }if(i % 4 == 1){
                graphpac.add(8, current);
            }if(i % 4 == 2){
                graphpac.add(9, current);
            }if(i % 4 == 3){
                graphpac.add(10, current);
            }
        }

        return graphpac;
}
