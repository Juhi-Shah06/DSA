/* STL :
Lists */

#include <iostream>
#include <list>
using namespace std;

int main()
{
    // lists are dymanic in nature. lists is different from vectors as it allows front operations as well.
    list<int> ls;
    ls.push_back(1);     //{1}
    ls.emplace_front(0); //{0,1}
    ls.emplace_back(3);  // {0,1,3}
    ls.push_front(2);    //{2,0,1,3}

    // rest all functions are same as vectors : begin, end, insert, size, clear, empty, rend, rbegin, swap
    // for lists, doubly linked list is maintained since we can perform operations from both ends
}