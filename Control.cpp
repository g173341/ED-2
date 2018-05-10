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
    initMenu();
}
void Control::initMenu(){
    vector<string> opt(  {"Exit","Insert a client", "Insert a  vip client", "Delete client", "Show all clients"});
    Menu *m = new Menu("Hash Assigment",opt);
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
                h->insertItem(*cli);
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
                h->insertItem(*cli);
                
                cout<<"Inserted"<<endl;
            };
                break;
            case 3: {
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
                if(h->deleteItem(*cli)){
                   cout<<"Deleted"<<endl;
                }else{
                     cout<<"Client wasn't found."<<endl;
                }
                
            };
                break;
            case 4:{
                h->print();
            };
                break;
            default:
                break;
        }
    }
    
    }
    

