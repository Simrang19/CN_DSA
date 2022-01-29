#include <iostream>
#include <queue>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited){

    queue<int> q;
    q.push(sv);

    visited[sv] = true;
    while(!q.empty()){
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();

        for(int i=0; i<n; i++){
            if(i==curr){
                continue;
            }
            if(edges[curr][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }


}

void print_disconnectedBFS(int **edges,int n)
{
    bool *visited = new bool[n]; 
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

int main() {
    int n;
    int e;
    cin >> n >> e;
    if(n==0){
        return 0;
    }
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i]=new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }

    for(int i=0; i<e; i++){
        int f,s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    print_disconnectedBFS(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges [i];
    }
    delete [] edges;




    // Delete all the memory
    return 0;
}