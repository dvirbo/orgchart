#include "OrgChart.hpp"

namespace ariel
{

    OrgChart &OrgChart::add_root(string ceo)
    {// if the chart already has a root - replace the mame..
        if (!chart.empty()) 
        {
            this->_boss = ceo;
        }
        this->_boss = ceo; // init the boss
        Node *temp;
        temp->manager = nullptr;
        temp->_duty = ceo;
        this->chart.insert(make_pair(ceo, temp));
    }

    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        if (chart.empty())
        {
            throw invalid_argument("root don't exist");
        }
        Node *temp;
        Node *p = this->chart.at(parent);
        temp->manager = p;
        temp->_duty = child;
        this->chart.at(parent)->_employees.push_back(temp);
        this->chart.insert(make_pair(child, temp));
    }

    OrgChart::iterator OrgChart::begin_level_order()
    {
        return iterator();
    }

    OrgChart::iterator OrgChart::end_level_order()
    {
        return iterator();
    }

    OrgChart::iterator OrgChart::begin_preorder()
    {
        return iterator();
    }

    OrgChart::iterator OrgChart::end_preorder()
    {
        return iterator();
    }

    OrgChart::iterator OrgChart::begin_reverse_order()
    {
        return iterator();
    }

    OrgChart::iterator OrgChart::end_reverse_order()
    {
        return iterator();
    }

    void OrgChart::iterator::Inorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
    }

    void OrgChart::iterator::Preoder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
    }

    void OrgChart::iterator::Postorder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
    }

} // namespace ariel
