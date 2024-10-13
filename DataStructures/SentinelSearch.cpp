#include <iostream>
using namespace std;
int main()
{
    int i, n, key;
    cout << "Enter the number of elements in the array " << endl;
    cin >> n;
    int a[50];
    cout << "Enter the elements in the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element you want to search in the array " << endl;
    cin >> key;
    int last = a[n - 1];
    a[n - 1] = key;
    i = 0;
    while (a[i] != key)
    {
        i++;
    }
    if (last == key || i < n - 1)
    {
        cout << "present " << endl;
    }
    else
    {
        cout << "not present " << endl;
    }
    return 0;
}