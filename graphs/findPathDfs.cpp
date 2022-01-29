#include <iostream>
#include <vector>
using namespace std;

vector<int> findpath(int** edges,int n,int v1,int v2,bool* visited){
    vector<int> v;
    visited[v1]=true;
    if(v1==v2){
        v.push_back(v1);
        visited[v1]=true;
        return v;
    }
    
    for(int i=0;i<n;i++){
        if(v1 == i){
            continue;
        }
        if((edges[v1][i]==1 and !visited[i])){
            visited[i]=true;
            vector<int> v=findpath(edges,n,i,v2,visited);
            if(v.size() >0 ){
                v.push_back(v1);
                 
                return v;
            }
        }
        
    }
    return v;

}

int main() {
    int n;
    int e;
    cin>>n>>e;
    int** edges=new int*[n];
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
    int v1;
    int v2;
    cin>>v1>>v2;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    vector<int> ans ;
    ans=findpath(edges,n,v1,v2,visited);
    for(int i=0;i < ans.size();i++){
        if(ans.size()>0){
            cout<<ans[i]<<" ";
        }
        else{
            return 0;
        }
        
    }
    // Write your code here
}

// vector<int>* hasPathDFS(bool** edges, int n, int startVertex, int endVertex, bool* visited){
//     vector<int>* ans = new vector<int>;
//     visited[startVertex] = true;
//     if(startVertex == endVertex){
//         visited[startVertex] = true;
//         ans->push_back(startVertex);
//         return ans;
//     }
    
//     for(int i=0; i<n; i++){
//         if(startVertex == i){
//             continue;
//         }
//         else if(edges[startVertex][i] && !visited[i]){
//             visited[i] = true;
//             vector<int>* ans = hasPathDFS(edges, n, i, endVertex, visited);
            
//             if(!ans->empty()){
//                 ans->push_back(startVertex);
//                 return ans;
//             }
//         }
//     }
//     return ans;
// }

// int main() {
//     // Write your code here
//     int n;
//     int e;
//     cin >> n >> e;
//     bool** edges = new bool*[n];
    
//     for(int i=0; i<n; i++){
//         edges[i] = new bool[n];
//         for(int j=0; j<n; j++){
//             edges[i][j] = 0;
//         }
//     }
    
//     for(int i=0; i<e; i++){
//         int a, b;
//         cin >> a >> b;
//         edges[a][b] = true;
//         edges[b][a] = true;
//     }
    
//     int sV, eV;
//     cin >> sV >> eV;
   
//     bool* visited = new bool[n];
    
//     for(int i=0; i<n; i++){
//         visited[i] = false;
//     }
    
//     vector<int>* ans = hasPathDFS(edges, n, sV, eV, visited);
    
//     for(int i=0; i<ans->size(); i++){
//         cout << (*ans)[i] << " ";
//     }
    
//     for(int i=0; i<n; i++){
//         delete[] edges[i];
//     }
    
//     delete[] edges;
//     delete[] visited;
// }