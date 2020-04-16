//
// Created by rotem levy on 02/04/2020.
//

#ifndef ANCESTOR_TREE_FAMILYTREE_HPP
#define ANCESTOR_TREE_FAMILYTREE_HPP
#include <iostream>

using namespace std;

class node
{
    public:
        string name;
        node *mother;
        node *father;
        node(string name)
        {
            (*this).name=name;
            (*this).mother= nullptr;
            (*this).father= nullptr;
        }
};

namespace family
{
    class Tree
    {
        public:
            node *root;
            Tree(string name)
            {
                this->root = new node(name);
            }

            Tree& addFather(string child,string father);
            Tree& addMother(string child,string mother);
            string relation(string name);
            string find(string relation);
            bool remove(string name);
            void display();
    };
}

#endif //ANCESTOR_TREE_FAMILYTREE_HPP
