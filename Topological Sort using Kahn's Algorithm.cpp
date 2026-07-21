#include <iostream>
using namespace std;

int main()
{
    int n;
    int graph[20][20];

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int indegree[20] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    int queue[20], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    cout << "Topological Sort: ";

    while (front < rear)
    {
        int node = queue[front++];

        cout << node << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1)
            {
                indegree[i]--;

                if (indegree[i] == 0)
                {
                    queue[rear++] = i;
                }
            }
        }
    }

    return 0;
}