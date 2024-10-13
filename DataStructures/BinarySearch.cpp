#include <iostream>
using namespace std;
int main()
{
    int n, low = 0, high;
    cout << "Enter the number of elements in the array " << endl;
    cin >> n;
    high = n - 1;
    int a[50];
    cout << "Enter the elements in the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cout << "Enter the element you want to search " << endl;
    cin >> x;
    while (low <= high)
    {
        int mid;
        mid = (high + low) / 2;
        if (a[mid] == x)
        {
            cout << "Element is found at position" << mid << endl;
            exit(0);
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
    }
    if (low > high)
        cout << "Element is not found " << endl;
    return 0;
}