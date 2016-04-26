#ifndef RESOURCES_H
#define RESOURCES_H
#include <iostream>
#include <vector>

struct person{
    std::string name;
    int age;
};

struct weapon{
    std::string type;
    std::string name;
    int number;
};

struct inventory{
    int food=0;
    int water=0;
    std::vector<weapon> armory;
    std::vector<person> party;
};

struct info{
    std::string currentcity;
};



class Resources
{
    public:
        Resources();
        virtual ~Resources();
        void addpartymember(std::string username, int userage);
        void removepartymember(std::string username);
        void displayallmembers();
        std::string printcurrentcity();
        void move1city(std::string moveto);
        void printinventory();
        void addresource();
    protected:
    private:
        std::vector<person*> partylist;
        std::string currentcity;
        inventory i1;
};

#endif // RESOURCES_H
