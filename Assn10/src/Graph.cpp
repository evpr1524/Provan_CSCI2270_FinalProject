#include "Graph.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

struct queueDistrict{
    vector<vertex> integers;
};

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    //dtor
}

void Graph::buildgraph(char *filenamein){

    ifstream inFile;
    string data;
    string cityname;
    string citydistance;

    inFile.open(filenamein);
        if(inFile.good()){
            getline(inFile,data); //add the initial cities to the verticies vector
            stringstream ss(data);
            getline(ss, cityname, ',');
            while(getline(ss, cityname, ',')){
                    bool found = false;
                    for(int i = 0; i < vertices.size(); i++){
                        if(vertices[i].name == cityname){
                            found = true;
                            cout<<vertices[i].name<<" found."<<endl;
                        }
                    }
                    if(found == false){
                        vertex v;
                        v.name = cityname;
                        v.visited=false;
                        v.ID=-1;
                        vertices.push_back(v);
                    }
                }

            int row=0;
            while(getline(inFile,data)){ //add the adjacency vectors
                stringstream ss(data);
                getline(ss, citydistance, ','); //burn the first city
                int column=0;

                //cout << "row: " << row << endl;
                for(int q=0; q < row+1; q++){
                    getline(ss, citydistance, ',');
                    int citydistanceint = atoi(citydistance.c_str());
                    //cout << "row2: " << citydistanceint << endl;

                    //if(citydistanceint == 0){}
                    //if(citydistanceint == -1){}
                    if(citydistanceint>=1){ //add it to the adjacency matrix
                        string v1 = vertices[column].name;
                        string v2 = vertices[row].name;
                        //cout << v1 << " : " << v2 << " adding connection with weight: " << citydistanceint << endl;
                        int weight = citydistanceint;
                        for(int i = 0; i < vertices.size(); i++){
                            if(vertices[i].name == v1){
                                for(int j = 0; j < vertices.size(); j++){
                                    if(vertices[j].name == v2 && i != j){
                                        adjVertex av;
                                        av.v = &vertices[j];
                                        av.weight = weight;
                                        vertices[i].adj.push_back(av);
                                        //another vertex for edge in other direction
                                        adjVertex av2;
                                        av2.v = &vertices[i];
                                        av2.weight = weight;
                                        vertices[j].adj.push_back(av2);
                                    }
                                }
                            }
                        }
                    }
                    ++column;
                }
                ++row;
            }
        }
}

void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.ID=-1;
        vertices.push_back(v);

    }
}

void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::printVertices(){

    for(int i=0; i<vertices.size(); ++i){
        cout << vertices[i].ID << ":" << vertices[i].name << "-->";
            for(int j=0; j<vertices[i].adj.size(); ++j){
                cout<<vertices[i].adj[j].v->name;
                    if (j != vertices[i].adj.size()-1)
                        cout<<"***";
            }
            cout << endl;
    }


}

void Graph::assignDistricts(){
    queue<vertex*> q;
    vertex *v;
    int currentdistrict=1;
        for(int i=0; i<vertices.size(); ++i){
            if(vertices[i].visited==false){
                q.push(&vertices[i]);
                while(!q.empty()){
                    v=q.front();
                    q.pop();
                    v->visited=true;
                    v->ID=currentdistrict;

                    for(int x=0; x<v->adj.size(); ++x){
                            if(v->adj[x].v->visited==false){
                                q.push(v->adj[x].v);
                            }
                    }
                }
                ++currentdistrict;
            }
        }
}

