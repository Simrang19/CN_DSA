#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
// #define int long long int
#define sz size()
using namespace std;
using ls= string;
using ld=double;


using namespace std;




int count(int n){
    if (n/10==0){
        return 1;
    }
    if(n == 0){
        return 1;
    }
    int smallAns = count(n / 10);
    int ans=smallAns+1;
    return ans;
}
int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
    return 0;
}