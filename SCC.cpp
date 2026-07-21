#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> graph[20], transpose[20];
int visited[20];
stack<int> st;

void dfs1(int node)
{
    visited[node] = 1;

    for(int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];

        if(visited[next] == 0)
        {
            dfs1(next);
        }
    }

    st.push(node);
}

void dfs2(int node)
{
    visited[node] = 1;

    cout << node << " ";

    for(int i = 0; i < transpose[node].size(); i++)
    {
        int next = transpose[node][i];

        if(visited[next] == 0)
        {
            dfs2(next);
        }
    }
}

int main()
{
    int n, e;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        transpose[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs1(i);
        }
    }

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    cout << "Strongly Connected Components:\n";

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(visited[node] == 0)
        {
            dfs2(node);
            cout << endl;
        }
    }

    return 0;
}