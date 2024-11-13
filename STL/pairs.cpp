/*STL : Standard template library
It has many algorithms, libraries in it which can be used and make our tasks easier.
Pairs*/

#include <iostream>
using namespace std;

int main()
{
    pair<int, int> p = {1, 3};          // we can form pairs of similar data types when to want to store same data type values
    cout << p.first << " " << p.second; // the values can be accessed by using the dot(.) opeartor

    pair<int, pair<int, int>> x = {1, {2, 3}}; // we can also form pair inside a pair
    cout << x.first << " " << x.second.first << " ";

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}}; // pair of array can also be formed and can be accessed the way a normal is done
    cout << arr[1].second;
}