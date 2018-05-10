//
//  Heap.cpp
//  Heap
//
//  Created by Kaulitz Guimarães on 28/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#include "Heap.hpp"

Heap::Heap(int MAX_ITEMS){
    this->MAX_ITEMS = MAX_ITEMS;
    cadastro  = new Client*[MAX_ITEMS];
    for (int i = 0; i <this-> MAX_ITEMS; i++) {

        cadastro[i] = NULL;
    }
    length    = 0;
};
Heap::Heap(int MAX_ITEMS, Client** ARRAY_ACCOUNT, int NUM_IN_ARRAY_ACCOUNT){
    this->MAX_ITEMS = MAX_ITEMS;
    cadastro  = new Client*[MAX_ITEMS];
    for (int i = 0; i <this-> MAX_ITEMS; i++) {

        cadastro[i] = NULL;
    }

    for (int i =0; i<NUM_IN_ARRAY_ACCOUNT; i++) {
        cadastro[i] = new Client(*ARRAY_ACCOUNT[i]);
    }

 print();

        for (int i =((NUM_IN_ARRAY_ACCOUNT-1)/2)-1; i>=0; i--) {

            descida(i, NUM_IN_ARRAY_ACCOUNT);

        }



    length = NUM_IN_ARRAY_ACCOUNT;
    }
void Heap::enqueue(Client newItem){
    length++;
    int indexBuffer = length-1;
    cadastro[indexBuffer] = new Client(newItem);
    subida(0, indexBuffer);
}
Client Heap::dequeue(){
    int indexBuffer = length - 1;
    Client buffer = *cadastro[0];
    cadastro[0] = cadastro[indexBuffer];
    cadastro[indexBuffer] = NULL;
    delete cadastro[indexBuffer];
    length--;
    descida(0, length-1);
    return buffer;
};
void Heap::subida(int root, int index){
    if(index < root){
        return;
    }else{

        int indexBuffer = ((index-1)/2);
        Client buffer;

        if (cadastro[index]->getPriority() >cadastro[indexBuffer]->getPriority() ){
            buffer = *cadastro[index];
            cadastro[index] =cadastro[indexBuffer];
            cadastro[indexBuffer] =new Client(buffer);
            subida(root, indexBuffer);

        }
    }

};
void Heap::descida(int index, int bottom){
    int indexBuffer1 = (2*index+1);
     int indexBuffer2 = (2*index+2);


        if((cadastro[indexBuffer1]==NULL &&  cadastro[indexBuffer2] == NULL) || (indexBuffer2>bottom || indexBuffer1>bottom)){
            return;
        }else{

            if(cadastro[indexBuffer2]->getPriority() > cadastro[indexBuffer1]->getPriority()){

                indexBuffer1 = indexBuffer2;

            }

            Client buffer;

            if (cadastro[index]->getPriority() < cadastro[indexBuffer1]->getPriority() ){

                buffer = *cadastro[index];
                cadastro[index] =cadastro[indexBuffer1];
                cadastro[indexBuffer1] =new Client(buffer);
                descida(indexBuffer1, bottom);
            }

    }
};
void Heap::print() const {
    std::cout << "INI" << std::endl;
    for (int i = 0; i < MAX_ITEMS; i++) {
        Client* acc = cadastro[i];
        if (acc != NULL) {
            cout<< i << ":" << acc->getEmail() <<", "  <<acc->getCredits()<< ", "<<acc->getPriority() << endl;
        }
    }
    std::cout << "FIM" << std::endl;
};

Heap::~Heap(){
    for(int i=0;i<MAX_ITEMS;i++){
        delete cadastro[i];
    }
    delete cadastro;
};
