#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
// #define int long long int
#define sz size()
using namespace std;
using ls= string;
using ld=double;
// void print(int n){
//     if(n == 1){
//         cout<< 1<<" ";
//     }
//     int smallOutput=print(n-1);
//     int output=smallOutput+1;
//     cout<<output<<" ";
// }
void print(int n){
    if(n == 1){
        cout << 1 << " ";
        return;
    }
    
    print(n - 1);
    cout << n << " ";
}
int main(){
    int n;
    cin >> n;
  
    print(n);
}