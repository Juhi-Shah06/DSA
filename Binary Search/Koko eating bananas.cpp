/*Koko Eating Bananas
Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

Example 1:
Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
Result: 5
Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.

Example 2:
Input Format: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
Result: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.

Before moving on to the solution, let’s understand how Koko will eat the bananas. Assume, the given array is {3, 6, 7, 11} and the given time i.e. h is 8.

First of all, Koko cannot eat bananas from different piles. He should complete the pile he has chosen and then he can go for another pile.
Now, Koko decides to eat 2 bananas/hour. So, in order to complete the first he will take
3 / 2 = 2 hours. Though mathematically, he should take 1.5 hrs but it is clearly stated in the question that after completing a pile Koko will not consume more bananas in that hour. So, for the first pile, Koko will eat 2 bananas in the first hour and then he will consume 1 banana in another hour.
From here we can conclude that we have to take ceil of (3/2). Similarly, we will calculate the times for other piles.

1st pile: ceil(3/2) = 2 hrs
2nd pile: ceil(6/2) = 3 hrs
3rd pile: ceil(7/2) = 4 hrs
4th pile: ceil(11/2) = 6 hrs
Koko will take 15 hrs in total to consume all the bananas from all the piles.

Observation: Upon observation, it becomes evident that the maximum number of bananas (represented by 'k') that Koko can consume in an hour is obtained from the pile that contains the largest quantity of bananas. Therefore, the maximum value of 'k' corresponds to the maximum element present in the given array.

So, our answer i.e. the minimum value of ‘k’ lies between 1 and the maximum element in the array i.e. max(a[]).

[Brute Force Approach]
Time Complexity: O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are running nested loops. The outer loop runs for max(a[]) times in the worst case and the inner loop runs for N times.
Space Complexity: O(1) as we are not using any extra space to solve this problem.

[Optimal Approach]
Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

// Brute force approach

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findMax(const vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(const vector<int> &v, int hourly)
{
    int totalHours = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        totalHours += ceil((double)v[i] / hourly);
    }
    return totalHours;
}
int main()
{
    int n, h;
    cout << "Enter the number of piles: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the number of bananas in each pile: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Enter the total hours available: ";
    cin >> h;
    int maxBananas = findMax(v);
    int answer = maxBananas;

    for (int rate = 1; rate <= maxBananas; rate++)
    {
        int requiredTime = calculateTotalHours(v, rate);
        if (requiredTime <= h)
        {
            answer = rate;
            break;
        }
    }
    cout << "Koko should eat at least " << answer << " bananas/hr." << endl;
    return 0;
}

// Optimal approach

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findMax(const vector<int> &v)
{
    int maxi = INT_MIN;
    for (int num : v)
    {
        maxi = max(maxi, num);
    }
    return maxi;
}
int calculateTotalHours(const vector<int> &v, int hourly)
{
    int totalHours = 0;
    for (int bananas : v)
    {
        totalHours += ceil((double)bananas / hourly);
    }
    return totalHours;
}
int main()
{
    int n, h;
    cout << "Enter the number of piles: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the number of bananas in each pile: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Enter the total hours available: ";
    cin >> h;
    int low = 1, high = findMax(v);
    int answer = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalHours = calculateTotalHours(v, mid);
        if (totalHours <= h)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "Koko should eat at least " << answer << " bananas/hr." << endl;
    return 0;
}
