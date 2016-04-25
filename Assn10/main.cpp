#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Graph.h"
#include "Resources.h"

using namespace std;

int main()
{
    int choice=0;
    string mychoice;
    ifstream inFile;
    string data;
    string cityname;
    string citydistance;
    string startingCity;
    string endingCity;
    string username;
    string useragestr;
    int userage=0;

    Graph g;
    Resources r1;
    char *filenamein = "zombieCities.txt";

    g.buildgraph(filenamein);

    cout << "Welcome to the Post-Apocalyptic Transit and Resource Monitor Network (PATRN)" << endl;
    cout << "\nThis application will allow you to keep track of your resources and connected cities in order to aid you in surviving the Apocalypse. \n" << endl;
    cout << "The application is now building the network from the cities that are most likely to have survived the apocalypse \n" << endl;
    cout << "We have set your initial city to Seattle, this can be changed in the code if desired.\n" << endl;
    cout << "Please enter the name of the current user" << endl;
    getline(cin, username);
    cout << "Please enter the age of the current user" << endl;
    getline(cin, useragestr);
    stringstream(useragestr) >> userage;
    r1.addpartymember(username, userage);


    while(choice!=420){
        cout << "======Main Menu======" << endl;
        cout << "1. Print verticies of colonies" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path (number of cities)" << endl;
        cout << "4. Find shortest distance between two cities" << endl;
        cout << "5. Display current city" << endl;
        cout << "6. Move to a connecting city" << endl;
        cout << "7. Display resources" << endl;
        cout << "8. Add a new type of resource to the register" << endl;
        cout << "9. Update resource register" << endl; // will have 2 public methods, add and subtract
        cout << "10. Add a city to the network" << endl;
        cout << "11. Update connections between two cities" << endl;
        cout << "12. Add member to party" << endl;
        cout << "13. Remove member from party" << endl;
        cout << "14. Display current party" << endl;
        cout << "15. Close Application" << endl;

        getline(cin, mychoice);
        stringstream(mychoice) >> choice;

        switch(choice){
        case 1:
            //cout << "printing verticies" << endl;
            g.printVertices();
            break;
        case 2:
            //cout << "Finding Districts" << endl;
            g.assignDistricts();
            break;
        case 3:
            //cout << "finding shortest path" << endl;
            cout << "Enter a starting city:" << endl;
            getline(cin, startingCity);
            cout << "Enter an ending city:" << endl;
            getline(cin, endingCity);
            g.shortestPath(startingCity, endingCity);
            break;
        case 4:     //shortest distance
            cout << "Enter a starting city:" << endl;
            getline(cin, startingCity);
            cout << "Enter an ending city:" << endl;
            getline(cin, endingCity);
            g.shortestDistance(startingCity, endingCity);
            break;
        case 5:     //
            break;
        case 6:     //
            break;
        case 7:     //
            break;
        case 8:     //
            break;
        case 9:     //
            break;
        case 10:    //
            break;
        case 11:    //
            break;
        case 12:    //add a party member
            cout << "Please enter the name of the party member to add: ";
            getline(cin, username);
            cout << "Please enter the age of the party member to add:" << endl;
            getline(cin, useragestr);
            stringstream(useragestr) >> userage;
            r1.addpartymember(username, userage);
            break;
        case 13:    //remove a party member
            cout << "Please enter the name of the party member to remove: ";
            getline(cin, username);
            r1.removepartymember(username);
            break;
        case 14:    //display all the users
            r1.displayallmembers();
            break;
        case 15:
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
}
