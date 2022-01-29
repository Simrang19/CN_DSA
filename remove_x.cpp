#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

void myfun(char input[],int size,int start){
    if (input[start]=='\0'){
        return;
    }

    
    myfun(input,size,start+1);
    if (input[start]=='x'){
            int l=strlen(input);
            // input[l-1]='\0';
            for (int i=start;i<l-1;i++){
                input[i]=input[i+1];
            }
            input[l-1]='\0';
        }
        else{
            return;
        }
}

void removeX(char input[]) {
    int size=strlen(input);
    myfun(input,size,0);
    // Write your code here

}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
