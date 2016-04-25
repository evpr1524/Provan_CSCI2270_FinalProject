#include "Resources.h"
#include <iostream>
#include <vector>

using namespace std;

Resources::Resources()
{
    //ctor
}

Resources::~Resources()
{
    //dtor
}

void Resources::addpartymember(std::string username, int userage){

    person *addtolist = new person;
    addtolist->name=username;
    addtolist->age=userage;
    partylist.push_back(addtolist);
}

void Resources::removepartymember(std::string username){

    for(int i=0; i<partylist.size(); ++i){
        if(partylist[i]->name==username){
            cout << "found the user to delete!" << endl;

        }
    }

}

void Resources::displayallmembers(){
    for(int i=0; i<partylist.size(); ++i){
        cout << "Party member " << i+1 << " " << partylist[i]->name << ". Age: " << partylist[i]->age;
        cout << "\n";
    }

}
