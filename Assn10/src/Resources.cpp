#include "Resources.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <sstream>

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

void Resources::printinventory(){
    cout << "Your current food count is: " << i1.food << "." << endl;
    cout << "Your current water supply is: " << i1.water << "." << endl;
    if(i1.armory.empty()){
        cout << "You currently have no weapons." << endl;
    }else{
        cout << "Your armory currently consists of:\n";
        for(int i=0; i<i1.armory.size(); ++i){
            cout << "\t" << i1.armory[i].type << " " << i1.armory[i].name << " " << i1.armory[i].number << endl;
        }
    }
    if(i1.special.empty()){
        cout << "You have no special items in your inventory." << endl;
    }else{
        cout << "Your current special Items are:" << endl;
        for(int j=0; j<i1.special.size(); ++j){
            cout << "\t Name: " << i1.special[j].name << ", Quantity: " << i1.special[j].quantity << endl;
            cout << "\t\t" << i1.special[j].description << endl;
        }
    }

}

void Resources::addresource(){

    string mychoice;
    int mychoiceint=0;
    string weapontype;
    string name;
    string newnumberstr;
    int newnumber;

    cout << "======Add Resource Menu======" << endl;
    cout << "1. Add food" << endl;
    cout << "2. Add water" << endl;
    cout << "3. Add weapon" << endl;
    cout << "=============================" << endl;
    cout << "Please pick an item to add: ";
    getline(cin, mychoice);
    stringstream(mychoice) >> mychoiceint;

    switch (mychoiceint){
    case 1:
        cout << "Enter the amount of food you wish to add or subtract to your stock" << endl;
        cout << "You currently have: " << i1.food << " counts of food" << endl;
        cout << "Amount to add or subtract (use \"-\" sign to subtract): ";
        getline(cin, mychoice);
        stringstream(mychoice) >>mychoiceint;
        i1.food=i1.food+mychoiceint;
        break;
    case 2:
        cout << "Enter the amount of water you wish to add or subtract to your stock" << endl;
        cout << "You currently have: " << i1.water << " counts of water" << endl;
        cout << "Amount to add or subtract (use \"-\" sign to subtract): ";
        getline(cin, mychoice);
        stringstream(mychoice) >>mychoiceint;
        i1.water=i1.water+mychoiceint;
        break;
    case 3:
        cout << "Please enter the type of weapon (such as Assault Rifle, Sniper Rifle, Baseball Bat, etc):" << endl;
        getline(cin, weapontype);
        cout << "Please enter the name of the weapon (such as AK-47, M24, M9, etc.):" << endl;
        getline(cin, name);
        cout << "Please enter the number of " << name << "'s you are adding to your inventory:" << endl;
        getline(cin, newnumberstr);
        stringstream(newnumberstr) >> newnumber;
        weapon addtoinventory;
        addtoinventory.type=weapontype;
        addtoinventory.name=name;
        addtoinventory.number=newnumber;
        i1.armory.push_back(addtoinventory);
        break;
    }

}

void Resources::addspecialItem(){

    string myitemname;
    string myitemdescription;
    string myitemquantitystr;
    int quantity=0;
    specialItem sp1;

    cout << "Please enter a name for the item you wish to record: ";
    getline(cin, myitemname);
    cout << "Please enter a description for the item you wish to record:";
    getline(cin, myitemdescription);
    cout << "Please enter a quantity for the number of " << myitemname << "s you have:";
    getline(cin, myitemquantitystr);
    stringstream(myitemquantitystr) << quantity;

    sp1.description=myitemdescription;
    sp1.name=myitemname;
    sp1.quantity=quantity;
    i1.special.push_back(sp1);



}
