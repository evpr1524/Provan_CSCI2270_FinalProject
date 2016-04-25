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



class Resources
{
    public:
        Resources();
        virtual ~Resources();
        void addpartymember(std::string username, int userage);
    protected:
    private:
        std::vector<person*> partylist;
};

#endif // RESOURCES_H
