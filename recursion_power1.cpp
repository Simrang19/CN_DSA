#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
// #define int long long int
#define sz size()
using namespace std;
using ls= string;
using ld=double;


int power(int x, int n) {
    if (n==0){
        return 1;
    }
    if (n==1){
        return x;
    }
    int smallOutput=power(x,n-1);
    int output=x*smallOutput;
    return output;
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

}
int main(){
    int x, n;
    cin >> x >> n;
  
    cout << power(x, n) << endl;
    return 0;
}