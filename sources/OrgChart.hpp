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
        int modeCount; // count every change in the chart
        int level_count; // 
        int reverse_count;
        int pre_count;
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
        string *reverse_order();
        string *begin_preorder();
        string *end_preorder();
        string *begin(); 
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