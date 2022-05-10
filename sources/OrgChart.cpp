#include "OrgChart.hpp"

namespace ariel
{

    OrgChart::OrgChart() {}

    OrgChart &OrgChart::add_root(string ceo)
    {
        return *this;
    }

    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        return *this;
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
