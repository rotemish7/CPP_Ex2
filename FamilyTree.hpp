//
// Created by rotem levy on 02/04/2020.
//

#ifndef ANCESTOR_TREE_FAMILYTREE_HPP
#define ANCESTOR_TREE_FAMILYTREE_HPP
#include <iostream>

using namespace std;

namespace family
{
    class Tree
    {
        string name;
        Tree* father;
        Tree* mother;
        Tree* child;

        public:

            Tree(string name)
            {
                this->name = name;
                this->mother = nullptr;
                this->father = nullptr;
                this->child = nullptr;
            }

            ~Tree()
            {
                delete this->father;
                delete this->mother;
            }

            Tree& addFather(string child,string father);
            Tree& addMother(string child,string mother);
            string relation(string name);
            string find(string relation);
            void remove(string name);
            void display();

        private:
            void print2DUtil(Tree *root, int space);
            Tree* search(string name, Tree* t);
            string findH(int count, Tree* temp, int type);
    };
}

#endif //ANCESTOR_TREE_FAMILYTREE_HPP
