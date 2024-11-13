/*Program to demonstrate character hashing.*/

//Method 1
#include <iostream>
using namespace std;

int main()
{
    // hash
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    // precompute
    int hash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i] - 'a'] += 1;
    }

    int q;
    cout << "Enter the number of queries you want to  make: ";
    cin >> q;
    cout << "Enter the characters for which you want to make the query: ";
    for (int i = 0; i < q; i++)
    {

        char c;
        cin >> c;
        // fetch
        cout << hash[c - 'a'] << endl;
    }
}


//Method 2
#include <iostream>
using namespace std;

int main()
{
    // hash
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    // precompute
    int hash[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]] += 1;
    }

    int q;
    cout << "Enter the number of queries you want to  make: ";
    cin >> q;
    cout << "Enter the characters for which you want to make the query: ";
    for (int i = 0; i < q; i++)
    {

        char c;
        cin >> c;
        // fetch
        cout << hash[c] << endl;
    }
}