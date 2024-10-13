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
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << key << " is present in the array " << endl;
            break;
        }
    }
    if (i == n)
    {
        cout << "The element is not present in the array " << endl;
    }
    return 0;
}