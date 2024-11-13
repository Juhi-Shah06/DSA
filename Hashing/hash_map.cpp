/*Program to demonstrate number hashing.
Ordered Map: Time complexity: O(log N)
Unordered Map: Time complexity: O(1)   [ best and average case   (most of the times 99.5% it is this)]
                              : O(N)   [ Worst case ]
*/

#include <iostream>
#include <map>
// #include <unordered_map>
using namespace std;

int main()
{
    // hash
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[50];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    map<int, int> mp;             //unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp) // to iterate on the map, to know key->value pair
    {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cout << "Enter the number of queries you want to  make: ";
    cin >> q; // This part reads an integer `q` from the user, which represents the number of queries the user wants to make.
    cout << "Enter the numbers for which you want to make the query: ";
    for (int i = 0; i < q; i++)
    {

        int num;
        cin >> num;
        // fetch
        cout << mp[num];
    }
}