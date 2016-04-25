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
