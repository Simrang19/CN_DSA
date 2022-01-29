#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string
#include <array>
#define sz size()
using namespace std;
using ls= string;
using ld=double;

void myfun(int input[],int size,int output[],int m){
    if(size==0){
        for(int i=0;i < m;i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    int newoutput[10000];
    // int k= sizeof(output)/sizeof(output[0]);
    // int k= *(&output + 1) - output;
    for(int i=0;i<(m);i++){
        newoutput[i]=output[i];
    }
    newoutput[m]=input[0];
    myfun(input+1,size-1,newoutput,m+1);
    myfun(input+1,size-1,output,m);
}

void printSubsetsOfArray(int input[], int size) {
    int m=0;
    int output[1000];
    myfun(input,size,output,m);
    return;
    
	// Write your code here
    
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}