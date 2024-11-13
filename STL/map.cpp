/* STL:
 MAP: key value pairs. keys are unique. values can be repeated. Map stores unique keys in sorted order.
 Time complexity: O(log n)
*/

#include <bits/stdc++.h>
#include <map>
using namespace std;

int main()
{
    map<int, int> mp;             // syntax: map(key, value)
    map<pair<int, int>, int> mpp; // syntax: map(pair(key), value)
    map<int, pair<int, int>> mpa; // syntax: map(key, pair(value))

    // map<int, int> mp;
    mp[1] = 2;        // at key 1 store value 2 (in map it is stored as {1,2})
    mp.emplace(3, 1); // key 3 value 1 {3,1}
    mp.insert(2, 4);  // key 2 value 4 {2,4}
    // stored in sorted order hence: [{1,2},{2,4},{3,1}]

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl; // output-->{1 2}
    }
    // map<int, pair<int, int>> mp;
    mpp[{2, 3}] = 10; // key 2,3 value 10  {{2,3},10}

    cout << mp[1];
    cout << mp[5];  // if an element does not exist, 0 is returned

    auto it = mp.lower_bound(2);
    auto it = mp.upper_bound(3);

    // swap, size, erase, empty are all the same

}