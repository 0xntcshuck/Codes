#include<iostream>
using namespace std;

int parent[20];

int find(int x)
{
    while(parent[x] != x)
    {
        x = parent[x];
    }
    return x;
}

int main()
{
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    int u[20], v[20], w[20];

    cout << "Enter source destination weight:\n";

    for(int i = 0; i < e; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    // Sort edges by weight
    for(int i = 0; i < e - 1; i++)
    {
        for(int j = i + 1; j < e; j++)
        {
            if(w[i] > w[j])
            {
                swap(w[i], w[j]);
                swap(u[i], u[j]);
                swap(v[i], v[j]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int cost = 0;

    cout << "Edges of MST:\n";

    for(int i = 0; i < e; i++)
    {
        int a = find(u[i]);
        int b = find(v[i]);

        if(a != b)
        {
            cout << u[i] << " - " << v[i] << " = " << w[i] << endl;

            cost += w[i];

            parent[a] = b;
        }
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}