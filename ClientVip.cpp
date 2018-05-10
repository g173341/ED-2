//
//  ClientVip.cpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 15/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#include "ClientVip.hpp"

ClientVip::ClientVip(int number,string name,string email,int credits, int codVip) : Client( number, name, email, credits){this->codVip = codVip;};
ClientVip::ClientVip(const ClientVip &obj): Client(obj){};
int ClientVip::getHash(const int max_items){
    return (this->getCredits() * codVip) % max_items;
}

