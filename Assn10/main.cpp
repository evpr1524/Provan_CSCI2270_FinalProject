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
    string nearestcitymain;
    int userage=0;
    string moveto;

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
        cout << "1. Manage Cities/Move cities" << endl;
        cout << "2. Manage Resources (Food/Water/Weapons)" << endl;
        cout << "3. Manage Party members" << endl;
        cout << "4. Exit Application" << endl;




        getline(cin, mychoice);
        stringstream(mychoice) >> choice;

        switch(choice){
            case 1:
                cout << "===============City Menu===============" << endl;
                cout << "1. Print verticies of colonies" << endl;
                cout << "2. Find districts" << endl;
                cout << "3. Find shortest path (number of cities)" << endl;
                cout << "4. Find shortest distance between two cities" << endl;
                cout << "5. Display current city" << endl;
                cout << "6. Move to a connecting city" << endl;
                cout << "7. Add a city to the network" << endl;
                cout << "8. Update connections between two cities" << endl;
                cout << "9. Return to previous Menu" << endl;

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
                    case 5:     //display current city
                        nearestcitymain=r1.printcurrentcity();
                        g.printnearestcities(nearestcitymain);
                        break;
                    case 6:     //move to a conecting city
                        nearestcitymain=r1.printcurrentcity();
                        g.printnearestcities(nearestcitymain);
                        cout << "Please enter the name of the city you wish to move to" << endl;
                        getline(cin, startingCity);
                        moveto = g.movecity(nearestcitymain, startingCity);
                        //cout << "moving to " << moveto << endl;
                            if(moveto == "NotACity"){
                                cout << "You can not travel to " << startingCity << " from your current city" << endl;
                            }else{
                                r1.move1city(moveto);
                            }
                        break;
                    case 7:     //Add a city to the network
                        break;
                    case 8:     //Update connections between two cities
                        break;
                    case 9:     //return to main (basically do nothing)
                        break;
                    default:
                        cout << "invalid Input, returning to previous menu" << endl;
                        break;
                }
            break;
        case 2:
            cout << "=============Resource Menu=============" << endl;
            cout << "1. Display resources" << endl;
            cout << "2. Update the resource register with food, water, or weapons" << endl;
            cout << "3. " << endl; // something?
            cout << "4. Return to previous menu" << endl;

            getline(cin, mychoice);
            stringstream(mychoice) >> choice;

            switch(choice){
                case 1:     //Display Resources
                    r1.printinventory();
                    break;
                case 2:    //Add a new type of resource to the register
                    r1.addresource();
                    break;
                case 3:    //
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid input, returning to previous menu" << endl;
                    break;
            }
            break;
        case 3:
            cout << "=============Party Menu=============" << endl;
            cout << "1. Add member to party" << endl;
            cout << "2. Remove member from party" << endl;
            cout << "3. Display current party" << endl;
            cout << "4. Return to previous Menu" << endl;

            getline(cin, mychoice);
            stringstream(mychoice) >> choice;

            switch(choice){
                case 1:    //add a party member
                    cout << "Please enter the name of the party member to add: ";
                    getline(cin, username);
                    cout << "Please enter the age of the party member to add:" << endl;
                    getline(cin, useragestr);
                    stringstream(useragestr) >> userage;
                    r1.addpartymember(username, userage);
                    break;
                case 2:    //remove a party member
                    cout << "Please enter the name of the party member to remove: ";
                    getline(cin, username);
                    r1.removepartymember(username);
                    break;
                case 3:    //display all the users
                    r1.displayallmembers();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid input, returning to previous menu" << endl;
                    break;
            }
            break;
        case 4:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid Input, please try again" << endl;
            break;
        }


    }
}
