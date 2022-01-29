#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

double geometricSum(int k) {
    if (k==0){
        return 1;
    }
    double sm=geometricSum(k-1);
    double ans=1+(sm)/2;
    return ans;
    // Write your code here

}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
