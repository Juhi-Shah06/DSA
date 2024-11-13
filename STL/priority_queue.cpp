/* STL
PRIORITY QUEUE: The largest number remains at the top or first in the queue.
Time complexity: Push and Pop operations - O(log n)   Top - O(1)
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Maximum heap
    priority_queue<int> pq;
    pq.push(1);    //{1}
    pq.push(2);    //{2,1}
    pq.push(0);    //{0,2,1}
    pq.emplace(5); //{5,0,2,1}

    cout << pq.top();

    pq.pop();

    cout << pq.top();

    // size, swap, empty same as stack and queue

    // if we want the queue to store minimum element at top
    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);    //{1}
    pq.push(2);    //{1,2}
    pq.push(0);    //{0,1,2}
    pq.emplace(5); //{0,1,2,5}

    cout << pq.top();

    pq.pop();

    cout << pq.top();
}