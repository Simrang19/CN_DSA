#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;


bool myfun(int n){
    if (n==0){
        return 1;
    }
    bool smallans=myfun(n/10);

}

int main(){
    int n;
    cin>>n;
    bool ans=myfun(n);
    cout<<ans;
}

// int fun1(int n){
//     static int o=5;
    
//     if (o>=4){
//         cout<<o;}
    
//     o--;

// }
// int main(){
//     fun1(5);
//     fun1(7);
//     fun1(6);

// }