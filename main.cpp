/**
 * main file for the exercise on iterators
 *
 * @author dvir borochov
 * @since 2022-05
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

int main()
{
    OrgChart chart;
    chart.add_root("A")
        .add_sub("A", "B")
        .add_sub("A", "F")
        .add_sub("B", "D")
        .add_sub("D", "E")
        .add_sub("D", "H");

    cout << chart << endl; // Prints the org chart in a reasonable format.

    for (auto it = chart.begin_level_order(); it != chart.end_level_order(); it++)
    {
        cout << (*it);
    }

    for (auto element : chart)
    { // this should work like level order
        cout << element << " ";
    } 
    cout << endl;
}

//clang++-9 main.cpp -o main
