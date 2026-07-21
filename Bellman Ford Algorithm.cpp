#include<iostream>
using namespace std;

int main()
{
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    int u[100], v[100], w[100];

    cout << "Enter source destination weight:\n";
    for(int i = 0; i < e; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    int dist[100];

    for(int i = 0; i < n; i++)
    {
        dist[i] = 9999;
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dist[source] = 0;

    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 0; j < e; j++)
        {
            if(dist[u[j]] != 9999 && dist[u[j]] + w[j] < dist[v[j]])
            {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    cout << "Shortest distances:\n";

    for(int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    return 0;
}