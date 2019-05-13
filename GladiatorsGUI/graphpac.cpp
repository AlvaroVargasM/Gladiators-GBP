#include "graphpac.h"

GraphPac::GraphPac()
{

}

void GraphPac::add(int num, std::string data){
    switch(num){
    case 1:
        this->gen1->add(data);
        break;
    case 2:
        this->gen2->add(data);
        break;
    case 3:
        this->gen3->add(data);
        break;
    case 4:
        this->gen4->add(data);
        break;
    case 5:
        this->gen5->add(data);
        break;
    case 6:
        this->gen6->add(data);
        break;
    case 7:
        this->gen7->add(data);
        break;
    case 8:
        this->gen8->add(data);
        break;
    case 9:
        this->gen9->add(data);
        break;
    case 10:
        this->gen10->add(data);
        break;
    }
}

GenericLinkedList<std::string>* GraphPac::get(int index){
    switch(index){
    case 1:
        return this->gen1;
    case 2:
        return this->gen2;
    case 3:
        return this->gen3;
    case 4:
        return this->gen4;
    case 5:
        return this->gen5;
    case 6:
        return this->gen6;
    case 7:
        return this->gen7;
    case 8:
        return this->gen8;
    case 9:
        return this->gen9;
    case 10:
        return this->gen10;
    }
}
