#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Graph.h"
#include "Resources.h"

using namespace std;

int main()
{
    int choice=0;   //initialize all the variables this menu/wrapper function incorporates
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
    int distancebetween12=0;

    Graph g;    //create instance of Graph
    Resources r1;   //create an instance of resources
    char *filenamein = "zombieCities.txt";  //read in the file that is in the folder to build the initial graph

    g.buildgraph(filenamein); //the function that builds the graph initially

    cout << "Welcome to the Post-Apocalyptic Transit and Resource Monitor Network (PATRN)" << endl; //intro txt
    cout << "\nThis application will allow you to keep track of your resources and connected cities in order to aid you in surviving the Apocalypse. \n" << endl;   //intro txt
    cout << "The application is now building the network from the cities that are most likely to have survived the apocalypse \n" << endl;  //intro txt
    cout << "We have set your initial city to Seattle, this can be changed in the code if desired.\n" << endl;  //intro txt
    cout << "Please enter the name of the current user" << endl;    //obtain the user's name to initialize the party
    getline(cin, username); //standard procedure of obtaining user input here
    cout << "Please enter the age of the current user" << endl;
    getline(cin, useragestr);
    stringstream(useragestr) >> userage;    //converting to an integer
    r1.addpartymember(username, userage);   //adds the user to the party list


    while(choice!=420){ //this wraps all the menus together
        cout << "======Main Menu======" << endl;    //the main menu text
        cout << "1. Manage Cities/Move cities" << endl;
        cout << "2. Manage Resources (Food/Water/Weapons)" << endl;
        cout << "3. Manage Party members" << endl;
        cout << "4. Exit Application" << endl;

        getline(cin, mychoice); //obtains user input for main menu
        stringstream(mychoice) >> choice;   //converts user input to an int for the switch function

        switch(choice){ //standard switch function
            case 1:
                choice=69;  //reset user input to something impossible for next menu/while loop
                while(choice!=9){   //keeps user in city menu function until they choose to leave
                cout << "===============City Menu===============" << endl;  //city menu
                cout << "1. Print verticies of colonies" << endl;
                cout << "2. Find districts" << endl;
                cout << "3. Find shortest path (number of cities)" << endl;
                cout << "4. Find shortest distance between two cities" << endl;
                cout << "5. Display current city" << endl;
                cout << "6. Move to a connecting city" << endl;
                cout << "7. Add a city to the network" << endl;
                cout << "8. Update connections between two cities" << endl;
                cout << "9. Return to previous Menu" << endl;

                getline(cin, mychoice); //obtaining user input
                stringstream(mychoice) >> choice;

                switch(choice){ //switch function for the city menu
                    case 1: //print current cities in the graph and their connections
                        g.printVertices();
                        break;
                    case 2: //assigning districts to the current cities in the graph
                        g.assignDistricts();
                        break;
                    case 3: //find the shortest path (not including distances)
                        cout << "Enter a starting city:" << endl;
                        getline(cin, startingCity); //obtain user input
                        cout << "Enter an ending city:" << endl;
                        getline(cin, endingCity);   //obtain user input
                        g.shortestPath(startingCity, endingCity);
                        break;
                    case 4:     //shortest distance between two cities
                        cout << "Enter a starting city:" << endl;
                        getline(cin, startingCity); //obtain user input
                        cout << "Enter an ending city:" << endl;
                        getline(cin, endingCity);   //obtain user input
                        g.shortestDistance(startingCity, endingCity);
                        break;
                    case 5:     //display current city
                        nearestcitymain=r1.printcurrentcity();  //prints the current city, which returns the name of the current city
                        g.printnearestcities(nearestcitymain);  //takes the current city and displays the surrounding cites
                        break;
                    case 6:     //move to a connecting city
                        nearestcitymain=r1.printcurrentcity();  //obtain the current city
                        g.printnearestcities(nearestcitymain);  //print the nearest cities
                        cout << "Please enter the name of the city you wish to move to" << endl;
                        getline(cin, startingCity); //obtain user input
                        moveto = g.movecity(nearestcitymain, startingCity); //moves the user to the new city if it is adjacent
                            if(moveto == "NotACity"){
                                cout << "You can not travel to " << startingCity << " from your current city" << endl;  //if the city wasn't an adjacent city, return that you can't travel to it.
                            }else{
                                r1.move1city(moveto);   //else, move to the city
                            }
                        break;
                    case 7:     //Add a city to the network
                        cout << "Please enter the name of the city you would like to add to the network: ";
                        getline(cin, cityname); //obtain user input
                        g.addVertex(cityname);  //adds the city to the list of verticies
                        g.assignDistricts();    //assigns districts again, to avoid errors when printing
                        break;
                    case 8:     //Update connections between two cities
                        cout << "Please enter the name of the first city you would like to connect: ";
                        getline(cin, cityname); //obtain user input
                        cout << "Please enter the name of the second city you would like to connnect to " << cityname << " :";
                        getline(cin, startingCity); //obtain user input
                        cout << "Please enter the distance between " << cityname << " and " << startingCity << ":";
                        getline(cin, endingCity);   //obtain user input
                        stringstream(endingCity) << distancebetween12;
                        g.addEdge(cityname, startingCity, distancebetween12);   //add the new edge
                        g.assignDistricts();    //assigns districts again to avoid errors when printing the verticies
                        break;
                    case 9:     //return to main (basically do nothing)
                        break;
                    default:    //what to do if it isn't one of the cases
                        cout << "invalid Input, Please try again" << endl;
                        break;
                }
                }
            break;
        case 2: //the resource menu
            choice=69;  //set the choice to something the user can't set it to
            while(choice!=4){   //while not choosing to exit the menu
            cout << "=============Resource Menu=============" << endl;  //print menu
            cout << "1. Display resources" << endl;
            cout << "2. Update the resource register with food, water, or weapons" << endl;
            cout << "3. Add special Item (Not Food, Water, or Weapons)" << endl; // something?
            cout << "4. Return to previous menu" << endl;

            getline(cin, mychoice); //obtain user input
            stringstream(mychoice) >> choice;

            switch(choice){
                case 1:     //Display Resources
                    r1.printinventory();
                    break;
                case 2:    //Add a new type of resource to the register
                    r1.addresource();
                    break;
                case 3:    //Add a special item to your inventory
                    r1.addspecialItem();
                    break;
                case 4: //leave the function
                    break;
                default:    //what to do if user enters gibberish
                    cout << "Invalid input, returning to previous menu" << endl;
                    break;
            }
            }
            break;
        case 3: //party menu
            while(choice!=4){
            cout << "=============Party Menu=============" << endl;
            cout << "1. Add member to party" << endl;
            cout << "2. Remove member from party" << endl;
            cout << "3. Display current party" << endl;
            cout << "4. Return to previous Menu" << endl;

            getline(cin, mychoice); //obtain user input
            stringstream(mychoice) >> choice;

            switch(choice){ //switch for the party menu
                case 1:    //add a party member
                    cout << "Please enter the name of the party member to add: ";
                    getline(cin, username); //obtain user input
                    cout << "Please enter the age of the party member to add:" << endl;
                    getline(cin, useragestr);   //obtain user input
                    stringstream(useragestr) >> userage;
                    r1.addpartymember(username, userage);
                    break;
                case 2:    //remove a party member
                    cout << "Please enter the name of the party member to remove: ";
                    getline(cin, username); //obtain user input
                    r1.removepartymember(username);
                    break;
                case 3:    //display all the users
                    r1.displayallmembers();
                    break;
                case 4: //exit the function
                    break;
                default:
                    cout << "Invalid input, returning to previous menu" << endl;
                    break;
            }
            }
            break;
        case 4: //leave the main menu/exit the application
            cout << "Goodbye!" << endl;
            return 0;
        default:    //unrecognized user input
            cout << "Invalid Input, please try again" << endl;
            break;
        }


    }
}
