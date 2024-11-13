/*Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Example 1:
Input:
 prices = [7,1,5,3,6,4]
Output:
 5
Explanation:
 Buy on day 2 (price = 1) and
sell on day 5 (price = 6), profit = 6-1 = 5.

Note
: That buying on day 2 and selling on day 1
is not allowed because you must buy before
you sell.

Time complexity: O(n^2)          [Brute force approach]
Space Complexity: O(1)

Time complexity: O(n)            [optimal approach]
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[50];
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max_profit = 0;
    int min_price = arr[0];
    for (int i = 0; i < n; i++)
    {
        int cost = arr[i] - min_price;
        max_profit = max(max_profit, cost);
        min_price = min(min_price, arr[i]);
    }
    cout << "The maximum profit is: " << max_profit;
    return 0;
}