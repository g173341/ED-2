//
//  Client.cpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 14/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#include <iostream>
#include "Client.h"

using namespace std;
Client::Client(){
    
};
Client::Client(const Client &obj ){
    number = obj.number;
    name = obj.name;
    email = obj.email;
    max_credits = obj.max_credits;
    
};

Client::Client(int number,string name,string email,int credits){
    this->number = number;
    this->name = name;
    this->email = email;
    this->max_credits = credits;
};

int Client::getHash(const int max_items){
    return (number + max_credits) % max_items;
};

string Client::getName(){
    return name;
};
int Client::getNumber(){
    return number;
};
string Client::getEmail(){
    return email;
};
int Client::getCredits(){
    return  max_credits;
};

int Client::getPriority(){
    return max_credits * number;
};



