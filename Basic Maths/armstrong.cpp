#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, num;
    cout << "Enter a number: ";
    cin >> n;
    num = n;
    while (n > 0)
    {
        int r = n % 10;
        sum = sum + (r * r * r);
        n = n / 10;
    }
    if (num == sum)
    {
        cout << "Armstrong number";
    }
    else
    {
        cout << "Not armstrong number";
    }
}