#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int staircase(int n){
    if(n==0 || n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }

    int x=staircase(n-1);
    int y=staircase(n-2);
    int z=staircase(n-3);
    return x+y+z;
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
