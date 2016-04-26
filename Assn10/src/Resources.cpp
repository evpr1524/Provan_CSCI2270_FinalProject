#include "Resources.h"
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

Resources::Resources()
{
    currentcity="Seattle";
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
            cout << "Deleting " << username << " from the list of party members" << endl;
            partylist.erase(partylist.begin()+i);
        }
    }
    cout << "Your party now consists of:" << endl;

    for(int i=0; i<partylist.size(); ++i){
        cout << "Party member " << i+1 << " " << partylist[i]->name << " Age: " << partylist[i]->age;
        cout << "\n";
    }
}

void Resources::displayallmembers(){
    for(int i=0; i<partylist.size(); ++i){
        cout << "Party member " << i+1 << " " << partylist[i]->name << " Age: " << partylist[i]->age;
        cout << "\n";
    }

}

string Resources::printcurrentcity(){

    cout << "Your current city is: " << currentcity << "." << endl;
    cout << "The closets Cities to you are: ";
    return currentcity;

}

void Resources::move1city(std::string moveto){

    currentcity=moveto;

}
