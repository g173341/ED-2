//
//  Control.cpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 22/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#include "Control.hpp"
#include <sstream>
#include <string>
using namespace std;
Control::Control(){
    initMenu();
}
void Control::initMenu(){
    vector<string> opt(  {"Exit","Insert a client", "Insert a  vip client", "Delete client", "Show all clients","Inser random list"});
    Menu *m = new Menu("Hash Assignment",opt);
    int choice =-1;
    while (choice !=0) {
         choice = m->getEscolha();
        switch (choice) {
            case 1:{
                string name, email;
                
                int number, credits;
                cout<< "Name: ";
                getline(cin,name);
                getline(cin,name);
                cout<< "Number: ";
                cin>>number;
                cout<< "Max credits: ";
                cin>>credits;
                cout<< "Email: ";
                getline(cin,email);
                getline(cin,email);
                Client *cli = new Client(number, name, email, credits);
                h->enqueue(*cli);
                cout<<"Inserted"<<endl;
            };
                break;
            case 2 :{
                string name, email;
                int number, credits, vipcode;
                cout<< "Name: ";
                getline(cin,name);
                getline(cin,name);
                cout<< "Number: ";
                cin>>number;
                cout<< "Max credits: ";
                cin>>credits;
                cout<< "Email: ";
                getline(cin,email);
                getline(cin,email);
                cout<< "VIP code: ";
                cin>>vipcode;
                cin.clear();
                ClientVip *cli = new ClientVip(number, name, email, credits,vipcode);
              h->enqueue(*cli);
                
                cout<<"Inserted"<<endl;
            };
                break;
            case 3: {
      
                h->dequeue();
                
            };
                break;
            case 4:{
                h->print();
            };
                break;
            case 5:{
                Client **listClient = new Client*[11];
                stringstream ss;
                vector<int> num ({rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30});
                vector<int> max ({rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30,rand() %30});
               
                for (int i =0;i<11;i++){
                    char c = rand() % 25 + 97;
                    string s (1,c);
                    Client * o =  new Client(num[i],s,s+"@ft.com",max[i]);
                    listClient[i] = new Client(*o);
                    h->enqueue(*o);
                }
                Heap *newHeap = new Heap(19,listClient,11);
                newHeap->print();
                m = NULL;
                opt.pop_back();
                m = new Menu("Hash Assignment",opt);
            };
                
                
                             
                break;
            default:
                break;
        }
    }
    
    }
    

