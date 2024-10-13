#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cout << "Enter the number of elements in the array " << endl;
    cin >> n;
    int a[50];
    cout << "Enter the elements in the array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "The unsorted array is " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 1; i < n; i++)
    {
        while (a[i] > a[i - 1] && i > 0)
        {
            int temp;
            temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
            i--;
        }
    }

    cout << "\nThe sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}