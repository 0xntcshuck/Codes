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

            if (graph[i][j] == 0 && i != j)
            {
                graph[i][j] = 9999;
            }
        }
    }

    int dist[20], visited[20] = {0};

    int source;

    cout << "Enter source node: ";
    cin >> source;

    for (int i = 0; i < n; i++)
    {
        dist[i] = graph[source][i];
    }

    visited[source] = 1;

    dist[source] = 0;

    for (int count = 1; count < n; count++)
    {
        int min = 9999;
        int nextNode;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && min + graph[nextNode][i] < dist[i])
            {
                dist[i] = min + graph[nextNode][i];
            }
        }
    }

    cout << "Shortest distances:\n";

    for (int i = 0; i < n; i++)
    {
        cout << source << " -> " << i << " = " << dist[i] << endl;
    }

    return 0;
}