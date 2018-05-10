//
//  Control.cpp
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 22/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#include "Control.hpp"
using namespace std;
Control::Control(){
    g = GenericQueue();
    initMenu();
}
void Control::initMenu(){
    vector<string> opt(  {"Exit","Insert a client", "Insert a  vip client", "Delete client", "Show linked heap"});
    Menu *m = new Menu("Linked Queue Assigment",opt);
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
                Client cli  =  Client(number, name, email, credits);
                g.enqueue(cli);
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
                g.enqueue(*cli);
                
                cout<<"Inserted"<<endl;
            };
                break;
            case 3: {
                Client c = g.dequeue();
                if(c.getName() != ""){
                    cout<<c.getName() + " deleted."<<endl;
                }else{
                     cout<<"Nothing to be deleted."<<endl;
                }
               
            
            };
                break;
            case 4:{
                g.list();
            };
                break;
            default:
                break;
        }
    }
    
    }
    

