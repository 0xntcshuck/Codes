#include<iostream>
using namespace std;
int graph[20][20], visited[20], n;
void dfs(int node)
{
    cout << node << " ";
    visited[node] = 1;
    for(int i=0;i<n;i++)
    {
        if(graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}
int main()
{
    int i, j, start;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter adjacency matrix:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << "Enter starting node: ";
    cin >> start;
    cout << "DFS Traversal: ";
    dfs(start);
    return 0;
}