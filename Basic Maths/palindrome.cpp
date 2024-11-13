// Time complexity: O(log n)

#include <iostream>
using namespace std;

int main()
{
    int n, num, rev = 0;
    cout << "Enter a number: ";
    cin >> n;
    num = n;

    while (n > 0)
    {
        int last_d = n % 10;
        rev = rev * 10;
        rev = rev + last_d;
        n = n / 10;
    }
    if (num == rev)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not palindrome";
    }
}