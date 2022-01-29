#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;


// int arr(char input[],int right,int left){
    
// }


    
#include<string.h>
bool checkPalindrome(char input[]) {
    // Write your code here
    static int i=0;
    int S=strlen(input);
    if(i>=S)
        return 1;
    if(input[i]!=input[S-i-1])
    {
        
        return 0;
    }
    else
    {
         
        i++;
        checkPalindrome(input);

     }
}


int main() {
    char input[50];
    cin >> input;
    int right=strlen(input)-1;
    int left=0;
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}