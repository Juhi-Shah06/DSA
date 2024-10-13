#include <iostream>
using namespace std;
class CircularQ
#define size 5
{
    int cq[size], front, rear;

public:
    void enqueue();
    void dequeue();
    bool isFull();
    bool isEmpty();
    void display();
    CircularQ()
    {
        front = -1;
        rear = -1;
    }
};
bool CircularQ::isFull()
{
    if (front == 0 && rear == size - 1)
        return true;
    else if (front == rear + 1)
        return true;
    else
        return false;
}
bool CircularQ::isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}
void CircularQ::enqueue()
{
    int val;
    if (isFull())
    {
        cout << "Queue is full " << endl;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        cout << "Enter value " << endl;
        cin >> val;
        cq[rear] = val;
    }
    else
    {
        rear = (rear + 1) % size;
        cout << "Enter value " << endl;
        cin >> val;
        cq[rear] = val;
    }
}
void CircularQ::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty " << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        cout << "Element deleted from front " << endl;
        front = (front + 1) % size;
    }
}
void CircularQ::display()
{
    if (isEmpty())
    {
        cout << "empty";
    }

    else
    {
        for (int i = front; i < size; i++)
            cout << cq[i] << " ";

        for (int i = 0; i <= rear; i++)
            cout << cq[i] << " ";
    }
}

int main()
{ 
    CircularQ q;
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