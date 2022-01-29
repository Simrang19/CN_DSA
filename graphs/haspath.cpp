#include <iostream>
using namespace std;

bool path(int** edges, int n, int sv,int ev, bool* visited){
    if(sv==ev){
        return true;
    }
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            if(path(edges, n, i,ev, visited)){
                return true;
            }
        }
    }
    return false;
}



int main() {
    int n;
    int e;
    cin >> n >> e;

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
    int si;
    int ei;
    cin>>si>>ei;

    bool* visited = new bool[n];

    for(int i=0; i<n; i++){
        visited[i]=false;
    }

    if(!path(edges,n,si, ei, visited)){
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    // Delete all the memory
    
    // Write your code here
}