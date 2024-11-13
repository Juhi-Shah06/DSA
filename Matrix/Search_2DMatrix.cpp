/*Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
Example 1:
Input Format:
N = 3, M = 4, target = 8,
mat[] = 1 2 3 4
        5 6 7 8
        9 10 11 12
Result: true
Explanation: The ‘target’  = 8 exists in the 'mat' at index (1, 3).

Example 2:
Input Format:
 N = 3, M = 3, target = 78,
mat[] = 1 2 4
        6 7 8
        9 10 34
Result: false
Explanation: The ‘target' = 78 does not exist in the 'mat'. Therefore in the output, we see 'false'.

Time Complexity: O(N X M), where N = given row number, M = given column number.       [Brute Force approach]
Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively.
Space Complexity: O(1) as we are not using any extra space.

Time Complexity: O(N + logM), where N = given row number, M = given column number.     [Better approach]
Reason: We are traversing all rows and it takes O(N) time complexity. But for all rows, we are not applying binary search rather we are only applying it once for a particular row. That is why the time complexity is O(N + logM) instead of O(N*logM).
Space Complexity: O(1) as we are not using any extra space.

Time Complexity: O(log(NxM)), where N = given row number, M = given column number.      [Optimal approach]
Reason: We are applying binary search on the imaginary 1D array of size NxM.
Space Complexity: O(1) as we are not using any extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force approach
int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    int matrix[10][10];
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "\nmatrix[" << i << "][" << j << "]=  ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nThe 2-D Array is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    int key;
    cout << "Enter the element you want to search in the matrix: ";
    cin >> key;
    bool flag = false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == key)
            {
                cout << "Element found at position (" << i << ", " << j << ").\n";
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (!flag)
        cout << "Element not found in the matrix.\n";
    return 0;
}

// Better approach
int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    int matrix[10][10];
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "\nmatrix[" << i << "][" << j << "]=  ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nThe 2-D Array is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    int key;
    cout << "Enter the element you want to search in the matrix: ";
    cin >> key;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] <= key && key <= matrix[i][m - 1])
        {
            int low = 0, high = m - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (matrix[i][mid] == key)
                {
                    cout << "Element found in row " << i << ".\n";
                    found = true;
                    break;
                }
                else if (key > matrix[i][mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            if (found)
                break;
        }
    }
    if (!found)
        cout << "Element not found in the matrix.\n";
    return 0;
}

// Optimal approach
int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    int matrix[10][10];
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "\nmatrix[" << i << "][" << j << "]=  ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nThe 2-D Array is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    int key;
    cout << "Enter the element you want to search in the matrix: ";
    cin >> key;
    bool found = false;
    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;

        if (matrix[row][col] == key)
        {
            found = true;
            break;
        }
        else if (matrix[row][col] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    found == true ? cout << "true\n" : cout << "false\n";
    
    return 0;
}