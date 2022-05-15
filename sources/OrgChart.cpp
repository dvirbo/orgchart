#include "OrgChart.hpp"
#include <queue>

namespace ariel
{
    OrgChart::OrgChart(/* args */)
    {
    }

    OrgChart &OrgChart::add_root(string ceo)
    {
        this->_root._duty = ceo; // init the root
        this->modeCount++;
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

    void OrgChart::init_level(Node n)
    {
        queue<Node> remain;
        for (Node level : n._employees)
        {
            this->_level.push_back(level._duty);
            remain.push(level);
        }

        while (!remain.empty())
        {
            // if (!remain.front()._employees.empty())

            for (Node level : remain.front()._employees)
            {
                this->_level.push_back(level._duty);
                //  cout << level._duty <<endl;
                remain.push(level);
            }
            remain.pop();
        }
    }

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
    void OrgChart::init_pre() ///////**
    {
        if (this->pre_count != this->modeCount)
        {
            this->_pre.clear();
        }
        else
        {
            return; // the vector didn't change
        }
    }

    string *OrgChart::begin_preorder()
    {
        init_pre();
        return this->_pre.data();
    }

    string *OrgChart::end_preorder()
    {
        init_pre();
        if (this->_pre.empty())
        {
            throw "vector is empty";
        }
        return &this->_pre.back();
    }

    void OrgChart::init_reverse() /////**
    {
        if (this->reverse_count != this->modeCount)
        {
            this->_reverse.clear();
        }
        else
        {
            return; // the vector didn't change
        }
    }

    string *OrgChart::begin_reverse_order()
    {
        init_reverse();
        return this->_reverse.data();
    }

    string *OrgChart::end_reverse_order()
    {
        init_reverse();
        if (this->_reverse.empty())
        {
            throw "vector is empty";
        }
        return &this->_reverse.back();
    }

} // namespace ariel
