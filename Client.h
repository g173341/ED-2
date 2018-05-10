//
//  Client.h
//  HashAssignment
//
//  Created by Kaulitz Guimarães on 14/03/18.
//  Copyright © 2018 Kaulitz Guimarães. All rights reserved.
//

#ifndef Client_h
#define Client_h
using namespace std;
class Client{
    private :
    int number;
    string name;
    string email;
    int max_credits;
    public:
    Client(const Client &obj );
    Client(int,string,string,int);
    virtual int getHash(const int max_items );
    int getNumber();
    string getName();
    string getEmail();
    int getCredits();
    
    
};
#endif /* Client_h */
