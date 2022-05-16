#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace ariel
{
    struct Node
    {
        string _duty;
        std::vector<Node> _employees;
        int _dist;
    };

    class OrgChart
    {
    private:
        Node _root;
        int modeCount = 0;
        int level_count = -1;
        int reverse_count = -1;
        int pre_count = -1;
        std::vector<string> _level;
        std::vector<string> _reverse;
        std::vector<string> _pre;
        std::vector<Node> _print;


    public:
        OrgChart();
        OrgChart &add_root(string ceo);
        OrgChart &add_sub(string parent, string child);
        friend std::ostream &operator<<(std::ostream &out, OrgChart &tree);

        string *begin_level_order();
        string *end_level_order();
        string *begin_reverse_order();
        string *end_reverse_order();
        string *begin_preorder();
        string *end_preorder();
        string *begin(); // need to use find() that return string*..
        string *end();
        Node* begin_print();
        Node* end_print();
        bool find_child(Node &n, string &parent, string &chid);
        void init_level(Node &n);
        void init_reverse(Node &n);
        void init_pre(Node &n);
        void init_print(Node &n);
    };

}