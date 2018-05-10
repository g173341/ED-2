//
//  LinkedQueue.cpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 27/04/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#include "LinkedQueue.hpp"
GenericQueue::GenericQueue(){
    this->front = NULL;
    this->rear = NULL;
}
GenericQueue::~GenericQueue(){
    NodeType* tempPtr;
    while (rear != NULL) {
        tempPtr = front;
        front  = front -> next;
        delete tempPtr;
    }
    
}


void GenericQueue::enqueue(ItemType item){
    try {
        NodeType* location;
        location = new NodeType;
        location->info = new Client(item);
        location->next = NULL;
        if(isEmpty()){
           
            
            front = rear =  location;
        }
            else{
            
           
        
            
            rear->next = location;
            rear = location;
          
            
                
               
           
        }
      
        
    }catch(std::bad_alloc exception){
        cout<<"THE MEMORY IS FULL!"<<endl;
    }
}
ItemType GenericQueue::dequeue(){
    if(! isEmpty()){
        NodeType *buffer = front;
        ItemType i = *buffer->info;
        front = front->next;
        buffer = NULL;
        delete buffer;
        return i;
    }
    ItemType item;
    return item;
}

void GenericQueue::list(){
    if(isEmpty()){
         cout<<"Empty list"<<endl;
    }
    NodeType *buffer = front;
    while (front != NULL) {
        cout<<"Name : " + dequeue().getName()<<endl;
    }
    front = buffer;
    
}
bool GenericQueue:: isEmpty() const {
        return (front == NULL);
    }


