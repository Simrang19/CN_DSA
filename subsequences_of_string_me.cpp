#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

int subse(string s,string output[]){
    if (s.empty()){
        output[0]="";
        return 1;
    }
    string smallstring=s.substr(1);
    int smallsize=subse(smallstring,output);
    for (int i=0;i<smallsize;i++){
        output[smallsize+i]=s[0]+output[i];
    }
    return 2*smallsize;
}


int main(){
    string s;
    cin>>s;
    string* output = new string[1000];
    int count=subse(s,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
}