/* STL:
 SET: everything is stored in sorted order, all values are unique(no repition).
 Time complexity: O(log n)
*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.emplace(2); //{2}
    s.insert(1);  //{1,2}
    s.insert(4);  //{1,2,4}
    s.emplace(3); //{1,2,3,4}

    /*Functionality of insert can also be used in vectors to increase efficiency. begin, end, rend, rbegin, size, empty, clear, swap all these are same for set.*/

    auto it = s.find(3);  // 3 will be returned
    auto it = s.find(5);  // if the element is not in the set, s.end will be returned. the place where s.end will be pointing, that will be returned.

    s.erase(3); // 3 will erased or deleted or removed from the queue
                // takes logarithmic time

    s.erase(it); // you can even give the address or the iterator of the number or element to be erased.

    s.count(1); // it will see whether that element is present or not. if present then returns 1 else returns 0.

    // {1,2,3,4,5}
    auto it1 = s.find(1);
    auto it2 = s.find(3);
    s.erase(it1, it2); // syntax: s.erase(first position(from where, included), last positon(till where, not included) , after erase the queue will be: {3,4,5}
     // lower_bound and upper_bound functions work in the same way


}