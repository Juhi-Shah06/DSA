#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class CLL
{
    node *head, *last;

public:
    void create();
    void traverse();
    void search();
    void insert();
    void Delete();
    CLL()
    {
        head = NULL;
        last = NULL;
    }
};
void CLL::create()
{
    node *temp;
    int val;
    cout << "Enter value " << endl;
    cin >> val;
    temp = new node;
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
    last->next = head;
}
void CLL::traverse()
{
    node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
void CLL::search()
{
    int flag = 0;
    node *temp = head;
    int key;
    cout << "Enter the search element " << endl;
    cin >> key;
    if (temp != NULL)
    {
        do
        {
            if (temp->data == key)
            {
                cout << "found ";
                flag = 1;
                break;
            }
            else
            {
                temp = temp->next;
            }

        } while (temp != head);
        if (flag == 0)
        {
            cout << "not found ";
        }
    }
}
void CLL::insert()
{
    node *temp = head;
    int val, key;
    cout << "Enter new valuee" << endl;
    cin >> val;
    node *newNode;
    newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    if (temp != NULL)
    {
        int ch;
        cout << "where insert " << endl;
        cout << "1.start" << endl;
        cout << "2.end" << endl;
        cout << "3.middle" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            newNode->next = head;
            last->next = newNode;
            head = newNode;
            break;
        case 2:
            last->next = newNode;
            newNode->next = head;
            last = newNode;
            break;
        case 3:
            cout << "after which element insert " << endl;
            cin >> key;
            do
            {
                if (temp->data == key)
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            } while (temp != NULL);
        }
    }
}
    int main()
    {
        CLL cl;
        int ch;
        do
        {
            cout << "\n1.Create " << endl;
            cout << "2.Traverse " << endl;
            cout << "3.Search " << endl;
            cout << "4.Insert " << endl;
            cout << "5.Delete" << endl;
            cout << "6.Exit " << endl;
            cout << "Enter your choice " << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                cl.create();
                break;
            case 2:
                cl.traverse();
                break;
            case 3:
                cl.search();
                break;
            case 4:
                cl.insert();
                break;
            }
        } while (ch != 5);
    }