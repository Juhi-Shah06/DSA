/*Set Matrix Zero
Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
Example 1:
Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

Example 2:
Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Explanation: Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0.

BRUTE FORCE APPROACH
Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)). Another O(N*M) is taken to mark all the cells with -1 as 0 finally.
Space Complexity: O(1) as we are not using any extra space.

BETTER APPROACH
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.
Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: O(N) is for using the row array and O(M) is for using the col array.

OPTIMAL APPROACH
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.
Space Complexity: O(1) as we are not using any extra space.*/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force approach
// int main()
// {
//     int n, m;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     cout << "Enter the number of columns: ";
//     cin >> m;
//     vector<vector<int>> matrix(n, vector<int>(m));
//     cout << "Enter the elements of the matrix:" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 for (int k = 0; k < m; k++)
//                 {
//                     if (matrix[i][k] != 0)
//                     {
//                         matrix[i][k] = -1;
//                     }
//                 }
//                 for (int k = 0; k < n; k++)
//                 {
//                     if (matrix[k][j] != 0)
//                     {
//                         matrix[k][j] = -1;
//                     }
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == -1)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     cout << "The Final matrix is: \n";
//     for (auto it : matrix)
//     {
//         for (auto ele : it)
//         {
//             cout << ele << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// Better approach
// int main()
// {
//     int n, m;
//     cout << "Enter the number of rows: ";
//     cin >> n;
//     cout << "Enter the number of columns: ";
//     cin >> m;
//     vector<vector<int>> matrix(n, vector<int>(m));
//     cout << "Enter the elements of the matrix:" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }
//     int row[50] = {0};
//     int col[50] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (row[i] == 1 || col[j] == 1)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     cout << "The Final matrix is: \n";
//     for (auto it : matrix)
//     {
//         for (auto ele : it)
//         {
//             cout << ele << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// Optimal Approach
