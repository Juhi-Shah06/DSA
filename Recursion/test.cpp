#include <iostream>
using namespace std;

int count = 0;
void print()
{
    if (count == 3)
    {
        return;
    }
    else
    {
        cout << count << endl;
        count++;
        print();
    }
}

int main()
{
    print();
    return 0;
}