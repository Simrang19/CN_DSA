#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int countZeros(int n) {

    if (n==0){
        return 1;
    }
    if(n<10){
        return 0;
    }
    if (n%10==0){
        return 1 +countZeros(n/10);
    }
    else{
        return countZeros(n/10);
    }
    
    // else if(n/10==0){
    //     return 1;
    // }
    // int sm=countZeros(n/10);
    // if (n%10==0){
    //     return sm+1;
    // }
    // else{
    //     return sm;
    // }
    
    // int ans=sm+1;
    // return ans;
    // Write your code here


}



int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
