/*Problem Statement: This problem has 3 variations. They are stated below:
Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:
      1
     1 1
    1 2 1
   1 3 3 1
  1 4 6 4 1
1 5 10 10 5 1

Example 1:
Input Format:
 N = 5, r = 5, c = 3
Result:
 6 (for variation 1)
1 4 6 4 1 (for variation 2)
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1    (for variation 3)

Explanation:
 There are 5 rows in the output matrix. Each row is formed using the logic of Pascal’s triangle.

Example 2:
Input Format:
 N = 1, r = 1, c = 1
Result:
 1 (for variation 1)
 1 (for variation 2)
 1 (for variation 3)
Explanation:
 The output matrix has only 1 row.
*/

// Variation 1

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int r, c;
  cout << "Enter the row number: ";
  cin >> r;
  cout << "Enter the column number: ";
  cin >> c;

  long long res = 1;
  for (int i = 0; i < c - 1; i++)
  {
    res = res * (r - 1 - i);
    res = res / (i + 1);
  }

  cout << "The element at position (r, c) is: " << res << endl;
  return 0;
}

// Variation 2

int main()
{

  int n;
  cout << "Enter the row number: ";
  cin >> n;

  long long ans = 1;
  cout << ans << " ";
  for (int i = 1; i < n; i++)
  {
    ans = ans * (n - i);
    ans = ans / i;
    cout << ans << " ";
  }
  cout << endl;

  return 0;
}

// Variation 3

int main()
{
  int n;
  cout << "Enter the number of rows for Pascal's Triangle: ";
  cin >> n;

  vector<vector<int>> pascalTriangle;
  for (int row = 1; row <= n; row++)
  {
    vector<int> currentRow;
    long long ans = 1;
    currentRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
      ans = ans * (row - col);
      ans = ans / col;
      currentRow.push_back(ans);
    }
    pascalTriangle.push_back(currentRow);
  }
  for (auto &it : pascalTriangle)
  {
    for (auto ele : it)
    {
      cout << ele << " ";
    }
    cout << endl;
  }
  return 0;
}
