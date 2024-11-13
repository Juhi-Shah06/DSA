/*At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

Example 1:
Input: bills = [5,5,5,10,20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

Time complexity: O(N)
N is the number of customers (or the size of the bills array). The program iterates over the bills array exactly once, processing each bill individually.
Space complexity: O(1)
The program uses a fixed amount of extra space regardless of the size of the input. */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of customers: ";
    cin >> n;
    vector<int> bills(n);
    cout << "Enter the bills given by the customers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> bills[i];
    }
    int five = 0, ten = 0;
    bool canGiveChange = true;
    for (int i = 0; i < n; i++)
    {
        if (bills[i] == 5)
        {
            five++;
        }
        else if (bills[i] == 10)
        {
            if (five == 0)
            {
                canGiveChange = false;
                break;
            }
            five--;
            ten++;
        }
        else
        {
            if (ten > 0 && five > 0)
            {
                ten--;
                five--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                canGiveChange = false;
                break;
            }
        }
    }
    if (canGiveChange)
    {
        cout << "True: All customers received correct change." << endl;
    }
    else
    {
        cout << "False: Unable to provide correct change for a customer." << endl;
    }
    return 0;
}
