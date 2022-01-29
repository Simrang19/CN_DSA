#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
// #define int long long int
#define sz size()
using namespace std;
using ls= string;
using ld=double;
int sum(int input[], int n) {
    if (n==0){
        return 0;
    }
    if (n==1){
        return input[0];
    }
    int smallans=sum(input +1,n-1);
    int ans=smallans+input[0];
    return ans;
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
    
    cout << sum(input, n) << endl;
}



