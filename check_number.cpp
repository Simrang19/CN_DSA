#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
// #define int long long int
#define sz size()
using namespace std;
using ls= string;
using ld=double;
bool checkNumber(int input[], int size, int x) {
    if (size>=0){
        if (input[size]==x){
            return true;
        }
        else{
            bool sm=checkNumber(input,size-1,x);
        }
    }
    else
        return false;
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

}



int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}