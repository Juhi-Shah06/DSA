#include <iostream>
using namespace std;
class LQueue
#define size 6
{
public:
    int queue[size], front, rear;
    void enqueue();
    void dequeue();
    bool isFull();
    bool isEmpty();
    void display();
    LQueue()
    {
        front = -1;
        rear = -1;
    }
};
bool LQueue::isFull()
{
    if (rear == size - 1)
        return true;
    else
        return false;
}
bool LQueue::isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}
void LQueue::enqueue()
{
    int val;
    if (isFull())
    {
        cout << "The queue is full " << endl;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        cout << "Enter value " << endl;          
        cin >> val;
        queue[rear] = val;
    }
    else
    {
        rear++;
        cout << "Enter value " << endl;
        cin >> val;
        queue[rear] = val;
    }
}
void LQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "The queue is empty " << endl;
    }
    else if (front == rear)
    {
        cout << "The element is deleted " << endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout << "Element deleted from front " << endl;
        front++;
    }
}
void LQueue::display()
{
    if (isEmpty())
    {
        cout << "The queue is empty " << endl;
    }
    else
    {
        cout << "The elements of the queue are : ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}
int main()
{
    LQueue q;
    int ch;
    cout << "1).Insert element " << endl;
    cout << "2).Delete element " << endl;
    cout << "3).Display elements " << endl;
    cout << "4).Exit " << endl;
    do
    {
        cout << "Enter your choice " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Invalid choice " << endl;
            break;
        }
    } while (ch != 4);
}