#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> BFS(int **edges, int n, int start, int end, bool *visited)
{
    queue<int> pendingNodes;
    unordered_map<int, int> map;

    vector<int> path; // path = start to end

    pendingNodes.push(start);
    visited[start] = true;
    while (pendingNodes.size())
    {
        int front = pendingNodes.front();
        if (front == end)
        {
            // map[end] = front;
            path.push_back(end);
            break;
        }
        pendingNodes.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[front][i] == 1 && visited[i] == false)
            {
                pendingNodes.push(i);
                visited[i] = true;
                map[i] = front;
            }
        }
    }

    if (path.size() > 0)
    {
        while(path[path.size()-1] != start){
            int lastInserted = path[path.size()-1];
            int whocalledLastInserted = map[lastInserted];
            path.push_back(whocalledLastInserted);
        }
    }
    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }

    bool visited[n] = {false};
    int start , end ;
    cin >> start >> end;
    vector<int> ans = BFS(edges,  n , start, end , visited);
    for(int i = 0 ; i  < ans.size() ; i++){
        cout << ans[i] << " ";
    }

}