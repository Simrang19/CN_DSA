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
        // if (input[0]==input[1]){
        //     for(int i=0;i<2;i++){
        //         input[]
        //     }
        // }
        return;
        
        // else{
        //     return;
        // }

    }
    myfun(input,size,start+1);
    // else{
    //     myfun(input+1,size-1);
    // }
    if(input[start]==input[start+1]){
        int l=strlen(input);
        input[l+1]='\0';
        for (int i=l-1;i>=start+1;i--){
            input[i+1]=input[i];
        }
        input[start+1]='*';
    }

    
}

void pairStar(char input[]) {
    int size = strlen(input);
    myfun(input,size,0);
    return;
    // Write your code here

}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
