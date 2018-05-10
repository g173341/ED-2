//
//  Control.hpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 22/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#ifndef Control_hpp
#define Control_hpp

#include <iostream>
#include "Client.h"
#include "ClientVip.hpp"
#include "Menu.h"
#include "LinkedQueue.hpp"
class Control{
private:
    GenericQueue g;
    void initMenu();
public:
    Control();
};
#endif /* Control_hpp */
