#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace ariel
{

    class OrgChart
    {
    private:
        struct Node
        {
            string _duty;
            Node *manager;
            std::vector<Node*> _employees;
        };
        string _boss;
        map<string, Node*> chart;

    public:
        OrgChart();
        OrgChart &add_root(string ceo);
        OrgChart &add_sub(string parent, string child);
        friend std::ostream &operator<<(std::ostream &out, const OrgChart &tree)
        {
            return out;
        }

        class iterator
        {
        private:
            Node *curr_node;
            std::vector<Node *> tree_as_vector;
            unsigned i = 0;
            int flag;

        public:
            iterator(Node *ptr = nullptr) : curr_node(ptr) {}
            void Inorder(Node *node);
            void Preoder(Node *node);
            void Postorder(Node *node);

            string &operator*() const { return curr_node->_duty; }
            string *operator->() const { return &(curr_node->_duty); }
            iterator &operator++()
            {
                curr_node = tree_as_vector.at(++i);
                return *this;
            }

            bool operator==(const iterator &it) { return this->curr_node == it.curr_node; }
            bool operator!=(const iterator &it) { return this->curr_node != it.curr_node; }
        };

        iterator begin_level_order();
        iterator end_level_order();
        iterator begin_reverse_order();
        iterator end_reverse_order();
        iterator begin_preorder();
        iterator end_preorder();
        iterator begin();  // need to use find() that return iterator..
        iterator end();
    };

}