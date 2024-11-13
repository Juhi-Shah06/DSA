/*Problem Statement: You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Time Complexity: O(N) where 𝑛 is the number of digits in the input array. This is because the algorithm may need to iterate through the entire array in the worst case (for example, when all digits are 9, such as in [9, 9, 9]).
Space Complexity: O(1) (constant space)
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < 9)
        {
            arr[i]++;
            break;
        }
        arr[i] = 0;
    }
    if (arr[0] == 0)
    {
        arr.insert(arr.begin(), 1);
    }
    cout << "Resulting array after increment: ";
    for (int digit : arr)
    {
        cout << digit << " ";
    }
    cout << endl;
    return 0;
}
