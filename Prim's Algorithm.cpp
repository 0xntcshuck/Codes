#include<iostream>
using namespace std;

int main()
{
    int n;
    int graph[20][20];
    int visited[20] = {0};

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if(graph[i][j] == 0)
            {
                graph[i][j] = 9999;
            }
        }
    }

    visited[0] = 1;

    int edge = 0;
    int cost = 0;

    cout << "Edges of MST:\n";

    while(edge < n - 1)
    {
        int min = 9999;
        int a, b;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 1)
            {
                for(int j = 0; j < n; j++)
                {
                    if(visited[j] == 0 && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        cout << a << " - " << b << " = " << min << endl;

        cost += min;

        visited[b] = 1;

        edge++;
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}