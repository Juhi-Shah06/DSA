#include <iostream>
using namespace std;

int main()
{
    int n, rev = 0;
    cout << "Enter a number: ";
    cin >> n;

    while (n > 0)
    {
        int last_d = n % 10;
        rev = rev * 10;
        rev = rev + last_d;
        n = n / 10;
        
    }
    cout << rev;
}