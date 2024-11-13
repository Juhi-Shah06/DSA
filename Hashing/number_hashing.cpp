/*Program to demonstrate number hashing.*/

#include <iostream>
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
    int hash[13] = {0}; // initializes all the elements to 0.
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1; // In this loop, the program iterates through the elements of the input array (arr). For each element arr[i], it increments the value at the corresponding index in the hash array. This is how hashing is implemented - the value in arr[i] serves as the index in the hash array, and its frequency is incremented.
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
        cout << hash[num] << endl; // This while loop executes q times. In each iteration, it reads an integer num from the user. Then, it prints the value stored at index num in the hash array, which represents the frequency of occurrence of the number num in the input array.
    }
}