/* STL:
 MULTISET: sorted elements but not unique
 Time complexity: O(log n)
*/

#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<int> ms;
    ms.emplace(2); //{2}
    ms.insert(2);  //{2,2}
    ms.insert(2);  //{2,2,2}
    ms.emplace(2); //{2,2,2,2}

    ms.erase(2); // all the occurences of 2 are erased

    int count = ms.count(2); // counts the number of 2's in the multiset

    //  if we want to erase only 1 occurence of 2
    ms.erase(ms.find(2)); // find is function of iterator so it will find the first occurence/address of 2 and delete it.

    ms.erase(ms.find(2), ms.find(2)+2); // find the first occurence of 2 and go till the second occurence of 2 and delete them both.

    // rest all functions and operations are same like set
}