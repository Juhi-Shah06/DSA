/*Graph program - create,display,bfs,dfs */
/*BFS : it is breadth first search and a graph traversal technique. we use queue to remember
 the neighbours of the particular vertex.*/
#include <iostream>
using namespace std;
class graph
{
public:
    int G[20][20];
    int n, e; // n is number of vertices and e is edges
    int v1, v2;
    int queue[20];   // for bfs
    int front, rear; // bfs uses queue so for insertion and deletion front and rear
    int visit[20];   // keep track of vertices that are visited
    void create();
    void display();
    void add(int);
    int remove();
    void bfs();
    int top;
    int stack[20]; // for dfs
    void dfs();
    void push(int);
    int pop();

    graph()
    {
        n = e = 0;
        top = -1;
        front = rear = -1;
        for (int i = 1; i <= 10; i++) // i is number of rows
        {
            for (int j = 1; j <= 10; j++) // j is number of columns
            {
                G[i][j] = 0;
            }
        }
        for (int i = 1; i <= 10; i++)
            visit[i] = 0;
    }
};       
void graph::create()
{
    cout << "Enter the number of vertices " << endl;
    cin >> n;
    cout << "Enter the number of edges " << endl;
    cin >> e;
    for (int i = 1; i <= e; i++)
    {
        cout << "Enter an edge (vertex v1 and v2) " << endl;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
}
void graph::display()
{
    cout << "The adjacency matrix is : " << endl;
    for (int i = 1; i <= n; i++) // rows
    {
        cout << "\n";
        for (int j = 1; j <= n; j++) // columns
        {
            cout << " " << G[i][j];
        }
    }
}
void graph::bfs()
{
    cout << "Enter the starting vertex " << endl;
    cin >> v1;
    add(v1);
    while (front != rear)
    {
        v1 = remove();
        visit[v1] = 1;
        cout << " " << v1;
        for (v2 = 1; v2 <= n; v2++)
        {
            if (G[v1][v2] == 1 && visit[v2] == 0)
            {
                add(v2);
                visit[v2] = 1;
            }
        }
    }
}
void graph::add(int v1)
{
    queue[++rear] = v1;
}
int graph::remove()
{
    return queue[++front];
}
void graph::dfs()
{
    cout << "Enter starting vertex " << endl;
    cin >> v1;
    push(v1);
    while (top != -1)
    {
        v1 = pop();
        if (visit[v1] == 0)
        {
            cout << " " << v1;
            visit[v1] = 1;
            for (v2 = 1; v2 <= n; v2++)
            {
                if (G[v1][v2] == 1)
                {
                    push(v2);
                }
            }
        }
    }
}
void graph::push(int v1)
{
    stack[++top] = v1;
}
int graph::pop()
{
    return stack[top--];
}
int main()
{
    int ch;
    graph gr;
    cout << "***Welcome to graph assignment***" << endl;
    do
    {
        cout << "\n1.Create " << endl;
        cout << "2.Display " << endl;
        cout << "3.BFS Traversal " << endl;
        cout << "4.DFS Traversal " << endl;
        cout << "5.Exit " << endl;
        cout << "Enter your choice " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            gr.create();
            break;
        case 2:
            gr.display();
            break;
        case 3:
            gr.bfs();
            break;
        case 4:
            gr.dfs();
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "Enter a valid choice " << endl;
            break;
        }
    } while (ch != 5);
}