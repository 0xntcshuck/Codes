#include<iostream>
using namespace std;
int main()
{
    int n, i, j, start;
    int graph[20][20];
    int visited[20] = {0};
    int queue[20], front = 0, rear = 0;
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
    queue[rear++] = start;
    visited[start] = 1;
    cout << "BFS Traversal: ";
    while(front < rear)
    {
        int node = queue[front++];
        cout << node << " ";
        for(i=0;i<n;i++)
        {
            if(graph[node][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
