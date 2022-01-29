#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source;
    int dest;
    int weight;
};

bool compareWeight(Edge e1, Edge e2) { 
    return e1.weight < e2.weight; //increasing order
}

int findParent(int v,int *parent){
    if(parent[v]==v){
        return v;
    }
    return findParent(parent[v],parent);
}

int main() {
    int n;
    int e;
    cin>>n>>e;
    Edge input[e];
    Edge output[n-1];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
        
    }
    sort(input,input+e,compareWeight);
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count!= n-1)
    {
        
        Edge nEdge;
        nEdge=input[i];
        int s=nEdge.source;
        int d=nEdge.dest;
        int p1,p2;
        p1=parent[s];
        p2=parent[d];
        while(p1!=parent[p1]){
            p1=parent[p1];
        }
        while(p2!=parent[p2]){
            p2=parent[p2];
        }
        if(p1!=p2){
            output[count]=input[i];
            count++;
            parent[p1]=p2;
        }
        i++;
        
    }
    for(int i=0;i<n-1;i++){
        Edge e=output[i];
        int small=min(e.dest,e.source);
        int big=max(e.dest,e.source);
        cout<<small<<" "<<big<<" "<<e.weight<<endl;
    }
    // Write your code here
}