// Bubble sort using iteration
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
    cout << endl;
    cout << " \n FOR ASCENDING ORDER " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

        cout << "\n The sorted array is " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }

    cout << "\n FOR DESCENDING ORDER  " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp;
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }

        cout << "\n The sorted array is " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
}