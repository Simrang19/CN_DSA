#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

// int maximumProfit(int budget[], int n) {
//     int temp=0;
//     int min=0;
//     for(int i=0;i<n;i++){
//         temp=budget[i];
//         int ans=0;
//         for(int j=0;j<n;j++){
//             if(budget[j]>=temp){
//                 ans+=1;
//             }
//             else{
//                 continue;
//             }
//         }
//         if(ans*budget[i]>min){
//             min=ans*budget[i];
//         }
        

//     }
//     return min;
//     // Write your code here

// }

int maximumProfit(int budget[], int n) {
    sort(budget,budget+n);
    int output[10000];
    for(int i=0;i<n;i++){
        output[i]=budget[i]*(n-i);

    }
    int max=0;
    for(int i=0;i<n;i++){
        if(output[i]>max){
            max=output[i];
        }
        else{
            continue;
        }

    }
    return max;
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
