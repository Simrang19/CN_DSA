#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

void replaceCharacter(char input[], char c1, char c2) {
    if(input[0]=='\0'){
        return;
    }
    replaceCharacter(input+1,c1,c2);
    if(input[0]==c1){
        input[0]=c2;
        return;
    }
    else{
        // replaceCharacter(input+1,c1,c2);
        return;
    }

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output. 
     * Change in the given input string itself.
     * Taking input and printing output is handled automatically.
     */
    
}

int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    replaceCharacter(input, c1, c2);
    cout << input << endl;
}