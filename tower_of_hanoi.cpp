#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==1){
        cout<<source<<" "<<destination<<endl;
        return;
    }
    if (n==0){
        return;
    }
    towerOfHanoi(n-1,source,destination,auxiliary);
    cout<<source<<" "<<destination<<endl;
    towerOfHanoi(n-1,auxiliary,source,destination);
    // Write your code here

}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
