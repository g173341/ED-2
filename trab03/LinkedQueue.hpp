//
//  LinkedQueue.hpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 27/04/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#ifndef LinkedQueue_hpp
#define LinkedQueue_hpp

#include <iostream>
#include "Client.h"
typedef Client ItemType;

// Estrutura usada para guardar a informacao e o endereco do proximo
// elemento.
struct NodeType
{
    ItemType* info;
    NodeType* next;
};



class GenericQueue
{
public:
    
    GenericQueue();
    ~GenericQueue();
    void     enqueue(ItemType);
    void list();
    ItemType dequeue();
    
    bool     isEmpty() const;
    bool     isFull() const;
    
private:
    NodeType* front;
    NodeType* rear;
};

#endif /* LinkedQueue_hpp */
