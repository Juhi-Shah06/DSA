// Selection Sort
// Time complexity: O(n^2)
// Space complexity: O(1)

#include <iostream>
using namespace std;
int main()
{
    int n;
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
    int i, j, min;
    for (i = 0; i < n; i++) // number of passes
    {
        min = i;
        for (j = i + 1; j < n; j++) // comparisons
            if (a[j] > a[min])
                min = j;
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    cout << "\n The sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
