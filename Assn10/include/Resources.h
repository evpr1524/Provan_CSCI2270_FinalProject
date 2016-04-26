#ifndef RESOURCES_H
#define RESOURCES_H
#include <iostream>
#include <vector>

struct person{
    std::string name;
    int age;
};

struct inventory{
    int food;
    int water;
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

    protected:
    private:
        std::vector<person*> partylist;
        std::string currentcity;
};

#endif // RESOURCES_H
