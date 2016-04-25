#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "Graph.h"

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

    Graph g;
    char *filenamein = "zombieCities.txt";

    g.buildgraph(filenamein);

    while(choice!=420){
        cout << "======Main Menu======" << endl;
        cout << "1. Print verticies of colonies" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path (number of cities)" << endl;
        cout << "4. Find shortest distance between two cities" << endl;
        cout << "5. " << endl;
        cout << "6. " << endl;
        cout << "7." << endl;
        cout << "8." << endl;
        cout << "9." << endl;
        cout << "10." << endl;
        cout << "11. Close Application" << endl;

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
        case 11:
            cout << "Goodbye!" << endl;
            return 0;

        }
    }
}
