#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int sumOfDigits(int n) {
    if (n==0){
        return 0;
    }
    int sm=sumOfDigits(n/10);
    int ans=sm+n%10;
    return ans;
    // Write your code here

}
int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
