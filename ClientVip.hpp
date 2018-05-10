//
//  ClientVip.hpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 15/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#ifndef ClientVip_hpp
#define ClientVip_hpp

#include <iostream>
#include "Client.h"

class ClientVip : public Client {
    private :
        int codVip;
public:
    ClientVip(const ClientVip& obj);
    ClientVip(int, string, string, int,int);
    int getHash(const int max_items);



};

#endif /* ClientVip_hpp */

