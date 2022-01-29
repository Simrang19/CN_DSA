#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int multiplyNumbers(int m, int n) {
    if (n==0){
        return 0;
    }
    int sm=multiplyNumbers(m,n-1);
    int ans=m+sm;
    return ans;
    // Write your code here

}


int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
