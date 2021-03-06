#include "OrgChart.hpp"
#include <queue>

namespace ariel
{
    OrgChart::OrgChart(/* args */)
    {
        this->modeCount = 0;
        this->level_count = -1;
        this->reverse_count = -1;
        this->pre_count = -1;
    }

    OrgChart &OrgChart::add_root(string ceo)
    {
        this->_root._duty = ceo; // init the root
        this->modeCount++;
        this->_root._dist = 0;
        return *this;
    }

    /*
    this recursive method help us to find the father of the node that we want to add
    */
    bool OrgChart::find_child(Node &n, string &parent, string &child)
    {
        Node nchild;
        if (n._duty.compare(parent) == 0)
        { // equals
            nchild._duty = child;
            nchild._dist = n._dist + 1; // inc the dist from the root
            n._employees.push_back(nchild);
            return true;
        }
        for (size_t i = 0; i < n._employees.size(); i++)
        {
            if (find_child(n._employees.at(i), parent, child))
            {
                return true;
            }
        }
        return false;
    }

    /*
    this method add node in the chart
    */
    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        if (this->_root._duty.empty())
        {
            throw invalid_argument("root don't exist");
        }
        // build the child node:

        if (!find_child(this->_root, parent, child))
        {
            throw runtime_error("parent don't exist");
        }

        this->modeCount++;
        return *this;
    }

    void OrgChart::init_level(Node &n)
    {
        queue<Node> remain;
        for (Node level : n._employees)
        {
            this->_level.push_back(level._duty);
            remain.push(level);
        }

        while (!remain.empty())
        {
            for (Node level : remain.front()._employees)
            {
                this->_level.push_back(level._duty);
                remain.push(level);
            }
            remain.pop();
        }
    }
    /*
    this method init the iterator that iterate in "level order"
    return pointer to the first element ("string") in the vector _level
    */
    string *OrgChart::begin_level_order()
    {
        if (this->level_count != this->modeCount)
        {
            this->_level.clear();
        }
        else
        {
            return this->_level.data(); // the vector didn't change
        }
        this->_level.push_back(this->_root._duty); // push the root
        init_level(_root);
        this->level_count = this->modeCount;

        return this->_level.data();
    }

    string *OrgChart::end_level_order()
    {
        size_t ind = this->_level.size();
        return &this->_level[ind];
    }

    /*
    this method recursivly iterate on the chart in preorder follows the Root Left Right policy
    */
    void OrgChart::init_pre(Node &n)
    {
        this->_pre.push_back(n._duty);
        for (size_t ind = 0; ind < n._employees.size(); ind++)
        {

            init_pre(n._employees.at(ind));
        }
    }
    /*
    this method init the iterator that iterate in "preorder"
    return pointer to the first element ("string") in the vector _pre
    */
    string *OrgChart::begin_preorder()
    {
        if (this->pre_count != this->modeCount)
        {
            this->_pre.clear();
        }
        else
        {
            return this->_pre.data(); // the vector didn't change
        }
        init_pre(this->_root);
        this->pre_count = this->modeCount;
        return this->_pre.data();
    }

    string *OrgChart::end_preorder()
    {
        if (this->_pre.empty())
        {
            throw "vector is empty";
        }
        size_t ind = this->_pre.size();
        return &this->_pre[ind];
    }
    /*
     after we insert the root
    */
    void OrgChart::init_reverse(Node &n)
    {
        for (auto it = n._employees.rbegin(); it != n._employees.rend(); it++) //insert (to begin()) the node child in reverse order
        {
            this->_reverse.insert(this->_reverse.begin(), (*it)._duty);
        }
        size_t ind = n._employees.size() - 1;
        for (auto it = n._employees.rbegin(); it != n._employees.rend(); it++) // recursive call on every child in reverse order
        {
            init_reverse(n._employees[ind]);
            ind--;
        }
    }
    /*
    this method init the iterator that iterate in "reverse order"
    return pointer to the first element ("string") in the vector _reverse
    */
    string *OrgChart::begin_reverse_order()
    {
        if (this->reverse_count != this->modeCount)
        {
            this->_reverse.clear();
        }
        else
        {
            return this->_pre.data(); // the vector didn't change
        }
        this->_reverse.push_back(this->_root._duty);
        init_reverse(this->_root);
        return this->_reverse.data();
    }

    string *OrgChart::reverse_order()
    {
        if (this->_reverse.empty())
        {
            throw "vector is empty";
        }
        size_t ind = this->_reverse.size();
        return &this->_reverse[ind];
    }

    string *OrgChart::begin()
    {
        return begin_level_order();
    } // need to use find() that return string*..
    string *OrgChart::end()
    {
        return end_level_order();
    }

    void OrgChart::init_print(Node &n)
    {
        queue<Node> remain;
        for (Node level : n._employees)
        {
            this->_print.push_back(level);
            remain.push(level);
        }

        while (!remain.empty())
        {
            for (Node level : remain.front()._employees)
            {
                this->_print.push_back(level);
                remain.push(level);
            }
            remain.pop();
        }
    }

    Node *OrgChart::begin_print()
    {
        this->_print.clear();
        this->_print.push_back(this->_root); // push the root
        init_print(_root);
        return this->_print.data();
    }

    Node *OrgChart::end_print()
    {
        size_t ind = this->_print.size();
        return &this->_print[ind];
    }

    std::ostream &operator<<(std::ostream &out, OrgChart &tree)
    {

        for (auto ind = tree.begin_print(); ind != tree.end_print(); ind++)
        {
            out << (*ind)._duty << " in level: " << (*ind)._dist;
            cout << endl;
        }
        return out;
    }

} // namespace ariel
