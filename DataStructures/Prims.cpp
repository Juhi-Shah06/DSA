#include <iostream>
using namespace std;
class prims
{
public:
    int costMatrix[20][20];
    int n, e; // n is number of vertices and e is edges
    int v1, v2;
    int edgecost, min;
    int row, col;
    int minCost = 0;
    void create();
    void display();
    int visit[20];
    void primsMST();
    prims()
    {
        n = e = 0;

        for (int i = 1; i <= 10; i++) // i is number of rows
        {
            for (int j = 1; j <= 10; j++) // j is number of columns
            {
                costMatrix[i][j] = -1;
            }
        }
        for (int i = 1; i <= 10; i++)
            visit[i] = 0;
    }
};
void prims::create()
{
    cout << "Enter the number of vertices " << endl;
    cin >> n;
    cout << "Enter the number of edges " << endl;
    cin >> e;
    for (int i = 1; i <= e; i++)
    {
        cout << "Enter an edge (vertex v1 and v2) " << endl;
        cin >> v1 >> v2;
        cout << "Enter cost " << endl;
        cin >> edgecost;
        costMatrix[v1][v2] = edgecost;
        costMatrix[v2][v1] = edgecost;
    }
}
void prims::display()
{
    cout << "The adjacency matrix is : " << endl;
    for (int i = 1; i <= n; i++) // rows
    {
        cout << "\n";
        for (int j = 1; j <= n; j++) // columns
        {
            cout << " " << costMatrix[i][j];
        }
    }
}
void prims::primsMST() /*3 conditions : 1) neighbour 2)unvisited 3)nearest */
// edge will be identified after the i loop

{
    for (int i = 1; i <= n; i++)
        visit[i] = 0;
    cout << "Enter starting vertex " << endl;
    cin >> v1;
    visit[v1] = 1;
    for (int k = 1; k <= n - 1; k++)
    {
        min = 999;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (visit[i] == 1 && visit[j] == 0)
                {
                    if (costMatrix[i][j] != -1 && min >= costMatrix[i][j])
                    {
                        min = costMatrix[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        minCost = minCost + min;
        visit[col] = 1;
        costMatrix[row][col] = -1;
        costMatrix[col][row] = -1;
    }
    cout << "The minimum cost is " << minCost << endl;
}
int main()
{
    int ch;
    prims p;
    cout << "***Welcome to prims assignment***" << endl;
    do
    {
        cout << "\n1.Create " << endl;
        cout << "2.Display " << endl;
        cout << "3.Prims method " << endl;
        cout << "4.Exit " << endl;
        cout << "Enter your choice " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            p.create();
            break;
        case 2:
            p.display();
            break;
        case 3:
            p.primsMST();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Enter a valid choice " << endl;
            break;
        }
    } while (ch != 4);
}