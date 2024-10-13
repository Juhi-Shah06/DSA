#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
class BT
{
public:
    node *root;
    void create();
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    void insert(node *, node *);
    BT()
    {
        root = NULL;
    }
};
void BT::create()
{
    int val;
    node *temp;
    cout << "Enter value " << endl;
    cin >> val;
    temp = new node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        insert(root, temp);
    }
}
void BT::insert(node *root, node *temp)
{
    char pos;
    cout << "Current root is " << root->data;
    cout << "Enter position ";
    cin >> pos;
    if (pos == 'L' || pos == 'l')
    {
        if (root->left == NULL)
            root->left = temp;
        else
            insert(root->left, temp);
    }
    else if (pos == 'R' || pos == 'r')
    {
        if (root->right == NULL)
            root->right = temp;
        else
            insert(root->right, temp);
    }
    else
    {
        cout << "Invalid input " << endl;
    }
}

void BT::inorder(node *temp)
{
    if (temp != NULL)
        inorder(temp->left);
    cout << " " << temp->data;
    inorder(temp->right);
}
void BT::preorder(node *temp)
{
    if (temp != NULL)
        cout << " " << temp->data;
    preorder(temp->left);
    preorder(temp->right);
}
void BT::postorder(node *temp)
{
    if (temp != NULL)
        postorder(temp->left);
    postorder(temp->right);
    cout << " " << temp->data;
}
int main()
{
    int ch;
    BT b;
    cout << "*****Welcome to Binary tree*****" << endl;
    cout << "1.Create " << endl;
    cout << "2.Preorder Traversal " << endl;
    cout << "3.Inorder Traversal " << endl;
    cout << "4.Postorder Traversal " << endl;
    cout << "5.Exit" << endl;
    do
    {
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.create();
            break;
        case 2:
            b.preorder(b.root);
            break;
        case 3:
            b.inorder(b.root);
            break;
        case 4:
            b.postorder(b.root);
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Invalid input";
            break;
        }
    } while (ch != 5);
    return 0;
}
