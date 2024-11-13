/* STL:
 UNORDERED_SET: all the values are unique but not in sorted order
 Time complexity: O(1)
very rarely, worst case scenario: O(N)
*/

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{
    /*lower_bound and upper_bound functions do not work but rest all functions and operations are the same as set.
    Randomized order
    It has better complexity than set in most cases but sometimes collisions may happen.*/

    unordered_set<int> s;
    s.emplace(2); //{2}
    s.insert(1);  //{1,2}
    s.insert(4);  //{4,1,2}
    s.emplace(3); //{4,1,3,2}
    s.insert(1);  //{4,1,3,2}
}