void Graph::shortestPath(string startingCity, string endingCity){

    for(int z=0; z< vertices.size(); ++z){
        vertices[z].visited=false;
    }

    vertex *startcity;
    vertex *endcity;
    bool citystartfound=false;
    bool cityendfound=false;

    for(int i=0; i<vertices.size(); ++i){
        if(startingCity == vertices[i].name){
            startcity=&vertices[i];
            citystartfound=true;
        }
        if(endingCity == vertices[i].name){
            endcity=&vertices[i];
            cityendfound=true;
        }
    }
    if(citystartfound==false || cityendfound ==false){
        cout << "One or more cities doesn't exist" << endl;
        return;
    }
    if(startcity->ID==-1 || endcity->ID==-1){
        cout << "Please identify the districts before checking distances" << endl;
    }
    if(startcity->ID != endcity->ID){
        cout << "No safe path between cities" << endl;
    }

    startcity->visited=true;
    startcity->distance=0;

    queue<vertex*> q;
    vertex *a;
    q.push(startcity);
    while(!q.empty()){
        a=q.front();
        q.pop();

        if(a->name==endingCity){
            cout <<"Final City: " << a->name << " Distance: " << a->distance << endl;
            return;
        }
        for(int x=0; x<a->adj.size(); ++x){
            if(!a->adj[x].v->visited){
                a->adj[x].v->visited=true;
                a->adj[x].v->distance=a->distance+1;
                //cout << a->adj[x].v->name << endl;
                q.push(a->adj[x].v);
            }
        }
    }
}

void Graph::shortestDistance(string startingCity, string endingCity){

    for(int z=0; z< vertices.size(); ++z){
        vertices[z].visited=false;
    }

    vertex *startcity;
    vertex *endcity;
    bool citystartfound=false;
    bool cityendfound=false;

    for(int i=0; i<vertices.size(); ++i){
        if(startingCity == vertices[i].name){
            startcity=&vertices[i];
            citystartfound=true;
        }
        if(endingCity == vertices[i].name){
            endcity=&vertices[i];
            cityendfound=true;
        }
    }
    if(citystartfound==false || cityendfound ==false){
        cout << "One or more cities doesn't exist" << endl;
        return;
    }
    if(startcity->ID==-1 || endcity->ID==-1){
        cout << "Please identify the districts before checking distances" << endl;
    }
    if(startcity->ID != endcity->ID){
        cout << "No safe path between cities" << endl;
    }

    startcity->visited=true;
    startcity->distance=0;
    vector<vertex*> solved;
    solved.push_back(startcity);
    vertex *prev;

    while(!endcity->visited){
        int minDistance = INT_MAX;
        vertex *solvedV=NULL;
        for(int x=0; x<solved.size(); ++x){
            vertex *s=solved[x];
            for(int y=0; y<s->adj.size(); ++y){
                if(!s->adj[y].v->visited){
                    s->adj[y].v->distance = s->distance + s->adj[y].weight;
                    if(s->adj[y].v->distance < minDistance){
                        solvedV=s->adj[y].v;
                        minDistance = s->adj[y].v->distance;
                        s->adj[y].v->previous=s;
                        prev=s;
                    }
                }
            }
        }
        solvedV->distance=minDistance;
        solvedV->previous=prev;
        solvedV->visited=true;
        solved.push_back(solvedV);
    }

    vertex *walker=endcity;
    vector <vertex*> thecout;
    while(walker != startcity->previous){
        thecout.push_back(walker);
        walker=walker->previous;
    }

    cout << "Shortest Path" << endl;
    cout << thecout[thecout.size()-1]->name;
    for(int h=thecout.size()-2; h>-1; h--){
        cout << " - " << thecout[h]->name;
    }
    cout << "\nMinimum Distance: " << endcity->distance << endl;



}

void Graph::printnearestcities(std::string currentcity){

    vertex tmp;
    int i=0;
    tmp=vertices[i];

    while(tmp.name!=currentcity){
        tmp=vertices[i];
        ++i;
    }
    cout << tmp.adj[0].v->name;
    for(int j=1; j<tmp.adj.size()-1; ++j){
        cout << ", " << tmp.adj[j].v->name;
    }
    cout << ", and " << tmp.adj.back().v->name << "." << endl;

}

std::string Graph::movecity(std::string currentcity, std::string newcity){

    vertex *tmp=new vertex;
    int i=0;
    tmp=&vertices[i];

    while(tmp->name!=currentcity){
        tmp=&vertices[i];
        ++i;
    }

    vector<vertex*> adjcities;

    for(int j=0; j<tmp->adj.size(); ++j){
            adjcities.push_back(tmp->adj[j].v);
    }

    for(int k=0; k<adjcities.size(); ++k){
        if(adjcities[k]->name==newcity){
            return newcity;
        }
    }

    return "NotACity";

}
