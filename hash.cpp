#include <iostream>
#include <cstddef> // Para usar o NULL
#include "hash.hpp" 
#include "Client.h"
#include "ClientVip.hpp"
using namespace std;
/*
  O construtor já foi feito para você, apenas memorize a sintaxe de
  alocação de um array. Observe que a chamada "new Account[size]" vai
  gerar novos objetos Account
 */
Hash::Hash(int size) {
  MAX_ITEMS = size;
  cadastro  = new Client*[size];

  /* 
     É sempre interessante garantir que os valores serão inicializados com NULL.
   */
  for (int i = 0; i < size; i++) {
    cadastro[i] = NULL;
  }
  length    = 0;
}

int Hash::getLength() const
{
    return this->length;
}

void Hash::retrieveItem(Client& cli, bool& found)
{
  int index = cli.getHash(MAX_ITEMS);
    found = false;
  /*
    Note que eu já estou desreferenciando o ponteiro que está em
    cadastro[location].
   */
    
    
    
       
        while (cadastro[index] != NULL && cadastro[index]->getEmail() != cli.getEmail()){
             index = (index+1) % MAX_ITEMS;
        
        Client aux = *cadastro[index];
        cli = aux;
        if (cadastro[index]->getEmail() != cli.getEmail()){
            found = true;
        }
    }
        
   
}



/*
  Agora use explicitamente o copy constructor para colocar o elemento
  que veio por parâmetro na posição correta.
 */

void Hash::insertItem(Client cli)
{
    int index = cli.getHash(MAX_ITEMS);
    
    
    while(cadastro[index] != NULL){
        index = (index+1) % MAX_ITEMS;
    }
   
    cadastro[index] = new Client(cli);
    length++;
}
void Hash::insertItem(ClientVip cli)
{
    int index = cli.getHash(MAX_ITEMS);
    
    
    while(cadastro[index] != NULL){
        index = (index+1) % MAX_ITEMS;
    }
    
    cadastro[index] = new ClientVip(cli);
    length++;
}


bool Hash::deleteItem(Client cli)
{
    int index = cli.getHash(MAX_ITEMS);
    while(cadastro[index] != NULL && cadastro[index]->getEmail() != cli.getEmail() ){
         index = (index+1) % MAX_ITEMS;
    }
    if(cadastro[index] != NULL){
         cadastro[index] = lapide;
        length--;
        return true;
    }
    return false;
   
}


/*
  O método print já foi implementado para você.
 */
void Hash::print() const {
  std::cout << "INI" << std::endl;
  for (int i = 0; i < MAX_ITEMS; i++) {
    Client* acc = cadastro[i];    
      if (acc != NULL & acc != lapide) {
       cout<< i << ":" << acc->getEmail() <<", "  <<acc->getCredits()<< endl;
      }
  }
  std::cout << "FIM" << std::endl;
}
