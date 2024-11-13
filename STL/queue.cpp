/* STL:
 QUEUE: First In First Out [FIFO]
 Time Complexity: O(1)   all operations happen in constant time
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> qu;
    qu.push(1);    //{1}
    qu.push(2);    //{1,2}
    qu.emplace(3); //{1,2,3}

    qu.back() += 5; // the 5 added to the last number of the queue and replaced with the new number    {1,2,8}

    cout << qu.back();

    qu.pop(); // pops the first element in the queue   {2,8}

    cout << qu.front();   // prints 2

    // size, swap, empty all these are same as stack
}