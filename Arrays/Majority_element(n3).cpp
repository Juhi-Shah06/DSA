/*Majority Elements(>N/3 times). Find the elements that appears more than N/3 times in the array.
Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.
Example 1:
Input Format: N = 5, array[] = {1,2,2,3,2}
Result: 2
Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

Example 2:
Input Format:  N = 6, array[] = {11,33,33,11,33,11}
Result: 11 33
Explanation:
Here we can see that the Count(11) = 3 and Count(33) = 3. Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.

[Brute force approach]
Time complexity: O(N^2), where N = size of the given array.
Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N^2).
Space Complexity: O(1) as we are using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.

[Better approach]
Time Complexity: O(N*logN), where N = size of the given array.
Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN).
If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
Space Complexity: O(N) as we are using a map data structure. We are also using a list that stores a maximum of 2 elements. That space used is so small that it can be considered constant.

[Optimal Approach]
Time complexity: O(log N)
Space complexity: O(1)
*/

// Brute Force Approach

#include <iostream>
#include <vector>
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
    vector<int> ls;
    for (int i = 0; i < n; i++)
    {
        if (ls.size() == 0 || ls[0] != arr[i])
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == arr[i])
                {
                    count++;
                }
            }
            if (count > n / 3)
            {
                ls.push_back(arr[i]);
            }
        }
        if (ls.size() == 2)
            break;
    }
    cout << "The majority elements are: ";
    for (auto it : ls)
        cout << it << " ";
    cout << "\n";

    return 0;
}

// Better Approach

#include <map>
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
    vector<int> ls;
    map<int, int> mpp;

    int minimum = (n / 3) + 1;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if (mpp[arr[i]] == minimum)
        {
            ls.push_back(arr[i]);
        }
        if (ls.size() == 2)
            break;
    }
    cout << "The majority elements are: ";
    for (auto it : ls)
        cout << it << " ";
    cout << "\n";

    return 0;
}

// Optimal Approach

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
    vector<int> ls;

    int count1 = 0, count2 = 0;
    int element1 = 0;
    int element2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && element2 != arr[i])
        {
            count1 = 1;
            element1 = arr[i];
        }
        else if (count2 == 0 && element1 != arr[i])
        {
            count2 = 1;
            element2 = arr[i];
        }
        else if (arr[i] == element1)
            count1++;
        else if (arr[i] == element2)
            count2++;
        else
        {
            count1--, count2--;
        }
    }

    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element1)
            count1++;
        if (arr[i] == element2)
            count2++;
    }

    int mini = int(n / 3) + 1;
    if (count1 >= mini)
        ls.push_back(element1);
    if (count2 >= mini)
        ls.push_back(element2);

    cout << "The majority elements are: ";
    for (auto it : ls)
        cout << it << " ";
    cout << "\n";

    return 0;
}