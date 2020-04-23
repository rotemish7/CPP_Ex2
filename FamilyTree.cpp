#include <iostream>
#include "FamilyTree.hpp"

using namespace std;

namespace family
{

    /**
     *
     * @param name
     * @param node
     * @return
     */
    Tree* Tree::search(string name, Tree* node)
    {
        if(node == NULL) return NULL;
        if(node->name == name) return node;
        Tree* Father = search(name, node->father);
        Tree* Mother = search(name, node->mother);
        if(Father != NULL) return Father;
        if(Mother != NULL) return Mother;
        return NULL;
    }

    /**
     *
     * @param child
     * @param father
     * @return
     */
    Tree& Tree::addFather(string child, string father)
    {
        Tree* temp = search(child, this);
        if (temp == nullptr)
        {
            throw runtime_error("No such name");
        }
        else if (temp->father != nullptr)
        {
            throw runtime_error("Already has a father");
        }
        else
        {
            temp->father = new Tree(father);
            temp->father->child = temp;
        }
        return *this;
    }

    /**
     *
     * @param child
     * @param mother
     * @return
     */
    Tree& Tree::addMother(string child, string mother)
    {
        Tree* temp = search(child, this);
        if (temp == NULL)
        {
            throw runtime_error("No such name");
        }
        else if (temp->mother != NULL)
        {
            throw runtime_error("Already has a mother");
        }
        else
        {
            temp->mother = new Tree(mother);
            temp->mother->child = temp;
        }
        return *this;
    }

    /**
     *
     * @param name
     * @return
     */
    string Tree::relation(string name)
    {
        Tree *temp = search(name,this);
        Tree *ans = temp;

        if(temp == this)
        {
            return "me";
        }
        if(temp == NULL)
        {
            return "unrelated";
        }
        int count = 0;
        string name_relation  = "";
        string relation[] = {"", "grand", "great-grand"};
        while (temp != this)
        {
            count++;
            temp = temp->child;
        }
        while(count>3)
        {
            name_relation+="great-";
            count--;
        }
        ans = ans->child;
        if(ans->father != NULL && ans->father->name.compare(name) == 0)
        {
            name_relation+=relation[count-1];
            return name_relation+="father";
        }
        else if(ans->mother != NULL && ans->mother->name.compare(name) == 0)
        {
            name_relation+=relation[count-1];
            return name_relation+="mother";
        }
        return NULL;
    }

    /**
     *
     * @param relation
     * @return
     */
    string Tree::find(string relation)
    {
        if(relation.compare("me") == 0)
        {
            return this->name;
        }
        else if(relation.compare("father") == 0 )
        {
            if(this->father != NULL)
            {
                return this->father->name;
            }
            throw runtime_error("No such relationship");
        }
        else if(relation.compare("mother") == 0)
        {
            if(this->mother != NULL)
            {
                return this->mother->name;
            }
            throw runtime_error("No such relationship");
        }
        else if(relation.compare("grandmother") == 0)
        {
            if(this->father != NULL && this->father->mother != NULL)
                return this->father->mother->name;
            else if(this->mother != NULL && this->mother->mother != NULL)
                return this->mother->mother->name;
            else throw runtime_error("No such relationship");
        }
        else if(relation.compare("grandfather") == 0)
        {
            if(this->father != NULL && this->father->father != NULL)
                return this->father->father->name;
            else if(this->mother != NULL && this->mother->father != NULL)
                return this->mother->father->name;
            else throw runtime_error("No such relationship");
        }
        else if(relation.find("great-") == 0)
        {
            size_t found = relation.find("great-");
            int count=3;
            Tree* temp = this;
            found = relation.find("great-",found+1,6);
            while(found != string::npos)
            {
                count++;
                found = relation.find("great-",found+1,6);
            }
            if(relation.find("mother") != string::npos)
            {
                string str = findH(count, this, 1);
                if (str == "NULL")
                {
                    throw runtime_error("No such relationship");
                }
                return str;
            }
            else if(relation.find("father") != string::npos)
            {
                string str = findH(count, this, 0);
                if (str == "NULL")
                {
                    throw runtime_error("No such relationship");
                }
                return str;
            }
        }
        else throw runtime_error("No such relationship");
        return NULL;
    }

    /**
     *
     * @param count
     * @param leaf
     * @param type
     * @return
     */
    string Tree::find_help(int count, Tree* temp, int type)
    {
        if(temp == NULL) return "NULL";
        if(count == 1)
        {
            if(type==1 && temp->mother != NULL)
            {
                return temp->mother->name;
            }
            else if(type==0 && temp->father != NULL)
            {
                return temp->father->name;
            }
            else return "NULL";
        }
        string father_T = findH(count-1, temp->father, type);
        string mother_T = findH(count-1, temp->mother, type);
        if(mother_T.compare("NULL"))
        {
            return mother_T;
        }
        return father_T;
    }

    /**
     *
     * @param name
     */
    void Tree::remove(string name)
    {
        Tree* temp = search(name, this);

        if(temp == NULL)
        {
            throw runtime_error("No such name");
        }
        else if(temp->name.compare(this->name) == 0)
        {
            throw runtime_error("Root can't be deleted");
        }
        else
        {
            Tree* temp2 = temp->child;
            if(temp != NULL)
            {
                if(temp2->father != NULL && temp2->father->name == name)
                {
                    temp2->father=NULL;
                }
                else if (temp2->mother != NULL && temp2->mother->name == name)
                {
                    temp2->mother=NULL;
                }
                delete temp;
            }
        }
    }

    /**
     *
     */
    void Tree::display()
    {
        print2DUtil(this, 0);
    }

    // https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    /**
     *
     * @param root
     * @param space
     */
    void Tree::print2DUtil(Tree *root, int space)
    {
        if (root == NULL)          // Base case
            return;
        space += 10;          // Increase distance between levels
        print2DUtil(root->father, space);        // Process right child
        cout << endl;          // Print current node after space
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << root->name << "\n";
        print2DUtil(root->mother, space);          // Process left child
    }
};
