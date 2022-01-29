#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <string> //for getline to take input string

#define sz size()
using namespace std;
using ls= string;
using ld=double;

void print(string input,string output){
    if(input.size()==0){
        cout<<output<<endl;
    }
    for(int i=0;i<input.length();i++){
        char ch=input[i];
        string left=input.substr(0,i);
        string right=input.substr(i+1);
        string complete=left +right;
        print(complete,output+ch);
    }

}

void printPermutations(string input){
    string output="";
    print(input,output);

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}