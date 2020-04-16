#include <iostream>
#include "FamilyTree.hpp"
using namespace std;

family::Tree &family::Tree::addFather(string child,string father)
{
    return *this;
}

family::Tree &family::Tree::addMother(string child,string mother)
{
    return *this;
}

string family::Tree::relation(string name)
{
    return "unrelated";
}

string family::Tree::find(string relation)
{
    return "find";
}

bool family::Tree::remove(string name)
{
    return true;
}

void family::Tree::display(){}

